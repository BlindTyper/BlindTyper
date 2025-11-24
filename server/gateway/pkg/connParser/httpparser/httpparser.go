package httpparser

import (
	"gateway/internal/listener"
	"log"
	"net/http"
)

func ParseHTTP(req *http.Request, w http.ResponseWriter, ConnData *listener.GatewayListener) {
	log.Println("HTTP parsing in process...")
}
