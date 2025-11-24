// Package listener - listens for connection and the routing data inside of the server
package listener

import (
	"log"
	"net/http"
	"security_service/internal/router"
)

func ConnHandler() {
	port := ":8081" // server port
	listener := &AuthListener{}
	log.Println("Auth Service is listening on", port)
	http.ListenAndServe("0.0.0.0"+port, listener)
}

type AuthListener struct {
	Logger *log.Logger
	JWTKey string
	Config struct {
		Port string
	}
}

func (auth *AuthListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	router.RouteRequest(auth.Logger, req.Context(), req, wrt)
}
