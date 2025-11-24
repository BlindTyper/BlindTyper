package jwtvalidator

import (
	"log"
)

type ProfileObject struct {
	JWT      string ``
	Username string ``
}

func ValidateJWT(profile ProfileObject) (bool, error) {
	log.Println("Validated JWT.")
	return true, nil
}
func (profile ProfileObject) SendValidateJWTRequest() (bool, error) {
	/*
		TODO
		Check gotten JWT.
	*/
	return ValidateJWT(profile)
}

func IsAuth(profile ProfileObject) (bool, error) {
	log.Println("User if Authed.")
	/*
		TODO
		Check JWT, then Validate it.
	*/
	return true, nil
}
func (profile ProfileObject) SendIsAuthRequest() (bool, error) {
	return IsAuth(profile)
}
