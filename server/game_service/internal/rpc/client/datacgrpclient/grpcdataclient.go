package grpcdataclient

import (
	"fmt"
	"game_service/internal/rpc/generated/datapb"
	"log"

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
