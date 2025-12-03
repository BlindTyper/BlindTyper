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
		OnlineHandler(path_parts[1:], req, wrt, ctx)
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
			// "password": func(r *http.Request, w http.ResponseWriter) {
			// 	edit_profile.ChangePassword(r, w, ctx)
			// },
			// "nickname": func(r *http.Request, w http.ResponseWriter) {
			// 	edit_profile.ChangeNickname(r, w, ctx)
			// },
			// "image": func(r *http.Request, w http.ResponseWriter) {
			// 	edit_profile.ChangeImage(r, w, ctx)
			// },
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

type OnlineGame struct {
}

func OnlineHandler(parts []string, req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	if len(parts) == 0 {
		http.NotFound(wrt, req)
		return
	}

	switch parts[0] {
	case "system":
		// owner || system commands.
	case "user":
		// join || actions like chat or sync progress.
		userFuncs := map[string]func(*http.Request, http.ResponseWriter){
			"create": func(req *http.Request, wrt http.ResponseWriter) {
				log.Println("ONLINE/USER/CREATE ACTION!!")

				// 1. проверка JWT / авторизация
				// 2. генерируем уникальный порт для лобби
				// 3. создаём структуру Lobby, сохраняем в Redis
				// 4. запускаем WS сервер на этом порту
				// 5. возвращаем клиенту JSON {lobbyID, port}
			},
		}

		if len(parts) < 2 {
			http.Error(wrt, "no user action specified", http.StatusBadRequest)
			return
		}

		action := parts[1]
		if f, ok := userFuncs[action]; ok {
			f(req, wrt)
		} else {
			http.Error(wrt, "unknown action", http.StatusBadRequest)
		}
	}
}
