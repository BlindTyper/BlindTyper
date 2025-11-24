package main

import (
	"log"
	"security_service/internal/listener"
	"security_service/internal/rpc/client"
	grpcserver "security_service/internal/rpc/server"
)

func main() {
	go grpcserver.RunGRPCserver()

	// start grpc client to data_service.
	if err := client.Init("data:50053"); err != nil {
		log.Fatalf("Failed to init gRPC client: %v", err)
	}
	/* TODO
	make restart connection function.
	*/
	defer client.Get().Close()

	log.Println("auth_service started")
	listener.ConnHandler()
}
