package lobbyserver

import (
	"log"
	"net/http"

	"github.com/gorilla/websocket"
)

type WSAuth struct {
	JWT      string `json:"JWT"`
	Username string `json:"Username"`
}

var upgrader = websocket.Upgrader{
	CheckOrigin: func(r *http.Request) bool { return true },
}

func ConnHandler() {
	mux := http.NewServeMux()
	mux.HandleFunc("/ws", wsHandler)

	log.Println("WS listening on :9000")

	if err := http.ListenAndServe("0.0.0.0:9000", mux); err != nil {
		log.Fatalf("WS server failed: %v", err)
	}
}

func wsHandler(w http.ResponseWriter, r *http.Request) {
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println("Upgrade error:", err)
		return
	}
	defer conn.Close()

	// читаем первый JSON-сообщение (JWT + Username)
	var auth WSAuth
	if err := conn.ReadJSON(&auth); err != nil {
		log.Println("Failed to read auth JSON:", err)
		conn.WriteMessage(websocket.CloseMessage,
			websocket.FormatCloseMessage(websocket.ClosePolicyViolation, "auth required"))
		return
	}

	log.Println("First message from client:", auth)

	// TODO: здесь проверка auth через gRPC

	for {
		var msg map[string]interface{}
		if err := conn.ReadJSON(&msg); err != nil {
			log.Println("Read error:", err)
			break
		}
		log.Println("Received:", msg)
		if err := conn.WriteJSON(msg); err != nil {
			log.Println("Write error:", err)
			break
		}
	}
}
