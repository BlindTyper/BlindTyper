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
		UserHander(path_parts[1:], req, wrt, ctx)

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
		/*
			TODO
			System Adjustments to user's access rights. Lobby Owner prerogative.
		*/
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
				/* TODO */
				Profile := edit_profile.ProfileObject{
					Nickname:  "Test",
					Email:     "Test@mail.ru",
					Password:  "test",
					ImagePath: "img...",
				}
				/*
					Object Function.
					Fill the object from the Request before using.
				*/
				Profile.ChangeEmailRequest(req, wrt)
				log.Println("Email changed")
			case "password":
				/* TODO */
				Profile := edit_profile.ProfileObject{
					Nickname:  "Test",
					Email:     "Test@mail.ru",
					Password:  "test",
					ImagePath: "img...",
				}
				/*
					Object Function.
					Fill the object from the Request before using.
				*/
				Profile.ChangePasswordRequest(req, wrt)
				log.Println("Email changed")
			case "nickname":
				/* TODO */
				Profile := edit_profile.ProfileObject{
					Nickname:  "Test",
					Email:     "Test@mail.ru",
					Password:  "test",
					ImagePath: "img...",
				}
				/*
					Object Function.
					Fill the object from the Request before using.
				*/
				Profile.ChangeNicknameRequest(req, wrt)
				log.Println("Email changed")
			case "image":
				/* TODO */
				Profile := edit_profile.ProfileObject{
					Nickname:  "Test",
					Email:     "Test@mail.ru",
					Password:  "test",
					ImagePath: "img...",
				}
				/*
					Object Function.
					Fill the object from the Request before using.
				*/
				Profile.ChangeImageRequest(req, wrt)
				log.Println("Email changed")
			default:
				log.Println("Unknown Parameter to edit.")
			}
		} else {
			log.Println("Edit request without id")
		}
	default:
		log.Println("Unknown Request")
	}
}
