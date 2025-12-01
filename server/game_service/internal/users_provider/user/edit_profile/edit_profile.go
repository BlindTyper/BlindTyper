/*
Package provides Create, Update, Delete actions for authorized user.
*/
package edit_profile

import (
	"context"
	"encoding/base64"
	"fmt"
	"game_service/internal/contextkeys"
	"log"
	"net/http"
	"os"
)

func ChangeImage(req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	// Получаем username и avatarB64 из контекста
	usernameVal := ctx.Value(contextkeys.UserKey)
	avatarVal := ctx.Value(contextkeys.ImgKey)

	if usernameVal == nil || avatarVal == nil {
		http.Error(wrt, "missing username or avatar in context", http.StatusBadRequest)
		return
	}

	username, ok1 := usernameVal.(string)
	avatarB64, ok2 := avatarVal.(string)
	if !ok1 || !ok2 || username == "" || avatarB64 == "" {
		http.Error(wrt, "invalid username or avatar in context", http.StatusBadRequest)
		return
	}

	// Декодируем base64
	imgBytes, err := base64.StdEncoding.DecodeString(avatarB64)
	if err != nil {
		http.Error(wrt, "invalid base64", http.StatusBadRequest)
		return
	}

	// создаём директорию для сохранения
	dstDir := "/var/www/blindtyper/static/avatars"
	if err := os.MkdirAll(dstDir, 0755); err != nil {
		log.Println("Failed to create directory:", err)
		http.Error(wrt, "cannot create directory", http.StatusInternalServerError)
		return
	}
	// Создаем путь для сохранения
	dstPath := fmt.Sprintf("/var/www/blindtyper/static/avatars/%s.png", username)
	dst, err := os.Create(dstPath)
	if err != nil {
		log.Println("Failed to create file:", err)
		http.Error(wrt, "cannot create file", http.StatusInternalServerError)
		return
	}
	defer dst.Close()

	// Пишем в файл
	if _, err := dst.Write(imgBytes); err != nil {
		log.Println("Failed to write file:", err)
		http.Error(wrt, "cannot write file", http.StatusInternalServerError)
		return
	}

	log.Println("Image Changed for user:", username)
	wrt.WriteHeader(http.StatusOK)
	wrt.Write([]byte(`{"success":true}`))
}

func ChangeEmail(req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	// TODO: read JSON, validate, call gRPC to update email in data_service
	usernameVal := ctx.Value(contextkeys.UserKey)
	emailVal := ctx.Value(contextkeys.EmailKey)

	if usernameVal == nil || emailVal == nil {
		http.Error(wrt, "missing username or email in context.", http.StatusBadRequest)
		return
	}
	/* TODO
	gRPC request to dataservice to change email in user table via username key.
	*/
}

func ChangePassword(req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	// TODO
	usernameVal := ctx.Value(contextkeys.UserKey)
	passwordVal := ctx.Value(contextkeys.PasswordKey)

	if usernameVal == nil || passwordVal == nil {
		http.Error(wrt, "missing username or password in context.", http.StatusBadRequest)
		return
	}
}

func ChangeNickname(req *http.Request, wrt http.ResponseWriter, ctx context.Context) {
	// TODO
	usernameVal := ctx.Value(contextkeys.UserKey)
	nicknameVal := ctx.Value(contextkeys.NicknameKey)

	if usernameVal == nil || nicknameVal == nil {
		http.Error(wrt, "missing username or nickname in context.", http.StatusBadRequest)
		return
	}
}
