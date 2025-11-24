package lobby_provider

import (
	"game_service/internal/online_provider/lobby/lobby_listener"
	"log"
	"net/http"
)

func ServeLobby(req http.Request, wrt http.ResponseWriter) {
	log.Println("Lobby Served.")
	port := ":8083"
	lls := &lobby_listener.LobbyListener{}

	http.ListenAndServe("0.0.0.0"+port, lls)
}
