package router

import (
	"context"
	"log"
	"net/http"
	"strings"
)

var action_routes = map[string]string{
	"test": "route", // middleware
}

func RouteRequest(user, JWT string, ctx context.Context, wrt http.ResponseWriter, req *http.Request) {
	log.Println("Router got Request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/game/")

	switch path {
	case "/test":
		log.Printf("path: %s", path)
		log.Println("test func, got:", user)
	default:
		log.Printf("path: %s", path)
		http.NotFound(wrt, req)
	}
}

/*
RouteRequest through the middleare
*/

/*
	RouteRequest REST, no access rules.
*/
