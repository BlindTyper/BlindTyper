package redisclient

import (
	"context"
	"log"
	"os"

	redis "github.com/redis/go-redis/v9"
)

var Rdb *redis.Client
var Ctx = context.Background()

func InitRedis() error {
	addr := os.Getenv("REDIS_ADDR")
	if addr == "" {
		addr = "redis:6379"
	}

	Rdb = redis.NewClient(&redis.Options{
		Addr:     addr,
		Password: "", // если нет
		DB:       0,
	})

	if err := Rdb.Ping(Ctx).Err(); err != nil {
		return err
	}

	log.Println("Redis connected")
	return nil
}
