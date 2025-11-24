package login

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	jwtgenerator "security_service/internal/JWTgenerator"
	"security_service/internal/rpc/client"
	//"gateway/pkg/connParser/httpparser" remote procedure call to the db_service
)

type LoginRequest struct {
	Username string `json:"Username"`
	Email    string `json:"Email"`
	Password string `json:"Password"`
}

func LoginHandler(wrt http.ResponseWriter, req *http.Request) {
	var body LoginRequest

	if err := json.NewDecoder(req.Body).Decode(&body); err != nil {
		http.Error(wrt, "Invalid JSON", http.StatusBadRequest)
		return
	}
	defer req.Body.Close()

	_, err := io.ReadAll(req.Body)
	if err != nil {
		http.Error(wrt, "cannot read body", http.StatusBadRequest)
		return
	}
	defer req.Body.Close()

	dataClient := client.Get()
	success, err := dataClient.RpcDataLogin(
		context.Background(),
		body.Username,
		body.Email,
		body.Password,
	)
	if err != nil {
		http.Error(wrt, fmt.Sprintf(`{"status": "failed", "message":"%v"}`, err), http.StatusInternalServerError)
		return
	}

	// Give Permission via JWT. (Login + SecretWord = SecretJWTkey for current session)

	JWT, err := jwtgenerator.GenerateJWT(body.Username)
	if err != nil {
		http.Error(wrt, fmt.Sprintf(`{"status": "failed", "message": "%v"}`, err), http.StatusInternalServerError)
		return
	}

	log.Printf("gRPC response: %v", success)
	wrt.Header().Set("Content-Type", "application/json")
	wrt.WriteHeader(http.StatusOK)
	wrt.Write([]byte(fmt.Sprintf(`{status: "ok", "message": "login approved", "JWT": "%v"}`, JWT)))
}
