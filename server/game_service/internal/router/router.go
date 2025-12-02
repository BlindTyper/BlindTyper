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

func RouteRequest(ctx context.Context, wrt http.ResponseWriter, req *http.Request) {
	log.Println("Router got Request. . .")

	path := strings.TrimPrefix(req.URL.Path, "/game/")
	path_parts := strings.Split(strings.TrimPrefix(path, "/"), "/")

	switch path_parts[0] {
	case "online":
		log.Println("online-request...")
		/*
		 chat
		 lobby
		 result
		*/

	case "user":
		UserHander(path_parts[1:], req, wrt, ctx)

	default:
		log.Printf("path: %s", path)
		http.NotFound(wrt, req)
	}
}

func UserHander(parts []string, req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	if len(parts) == 0 {
		http.NotFound(wrt, req)
		return
	}

	switch parts[0] {
	case "system":
		/*
			TODO
			System Adjustments to user's access rights. Lobby Owner prerogative.
		*/
		log.Println("System Request -> edit Handler")

	case "edit":
		editFuncs := map[string]func(*http.Request, http.ResponseWriter){
			"email": func(r *http.Request, w http.ResponseWriter) {
				edit_profile.ChangeEmail(r, w, ctx)
			},
			"password": func(r *http.Request, w http.ResponseWriter) {
				edit_profile.ChangePassword(r, w, ctx)
			},
			"nickname": func(r *http.Request, w http.ResponseWriter) {
				edit_profile.ChangeNickname(r, w, ctx)
			},
			"image": func(r *http.Request, w http.ResponseWriter) {
				edit_profile.ChangeImage(r, w, ctx)
			},
		}

		if len(parts) < 2 {
			http.Error(wrt, "no edit parameters specified.", http.StatusBadRequest)
			return
		}

		command_type := parts[1]
		if f, ok := editFuncs[command_type]; ok {
			auth := true
			/*
				TODO
				auth check

				gRPC call to Auth service
			*/
			if !auth {
				http.Error(wrt, "Non Auth", http.StatusUnauthorized)
			}
			f(req, wrt)
		} else {
			log.Println("Unknown Parameter to edit.")
		}
	default:
		log.Println("Unknown Request")
	}
}
