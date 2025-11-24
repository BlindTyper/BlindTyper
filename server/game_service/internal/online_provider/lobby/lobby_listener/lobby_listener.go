package lobby_listener

import (
	"log"
	"net/http"
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
	// Realize WebSocket Connection and return data and access for connection.
}
