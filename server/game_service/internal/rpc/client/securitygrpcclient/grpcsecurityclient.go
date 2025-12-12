package grpcsecurityclient

import (
	"context"
	"fmt"
	"log"
	"time"

	authpb "game_service/internal/rpc/generated/authpb"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

type AuthServiceClient struct {
	client authpb.AuthServiceClient
	conn   *grpc.ClientConn
}

var GlobalAuthClient *AuthServiceClient

func Init(authServiceUrl string) error {
	conn, err := grpc.NewClient(
		authServiceUrl,
		grpc.WithTransportCredentials(insecure.NewCredentials()),
	)
	if err != nil {
		return fmt.Errorf("failed to connect to auth service: %v", err)
	}

	GlobalAuthClient = &AuthServiceClient{
		client: authpb.NewAuthServiceClient(conn),
		conn:   conn,
	}

	log.Printf("Connected to auth service at: %s", authServiceUrl)
	return nil
}

func Get() *AuthServiceClient {
	if GlobalAuthClient == nil {
		log.Fatal("AuthServiceClient not inited.")
	}
	return GlobalAuthClient
}

func (d *AuthServiceClient) Close() {
	if d.conn != nil {
		_ = d.conn.Close()
		log.Println("Auth service connection closed")
	}
}

// isauth
func (auth *AuthServiceClient) IsAuth(ctx context.Context, JWT, username string) (bool, error) {
	// Добавляем таймаут к контексту
	ctx, cancel := context.WithTimeout(ctx, 10*time.Second)
	defer cancel()

	// Создаем gRPC запрос
	req := &authpb.IsAuthRequest{
		JWT:      JWT,
		Username: username,
	}

	// Вызываем gRPC метод
	resp, err := auth.client.IsAuth(ctx, req)
	if err != nil {
		return false, fmt.Errorf("gRPC DataLogin failed: %v", err)
	}

	log.Printf("Auth IsAuth response for user %s: %v", username, resp.Status)
	return resp.Status, nil
}
