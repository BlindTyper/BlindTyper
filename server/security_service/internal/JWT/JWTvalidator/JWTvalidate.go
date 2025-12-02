package jwtvalidator

import (
	"fmt"
	"log"

	"github.com/golang-jwt/jwt/v5"
)

type ProfileObject struct {
	JWT      string ``
	Username string ``
}

func ValidateJWT(profile ProfileObject) (bool, error) {

	token, err := jwt.Parse(profile.JWT, func(t *jwt.Token) (interface{}, error) {
		if _, ok := t.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("invalid token") // invalid signing method
		}
		// TODO
		// Move the Secret Word to $ENV
		return []byte("SecretWordExample" + profile.Username), nil
	})

	if err != nil {
		return false, err
	}

	return token.Valid, nil
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
