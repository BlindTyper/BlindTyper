package jwtvalidator

import (
	"context"
	"errors"
	"fmt"
	"log"
	redisclient "security_service/internal/redis/client"

	"github.com/golang-jwt/jwt/v5"
)

type ProfileObject struct {
	JWT      string ``
	Username string ``
}

// Устанавливаем токен как активный в Redis с TTL
func ValidateJTI(jti string) (bool, error) {
	ctx := context.Background()
	key := "token:" + jti

	// Получаем значение
	val, err := redisclient.Rdb.Get(ctx, key).Result()
	if err != nil {
		return false, err // ошибка Redis
	}

	log.Printf("val: status = %s", val)

	if val != "active" {
		return false, nil // токен не активен
	}

	return true, nil
}

func ValidateJWT(profile ProfileObject) (bool, error) {

	token, err := jwt.Parse(profile.JWT, func(t *jwt.Token) (interface{}, error) {
		if _, ok := t.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("invalid token") // invalid signing method
		}
		// TODO
		// Move the Secret Word to $ENV
		return []byte("SecretWordExample"), nil
	})

	if err != nil {
		return false, err
	}

	// Проверяем JTI в Redis
	claims, ok := token.Claims.(jwt.MapClaims)
	if !ok || claims["jti"] == nil {
		return false, fmt.Errorf("jti claim missing")
	}

	log.Println(claims)

	UsernameRaw, ok := claims["sub"]
	if !ok || UsernameRaw == nil {
		return false, errors.New("username not present in JWT")
	}
	UsernameRaw, ok = UsernameRaw.(string)
	if !ok {
		return false, errors.New("username is not a string")
	}

	if claims["sub"].(string) != profile.Username {
		return false, fmt.Errorf("username mismatch")
	}
	jti := claims["jti"].(string)
	valid, err := ValidateJTI(jti)
	if err != nil || !valid {
		return false, err
	}

	return token.Valid, nil
}

func IsAuth(profile ProfileObject) (bool, error) {
	log.Println("User if Authed.")
	/*
		TODO
		Check JWT, then check auth status in system. if already authed -> remove previous token from the memory.
	*/

	return true, nil
}
func (profile ProfileObject) SendIsAuthRequest() (bool, error) {
	_, err := ValidateJWT(profile)
	if err != nil {
		return false, err
	}

	return IsAuth(profile)
}
