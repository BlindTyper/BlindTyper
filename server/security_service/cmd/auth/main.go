package main

import (
	"log"
	"security_service/internal/listener"
	redisclient "security_service/internal/redis/client"
	"security_service/internal/rpc/client"
	grpcserver "security_service/internal/rpc/server"

	"time"
)

func main() {
	// --- Инициализация Redis ---
	for i := 0; i < 10; i++ {
		err := redisclient.InitRedis()
		if err != nil {
			log.Printf("Waiting for Redis... retry %d: %v", i, err)
			time.Sleep(2 * time.Second)
			continue
		}
		break
	}
	log.Println("Redis initialized")

	// --- gRPC сервер ---
	go grpcserver.RunGRPCserver()

	// --- gRPC клиент к data_service ---
	if err := client.Init("data:50053"); err != nil {
		log.Fatalf("Failed to init gRPC client: %v", err)
	}
	defer client.Get().Close()

	log.Println("auth_service started")
	listener.ConnHandler()
}
