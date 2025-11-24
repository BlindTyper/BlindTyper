package router

import (
	"context"
	"log"
	"net/http"
	"strings"
)

func RouteRequest(Logger *log.Logger, ctx context.Context,
	req *http.Request, wrt http.ResponseWriter) {
	/*
		comments
	*/
	log.Println("Router got request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/data/")

	switch path {
	case "/loginCheck":
		log.Println("login check in process. . .")
	default:
		http.NotFound(wrt, req)
	}

}
