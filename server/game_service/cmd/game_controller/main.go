package main

import (
	"game_service/internal/listener"
	"log"
)

func main() {
	log.Println("game_controller started.")

	/*
		TODO
		start grpc client
		- data
		- sec

		wrap into middleware -> grpc reqs to db
	*/

	// start security_grpc client

	listener.ConnHandler()
}
