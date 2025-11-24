package main

import (
	"database/sql"
	"db_service/internal/listener"
	grpcserver "db_service/internal/rpc/server"
	"fmt"
	"log"

	_ "github.com/lib/pq"
)

/*
Data for Postgres connection

	ToDo()

	- move const to $ENV for securing data safety.
*/
const (
	Host     = "postgres"
	Port     = 5432
	User     = "postgres"
	Password = "example"
	Dbname   = "mydb"
)

// Setting up the database connection. via database/sql module.
func DbConnection() (*sql.DB, error) {
	psqlInfo := fmt.Sprintf("host=%s port=%d user=%s password=%s dbname=%s sslmode=disable", Host, Port, User, Password, Dbname)

	db, err := sql.Open("postgres", psqlInfo)
	if err != nil {
		return nil, err
	}
	log.Printf("Connected to %s.", Dbname)
	return db, nil
}

//test
/*
Main Function. Entrypoint for any connection.

	Init DB connection & start internal server for accepting connections from users. (from gateway.)
*/
func main() {
	log.Println("Database service started....")

	db, err := DbConnection()
	if err != nil {
		log.Fatalf("Cannot connect to DB: %v", err)
	}
	defer db.Close()

	go grpcserver.RunGRPCserver(db)
	listener.ConnHandler()
}
