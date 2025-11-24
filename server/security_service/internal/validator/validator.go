package validator

import (
	"log"
	"net/http"
	//"golang.org/x/tools/go/analysis/passes/unmarshal"
)

/*
	check auth
	check register format
	check source correctness
*/

func ValidateRegisterFormat() {
	log.Println("Pending validation")

	// unmarshal() - tool for unwrap JSON

	/*
		??? maybe check that inside of the client? or double check
		for false-sources prediction

		! check of data format
	*/
}

func ValidateResetFormat(wrt http.ResponseWriter, req *http.Request) {
	log.Println("Pending validation")
	// idk
}

func IsAuth(wrt http.ResponseWriter, req *http.Request) {
	log.Println("IsAuth processing")

	// checking header & JWT
	result := true

	if result {
		log.Println("Access Granted")
		wrt.WriteHeader(http.StatusOK)
		return
	}

	log.Println("Not Authed")
	wrt.WriteHeader(http.StatusUnauthorized)
}
