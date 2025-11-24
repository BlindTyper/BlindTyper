package router

import (
	"context"
	"log"
	"net/http"
	"strings"
)

type UserInfo struct {
	JWT string
	UID string
}

func RouteRequest(user UserInfo, ctx context.Context, wrt http.ResponseWriter, req *http.Request) {
	log.Println("Router got Request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/game/")

	switch path {
	case "test":
		log.Println("test func, got:", user)
	default:
		http.NotFound(wrt, req)
	}
}
