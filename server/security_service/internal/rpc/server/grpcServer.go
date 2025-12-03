package grpcserver

import (
	"context"
	"log"
	"net"
	authpb "security_service/internal/rpc/generated"

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

func (s *AuthServer) IsAuth(ctx context.Context, req *authpb.IsAuthRequest) (*authpb.IsAuthResponse, error) {
	Profile := &jwtvalidator.ProfileObject{
		JWT:      req.GetJWT(),
		Username: req.GetUsername(),
	}

	status, error := Profile.SendIsAuthRequest()
	if error != nil {
		return nil, error
	}

	return &authpb.IsAuthResponse{Status: status}, nil
}
