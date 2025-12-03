package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
	"sync"

	"github.com/gorilla/websocket"
)

type LobbyListener struct {
	Logger *log.Logger
	JWTKey string
	Config struct {
		Port string
	}
}

func (lbs *LobbyListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	log.Println("Lobby Served.")

	/* TODO
	Realize WebSocket Connection and return data and access for connection.
	set auth check and access rights setup
	*/

}

// test.
const MaxPlayers = 8

type Player struct {
	ID   int    `json:"id"`
	Name string `json:"name"`
}

type GameUpdate struct {
	Message string   `json:"message"`
	Players []Player `json:"players"`
}

var (
	upgrader = websocket.Upgrader{
		CheckOrigin: func(r *http.Request) bool { return true }, // test only
	}
	clients   = make(map[*websocket.Conn]*Player)
	clientsMu sync.Mutex
	nextID    = 1
)

func Broadcast(update GameUpdate) {
	clientsMu.Lock()
	defer clientsMu.Unlock()

	data, err := json.Marshal(update)
	if err != nil {
		log.Printf("JSON MARSHAL ERR: %s", err)
		return
	}

	for conn := range clients {
		if err := conn.WriteMessage(websocket.TextMessage, data); err != nil {
			log.Printf("writeMessage error: %s", err)
			conn.Close()
			delete(clients, conn)
		}
	}
}

func handleWebSocket(w http.ResponseWriter, r *http.Request) {
	clientsMu.Lock()
	if len(clients) >= MaxPlayers {
		clientsMu.Unlock()
		http.Error(w, "Server full", http.StatusForbidden)
		return
	}
	clientsMu.Unlock()

	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println("Upgrade error:", err)
		return
	}

	clientsMu.Lock()
	player := &Player{ID: nextID, Name: "Player" + strconv.Itoa(nextID)}
	nextID++
	clients[conn] = player
	clientsMu.Unlock()

	log.Println("New player connected:", player.ID)

	Broadcast(GameUpdate{
		Message: player.Name + " joined the game!",
		Players: getPlayersList(),
	})

	defer func() {
		clientsMu.Lock()
		delete(clients, conn)
		clientsMu.Unlock()
		Broadcast(GameUpdate{
			Message: player.Name + " left the game...",
			Players: getPlayersList(),
		})
		conn.Close()
		log.Println("Player disconnected:", player.ID)
	}()

	// 🔹 Важно! Цикл чтения держит соединение живым
	for {
		_, msg, err := conn.ReadMessage()
		if err != nil {
			log.Println("ReadMessage error:", err)
			break
		}
		log.Printf("Received from %s: %s", player.Name, string(msg))
		Broadcast(GameUpdate{
			Message: fmt.Sprintf("%s says: %s", player.Name, string(msg)),
			Players: getPlayersList(),
		})
	}
}

func getPlayersList() []Player {
	clientsMu.Lock()
	defer clientsMu.Unlock()

	list := make([]Player, 0, len(clients))

	for _, p := range clients {
		list = append(list, *p)
	}
	return list
}

func main() {
	// WebSocket сервер
	http.HandleFunc("/ws", handleWebSocket)
	log.Println("WebSocket server started on :8089")

	// HTTP сервер для теста HTML (локальный)
	go func() {
		log.Println("HTTP server started on :9000")
		err := http.ListenAndServe(":9000", http.FileServer(http.Dir(".")))
		if err != nil {
			log.Fatal("HTTP server error:", err)
		}
	}()

	// Старт основного WebSocket сервера (блокирует текущую горутину)
	log.Fatal(http.ListenAndServe(":8089", nil))
}
