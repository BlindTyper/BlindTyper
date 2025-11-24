package listener

import (
	"db_service/internal/router"
	"log"
	"net/http"
)

func ConnHandler() {
	port := ":8082"
	log.Println("Database listening on", port)
	listener := &DatabaseListener{}
	http.ListenAndServe("0.0.0.0"+port, listener)
}

type DatabaseListener struct {
	Logger   *log.Logger
	AuthInfo struct {
		login    string
		password string
	}
}

func (dtb *DatabaseListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {
	router.RouteRequest(dtb.Logger, req.Context(), req, wrt)
}
