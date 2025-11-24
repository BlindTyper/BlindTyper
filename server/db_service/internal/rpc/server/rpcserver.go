package grpcserver

import (
	"context"
	"database/sql"
	loginRequest "db_service/internal/databaseInteraction/authProvider/loginRequest"
	registerRequest "db_service/internal/databaseInteraction/authProvider/registerRequest"
	editRequest "db_service/internal/databaseInteraction/profileProvider/editRequest"
	datapb "db_service/internal/rpc/generated"
	"log"
	"net"

	"google.golang.org/grpc"
)

type DataServer struct {
	datapb.UnimplementedDataServiceServer
	DB *sql.DB
}

// запуск grpc сервера для других сервисов
func RunGRPCserver(db *sql.DB) {
	lis, err := net.Listen("tcp", ":50053")
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}

	grpcServer := grpc.NewServer()
	dataServer := &DataServer{DB: db}
	datapb.RegisterDataServiceServer(grpcServer, dataServer) // ← здесь создаём экземпляр своей структуры

	log.Println("gRPC data server listening on :50053")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}

// сопоставление данных в БД
func (s *DataServer) RpcDataLogin(ctx context.Context, req *datapb.DataLoginRequest) (*datapb.DataLoginResponse, error) {
	Profile := &loginRequest.ProfileObject{
		Username: req.GetUsername(),
		Email:    req.GetEmail(),
		Password: req.GetPassword(),
	}

	success, error := loginRequest.SendLoginRequest(Profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataLoginResponse{Success: success}, nil
}

// создание новой записи и валидация корректности ввода.
func (s *DataServer) RpcDataRegister(ctx context.Context, req *datapb.DataRegisterRequest) (*datapb.DataRegisterResponse, error) {
	Profile := &registerRequest.ProfileObject{
		Username:       req.GetUsername(),
		Password:       req.GetPassword(),
		PasswordRepeat: req.GetPasswordRepeat(),
		Email:          req.GetEmail(),
	}

	message, error := registerRequest.SendRegisterRequest(Profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataRegisterResponse{Message: message}, nil
}

// удаление профиля по ID
func (s *DataServer) RpcDataProfileDelete(ctx context.Context, req *datapb.DataProfileDeleteRequest) (*datapb.DataProfileDeleteResponse, error) {
	success := true

	return &datapb.DataProfileDeleteResponse{Success: success}, nil
}

// изменение пароля
func (s *DataServer) RpcDataProfilePasswordUpdate(ctx context.Context, req *datapb.DataProfilePasswordUpdateRequest) (*datapb.DataProfilePasswordUpdateResponse, error) {
	profile := new(editRequest.ProfileObject)
	{
		req.GetPassword()
		req.GetPasswordRepeat()
	}

	success, error := editRequest.SendEditProfilePasswordRequest(profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataProfilePasswordUpdateResponse{Success: success}, nil
}

// изменение имени
func (s *DataServer) RpcDataProfileNameUpdate(ctx context.Context, req *datapb.DataProfileNameUpdateRequest) (*datapb.DataProfileNameUpdateResponse, error) {
	profile := new(editRequest.ProfileObject)
	{
		req.GetUsername()
	}

	success, error := editRequest.SendEditProfileNameRequest(profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataProfileNameUpdateResponse{Success: success}, nil
}

// изменение картинки профиля
func (s *DataServer) RpcDataProfileImageUpdate(ctx context.Context, req *datapb.DataProfileImageUpdateRequest) (*datapb.DataProfileImageUpdateResponse, error) {
	profile := new(editRequest.ProfileObject)
	{
		req.GetImage()
	}

	success, error := editRequest.SendEditProfileImageRequest(profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataProfileImageUpdateResponse{Success: success}, nil
}

// изменение почты
func (s *DataServer) RpcDataProfileEmailUpdate(ctx context.Context, req *datapb.DataProfileEmailUpdateRequest) (*datapb.DataProfileEmailUpdateResponse, error) {
	profile := new(editRequest.ProfileObject)
	{
		req.GetEmail()
	}

	success, error := editRequest.SendEditProfileEmailRequest(profile, s.DB)
	if error != nil {
		return nil, error
	}

	return &datapb.DataProfileEmailUpdateResponse{Success: success}, nil
}
