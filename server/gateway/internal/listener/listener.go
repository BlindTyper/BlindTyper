/*
Package listener provides new connections to the gateway
*/
package listener

import (
	"gateway/internal/router"
	"log"
	"net/http"
)

/*
ConnHandler . . .
*/
func ConnHandler() {
	port := ":8080"
	log.Println("Gateway listening on", port)
	listener := &GatewayListener{}
	http.ListenAndServe("0.0.0.0"+port, listener)
}

/*
GatewayListener is struct for ServeHTTP which provides http.Handler realization
struct provides every needed info about connection
*/
type GatewayListener struct {
	Logger *log.Logger
	JWTKey string // add JWT verification
	Config struct {
		Port string // add routing
	}
}

/*
ConnRecognize separates request on parts for parallel processing and giving it to the corresponding service/worker
Gateway Handler implementation:
*/
func (gtw *GatewayListener) ServeHTTP(wrt http.ResponseWriter, req *http.Request) {

	router.RouteRequest(gtw.Logger, req.Context(), req, wrt)

}
