package router

import (
	"context"
	"game_service/internal/users_provider/user/edit_profile"
	"log"
	"net/http"
	"strings"
)

// var action_routes = map[string]string{
// 	"test": "route", // middleware
// }

func RouteRequest(user, JWT string, ctx context.Context, wrt http.ResponseWriter, req *http.Request) {
	log.Println("Router got Request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/game/")
	path_parts := strings.Split(strings.TrimPrefix(path, "/"), "/")
	log.Println(path_parts[0])
	switch path_parts[0] {
	case "online":
		log.Println("online-request...")
		/*
		 chat
		 lobby
		 result
		*/
	case "user":
		/*
			TODO
			decode JSON and get required method
		*/
		UserHander(path_parts[1:], req, wrt)

		log.Println("User Handler")
	default:
		log.Printf("path: %s", path)
		http.NotFound(wrt, req)
	}
}

func UserHander(parts []string, req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	log.Println("User Handler, decompose path.")

	if len(parts) == 0 {
		log.Println("User: Empty Route.")
		return
	}

	switch parts[0] {
	case "system":
		log.Println("System Request -> edit Handler")
	case "edit":
		if len(parts) > 1 {
			command_type := parts[1]
			/*
				switch: type edit profile command.
				also part...
			*/
			switch command_type {
			case "email":
				edit_profile.ChangeEmail(req, wrt, ctx)
			case "password":
			case "nickname":
			case "image":
			default:
				log.Println("Unknown Parameter to edit.")
			}
		} else {
			log.Println("Edit request without id")
		}

		log.Println("Edit request -> edit Handler")
	default:
		log.Println("Unknown Request")
	}
}
