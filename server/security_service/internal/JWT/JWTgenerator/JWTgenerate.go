package jwtgenerator

import (
	"log"
	"time"

	"github.com/golang-jwt/jwt/v5"
)

/*
New JWT will be given to the source client on base of his username. ( username + secretword in $env)
*/
func GenerateJWT(Username string) (answer string, err error) { // return type is JWT. string?
	// TODO
	// Move secret Word to $ENV
	hmacSampleSecret := []byte("SecretWordExample" + Username)

	/*
		Setting up the life-time of the given token.
	*/
	claims := &jwt.RegisteredClaims{
		ExpiresAt: jwt.NewNumericDate(time.Now().Add(168 * time.Hour)),
		Issuer:    "Auth-Service",
		Subject:   Username,
		IssuedAt:  jwt.NewNumericDate(time.Now()),
		// JWT ID -> to Redis.
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	signedToken, err := token.SignedString(hmacSampleSecret)
	if err != nil {
		return "", err
	}

	log.Println("JWT generated")
	return signedToken, nil
}
