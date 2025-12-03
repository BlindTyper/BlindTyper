package router

import (
	"context"
	"fmt"
	"io"
	"log"
	"net/http"
	"strings"

	"google.golang.org/grpc/status"
)

/*
TODO
this package has to provide middleware check for the approving internal commands. not the other ones.
*/
var routes = map[string]string{
	"/auth/":   "http://auth:8081/",  // no need to middleware
	"/data/":   "http://data:8082/",  // no access. only internal services to reroute.
	"/game/":   "http://game:8083/",  // TODO middleware
	"/admin/":  "http://admin:8084/", // TODO middleware
	"/online/": "http://game:9000/",
}

func RouteRequest(Logger *log.Logger, ctx context.Context,
	req *http.Request, wrt http.ResponseWriter) {

	log.Println("Router got request. . .")

	for prefix, targetBase := range routes {
		if strings.HasPrefix(req.URL.Path, prefix) {
			target := targetBase + strings.TrimPrefix(req.URL.Path, prefix)
			log.Println("proxying to:", target)

			switch prefix {
			case "/admin/":
				/*
					TODO
					local middleware wrap with grpc reqs to the sec_srvc
				*/

				err := ProxyRequest(req, wrt, target)
				if err != nil {
					// http.Error(wrt, err.Error(), 400)
					return
				}
				return
			case "/game/":
				/*
					TODO
					local middleware wrap with grpc reqs to the sec_srvc
				*/
				fmt.Println("router /game/")
				err := ProxyRequest(req, wrt, target)
				if err != nil {
					// http.Error(wrt, err.Error(), 400)
					return
				}
				return

			case "/data/":
				/* refuse connection. only internal calls allowed. */
				http.Error(wrt, "Only internal calls allowed", 400)
				return
			default:
				ProxyRequest(req, wrt, target)
				return
			}
		}
	}

	http.NotFound(wrt, req)
}

func ProxyRequest(r *http.Request, w http.ResponseWriter, target string) (error error) {

	body, err := io.ReadAll(r.Body)
	if err != nil {
		errMsg := err.Error()
		fmt.Println(errMsg)

		return status.Errorf(http.StatusBadRequest, "%s", errMsg)
	}
	defer r.Body.Close()

	req, err := http.NewRequest(r.Method, target, io.NopCloser(strings.NewReader(string(body))))
	if err != nil {
		errMsg := err.Error()
		fmt.Println(errMsg)
		return status.Errorf(http.StatusInternalServerError, "%s", errMsg)
	}

	req.Header = r.Header.Clone()

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		errMsg := err.Error()
		log.Println(errMsg)
		return status.Errorf(http.StatusBadGateway, "%s", errMsg)
	}

	defer resp.Body.Close()

	for k, v := range resp.Header {
		w.Header()[k] = v
	}
	w.WriteHeader(resp.StatusCode)
	io.Copy(w, resp.Body)

	return nil
}
