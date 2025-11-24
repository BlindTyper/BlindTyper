// Package router provides data transfering between modules of the auth-service
package router

import (
	"context"
	"log"
	"net/http"
	"security_service/internal/authentification/login"
	"security_service/internal/authentification/register"
	"strings"
)

/* var routes = map[string]http.HandlerFunc{
    "login":    LoginHandler,
    "register": RegisterHandler,
    "main":     MainHandler,
}

func RouteRequest(Logger *log.Logger, ctx context.Context, req *http.Request, wrt http.ResponseWriter) {
    path := strings.TrimPrefix(req.URL.Path, "/auth/")
    handler, ok := routes[path]
    if !ok {
        http.NotFound(wrt, req)
        return
    }
    handler(wrt, req)
}
*/

func RouteRequest(Logger *log.Logger, ctx context.Context,
	req *http.Request, wrt http.ResponseWriter) {
	/*
		add check for internal project sertificate
	*/
	log.Println("Router got request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/auth/")

	switch path {
	case "/login":
		login.LoginHandler(wrt, req)
	case "/register":
		register.RegisterHandler(wrt, req)
	default:
		/*
			TODO
			maybe change to Invalid Command 403?
		*/
		http.NotFound(wrt, req)
	}
}
