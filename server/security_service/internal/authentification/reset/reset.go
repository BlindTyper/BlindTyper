package reset

import (
	"io"
	"log"
	"net/http"
	"security_service/internal/validator"
)

func ResetHandler(wrt http.ResponseWriter, req *http.Request) {
	validator.ValidateResetFormat(wrt, req)

	_, err := io.ReadAll(req.Body)
	if err != nil {
		http.Error(wrt, "cannot read body", http.StatusBadRequest)
	}
	defer req.Body.Close()

	log.Println("Reset Handler Answer")

	wrt.Header().Set("Content-Type", "application/json")
	wrt.WriteHeader(http.StatusOK)
	wrt.Write([]byte(`{status: "ok", "message":"register request received"}`))

}
