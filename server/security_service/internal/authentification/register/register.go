package register

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"security_service/internal/rpc/client"
	"security_service/internal/validator"
)

type RegisterRequest struct {
	Username       string `json:"Username"`
	Password       string `json:"Password"`
	PasswordRepeat string `json:"Password_repeat"`
	Email          string `json:"Email"`
}

func RegisterHandler(wrt http.ResponseWriter, req *http.Request) {
	validator.ValidateRegisterFormat()

	var body RegisterRequest

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

	log.Println("Gegister Handler Answer")

	dataClient := client.Get()

	success, err := dataClient.RpcDataRegister(
		context.Background(),
		body.Username,
		body.Password,
		body.PasswordRepeat,
		body.Email,
	)
	if err != nil {
		http.Error(wrt, fmt.Sprintf(`{"status":"failed","message":"%v"}`, err), http.StatusInternalServerError)
		return
	}

	log.Printf("gRPC respone: %v", success)
	wrt.Header().Set("Content-Type", "application/json")
	wrt.WriteHeader(http.StatusOK)
	wrt.Write([]byte(`{status: "ok", "message":"register request received"}`))
}
