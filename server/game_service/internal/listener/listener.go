package listener

import (
	"context"
	"encoding/json"
	"fmt"
	"game_service/internal/contextkeys"
	"game_service/internal/router"
	AuthClient "game_service/internal/rpc/client/securitygrpcclient"

	"log"
	"net/http"
)

func ConnHandler() {
	port := ":8083"
	log.Println("Game Service listening on", port)

	listener := &GameServiceListener{}
	http.ListenAndServe("0.0.0.0"+port, listener)
}

type GameServiceListener struct {
	JWT       string `json:"JWT"`       // Access token
	Username  string `json:"Username"`  // Unique ID
	AvatarB64 string `json:"AvatarB64"` // pfp
	Password  string `json:"Password"`  // Password
	Email     string `json:"Email"`     // Email
	Nickname  string `json:"Nickname"`
}

func (listener *GameServiceListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	var body GameServiceListener

	if err := json.NewDecoder(req.Body).Decode(&body); err != nil {
		log.Println("Decode Error")
		http.Error(wrt, "Invalid JSON | game_service/internal/listener", http.StatusBadRequest)
		return
	}
	defer req.Body.Close()

	authClient := AuthClient.Get()
	isAuth, err := authClient.IsAuth(
		context.Background(),
		body.JWT,
		body.Username,
	)
	if err != nil {
		http.Error(wrt, fmt.Sprintf(`{"status": "failed", "message":"%v"}`, err), http.StatusInternalServerError)
		return
	}
	if isAuth {
		ctx := context.WithValue(req.Context(), contextkeys.UserKey, body.Username)
		ctx = context.WithValue(ctx, contextkeys.ImgKey, body.AvatarB64)
		ctx = context.WithValue(ctx, contextkeys.NicknameKey, body.Nickname)
		ctx = context.WithValue(ctx, contextkeys.PasswordKey, body.Password)
		ctx = context.WithValue(ctx, contextkeys.EmailKey, body.Email)

		req = req.WithContext(ctx)

		router.RouteRequest(ctx, wrt, req)
	} else {
		http.Error(wrt, fmt.Sprintln(`{"status": "failed", "message": "Not Authed"}`), http.StatusNetworkAuthenticationRequired)
		return
	}
}
