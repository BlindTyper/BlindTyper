package grpcserver

import (
	"context"
	"log"
	"net"
	authpb "security_service/internal/rpc/generated"
	"security_service/internal/rpc/generated/datapb"

	jwtvalidator "security_service/internal/JWT/JWTvalidator"

	"google.golang.org/grpc"
)

// AuthServer реализует интерфейс AuthServiceServer
type AuthServer struct {
	authpb.UnimplementedAuthServiceServer
}

func RunGRPCserver() {
	lis, err := net.Listen("tcp", ":50052")
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}

	grpcServer := grpc.NewServer()
	authpb.RegisterAuthServiceServer(grpcServer, &AuthServer{}) // ← здесь создаём экземпляр своей структуры

	log.Println("gRPC server listening on :50052")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}

// сопоставление данных в БД
func (s *AuthServer) RpcIsAuth(ctx context.Context, req *authpb.IsAuthRequest) (*authpb.IsAuthResponse, error) {
	Profile := &jwtvalidator.ProfileObject{
		JWT:      req.GetJWT(),
		Username: req.GetUsername(),
	}

	status, error := jwtvalidator.SendLoginRequest(Profile)
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
