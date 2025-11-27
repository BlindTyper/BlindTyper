package router

import (
	"context"
	"log"
	"net/http"
	"strings"
)

func RouteRequest(user, JWT string, ctx context.Context, wrt http.ResponseWriter, req *http.Request) {
	log.Println("Router got Request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/game/")

	switch path {
	case "test":
		log.Println("test func, got:", user)
	default:
		http.NotFound(wrt, req)
	}
}
