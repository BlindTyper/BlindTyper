package jwtgenerator

import (
	"context"
	"log"
	redisclient "security_service/internal/redis/client"
	"time"

	jwt "github.com/golang-jwt/jwt/v5"
	"github.com/google/uuid"
)

/*
New JWT will be given to the source client on base of his username. ( username + secretword in $env)
*/
func GenerateJWT(Username string) (answer string, err error) { // return type is JWT. string?
	/* TODO
	Move secret Word to $ENV
	*/
	ctx := context.Background()
	hmacSampleSecret := []byte("SecretWordExample")

	/*
		Setting up the life-time of the given token.
	*/
	jti := uuid.NewString()
	ttl := 168 * time.Hour

	claims := &jwt.RegisteredClaims{
		ExpiresAt: jwt.NewNumericDate(time.Now().Add(ttl)),
		Issuer:    "Auth-Service",
		Subject:   Username,
		IssuedAt:  jwt.NewNumericDate(time.Now()),
		// JWT ID -> to Redis.
		ID: jti,
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	signedToken, err := token.SignedString(hmacSampleSecret)
	if err != nil {
		return "", err
	}

	log.Println("JWT generated")

	/*
		TODO -> give token to the redis.
	*/

	// --- Redis ---
	// 1. Удаляем старый токен, если есть
	oldJTI, err := redisclient.Rdb.Get(ctx, "active_token:"+Username).Result()
	if err == nil && oldJTI != "" {
		redisclient.Rdb.Del(ctx, "token:"+oldJTI)
	}

	if oldJTI != "" {
		// удаляем старый токен, если он есть
		if err := redisclient.Rdb.Del(ctx, "token:"+oldJTI).Err(); err != nil {
			return "", err
		}
	}

	// 2. Сохраняем новый токен как активный
	err = redisclient.Rdb.Set(ctx, "token:"+jti, "active", ttl).Err()
	if err != nil {
		return "", err
	}

	log.Println("redis set passed")
	// 3. Обновляем активный токен пользователя
	err = redisclient.Rdb.Set(ctx, "active_token:"+Username, jti, ttl).Err()
	if err != nil {
		return "", err
	}

	log.Println("JWT generated and stored in Redis")
	return signedToken, nil
}
