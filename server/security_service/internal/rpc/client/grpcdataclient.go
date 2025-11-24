package client

import (
	"context"
	"fmt"
	"log"
	"time"

	datapb "security_service/internal/rpc/generated/datapb"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

type DataServiceClient struct {
	client datapb.DataServiceClient
	conn   *grpc.ClientConn
}

var GlobalDataClient *DataServiceClient

func Init(dataServiceUrl string) error {
	conn, err := grpc.NewClient(
		dataServiceUrl,
		grpc.WithTransportCredentials(insecure.NewCredentials()),
	)
	if err != nil {
		return fmt.Errorf("failed to connect to data service: %v", err)
	}

	GlobalDataClient = &DataServiceClient{
		client: datapb.NewDataServiceClient(conn),
		conn:   conn,
	}

	log.Printf("Connected to data service at: %s", dataServiceUrl)
	return nil
}

func Get() *DataServiceClient {
	if GlobalDataClient == nil {
		log.Fatal("DataServiceClient not inited.")
	}
	return GlobalDataClient
}

func (d *DataServiceClient) Close() {
	if d.conn != nil {
		_ = d.conn.Close()
		log.Println("Data service connection closed")
	}
}

// RpcDataLogin - проверка логина и пароля в базе данных
func (d *DataServiceClient) RpcDataLogin(ctx context.Context, username, email, password string) (bool, error) {
	// Добавляем таймаут к контексту
	ctx, cancel := context.WithTimeout(ctx, 10*time.Second)
	defer cancel()

	// Создаем gRPC запрос
	req := &datapb.DataLoginRequest{
		Username: username,
		Email:    email,
		Password: password,
	}

	// Вызываем gRPC метод
	resp, err := d.client.RpcDataLogin(ctx, req)
	if err != nil {
		return false, fmt.Errorf("gRPC DataLogin failed: %v", err)
	}

	log.Printf("DataLogin response for user %s: %v", username, resp.Success)
	return resp.Success, nil
}

// RpcDataRegister - регистрация нового пользователя в базе данных
func (d *DataServiceClient) RpcDataRegister(ctx context.Context, username, password, passwordRepeat, email string) (string, error) {
	// Добавляем таймаут к контексту
	ctx, cancel := context.WithTimeout(ctx, 10*time.Second)
	defer cancel()

	// Создаем gRPC запрос
	req := &datapb.DataRegisterRequest{
		Username:       username,
		Password:       password,
		PasswordRepeat: passwordRepeat,
		Email:          email,
	}

	// Вызываем gRPC метод
	resp, err := d.client.RpcDataRegister(ctx, req)
	if err != nil {
		return "", fmt.Errorf("gRPC DataRegister failed: %v", err)
	}

	log.Printf("DataRegister response for user %s: %s", username, resp.Message)
	return resp.Message, nil
}
