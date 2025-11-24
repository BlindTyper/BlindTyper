package listener

import (
	"game_service/internal/router"
	"log"
	"net/http"
)

func ConnHandler() {
	port := ":8083"
	log.Println("Game Service listening on", port)
	/* TODO
	Wrap listener into the middleware HandlerFunc
	*/

	listener := &GameServiceListener{}
	http.ListenAndServe("0.0.0.0"+port, listener)
}

type GameServiceListener struct {
	Logger   log.Logger
	UserInfo struct {
		JWT string // Access token
		UID string // Unique ID
	}
}

func (listener *GameServiceListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	router.RouteRequest(listener.UserInfo, req.Context(), wrt, req)
}
