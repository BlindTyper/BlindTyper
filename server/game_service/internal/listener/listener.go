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
}

func (listener *GameServiceListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	/* TODO
	Wrap listener into the middleware HandlerFunc
	*/

	var body GameServiceListener

	if err := json.NewDecoder(req.Body).Decode(&body); err != nil {
		log.Println("Decode Error")
		http.Error(wrt, "Invalid JSON", http.StatusBadRequest)
		return
	}
	defer req.Body.Close()

	authClient := AuthClient.Get()
	success, err := authClient.IsAuth(
		context.Background(),
		body.JWT,
		body.Username,
	)
	if err != nil {
		http.Error(wrt, fmt.Sprintf(`{"status": "failed", "message":"%v"}`, err), http.StatusInternalServerError)
		return
	}
	if success {
		ctx := context.WithValue(req.Context(), contextkeys.UserKey, body.Username)
		ctx = context.WithValue(ctx, contextkeys.ImgKey, body.AvatarB64)
		req = req.WithContext(ctx)

		log.Printf("heh. %s", ctx)
		router.RouteRequest(ctx, wrt, req)
	} else {
		http.Error(wrt, fmt.Sprintln(`{"status": "failed", "message": "Not Authed"}`), http.StatusNetworkAuthenticationRequired)
		return
	}
}
