package main

import (
	"game_service/internal/listener"
	lobbyserver "game_service/internal/online_provider/lobby/lobby_provider/lobby_server"
	grpcsecurityclient "game_service/internal/rpc/client/securitygrpcclient"
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
	// start grpc client to data_service.
	if err := grpcsecurityclient.Init("auth:50052"); err != nil {
		log.Fatalf("Failed to init gRPC client: %v", err)
	}
	defer grpcsecurityclient.Get().Close()
	/* TODO
	make restart connection function.
	*/

	go lobbyserver.ConnHandler()
	listener.ConnHandler()
}
