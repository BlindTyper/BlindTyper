package lobbyserver

import (
	"context"
	"encoding/json"
	"fmt"
	AuthClient "game_service/internal/rpc/client/securitygrpcclient"
	"log"
	"net/http"

	"github.com/gorilla/websocket"
)

type GameServiceListener struct {
	JWT       string `json:"JWT"`      // Access token
	Username  string `json:"Username"` // Unique ID
	Parameter struct {
		Cmd1 string `json:"cmd1"`
		Cmd2 string `json:"cmd2"`
		Cmd3 string `json:"cmd3"`
	} `json:"parameter"`
}

func WSServerInit() {
	mux := http.NewServeMux()
	listener := &GameServiceListener{}
	mux.Handle("/ws", listener) // wsHandler апгрейдит соединение
	log.Println("WebSocket server listening on :9000")
	http.ListenAndServe("0.0.0.0:9000", mux)
}

var upgrader = websocket.Upgrader{
	CheckOrigin: func(r *http.Request) bool { return true }, // разрешаем все источники для теста
}

func (listener *GameServiceListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	var body GameServiceListener

	if err := json.NewDecoder(req.Body).Decode(&body); err != nil {
		log.Println("Decode Error")
		http.Error(wrt, "Invalid JSON | game_service/internal/online_provider/lobby/listener"+err.Error(), http.StatusBadRequest)
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
	if !isAuth {
		http.Error(wrt, "Unauthorized", http.StatusUnauthorized)
		return
	}

	conn, err := upgrader.Upgrade(wrt, req, nil)
	if err != nil {
		log.Println("WS Upgrade error:", err)
		return
	}
	defer conn.Close()

	for {
		var msg map[string]interface{}
		if err := conn.ReadJSON(&msg); err != nil {
			log.Println("read error, ", err)
			break
		}
		log.Println("received:", msg)

		if err := conn.WriteJSON(msg); err != nil {
			log.Println("Write error: ", err)
			break
		}
	}
}
