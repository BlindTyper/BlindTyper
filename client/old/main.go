package main

import (
	"bufio"
	"fmt"
	"log"
	"os"

	"github.com/gorilla/websocket"
)

func main() {
	// Адрес WebSocket сервера через nginx
	url := "ws://localhost/api/online/ws"
	log.Println("Connecting to", url)

	conn, _, err := websocket.DefaultDialer.Dial(url, nil)
	if err != nil {
		log.Fatal("Dial error:", err)
	}
	defer conn.Close()
	log.Println("Connected!")
	/*
		сбор приветственного сообщения с данными авторизации.
	*/
	auth := map[string]string{
		"JWT":      "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJBdXRoLVNlcnZpY2UiLCJzdWIiOiJBbGV4ZXkiLCJleHAiOjE3NjU0MTM4MTEsImlhdCI6MTc2NDgwOTAxMSwianRpIjoiODQwNmNhMDItOGI2YS00NDY3LWJjMWMtZjdiN2QwYzJiYTFjIn0.yaoIs1sRUBvLQvNkZhVC3GocJJSE-Qdfpc1--GD8RkU",
		"Username": "Alexey",
	}
	conn.WriteJSON(auth)

	/*
		отдельный поток для обработки полученных от севрера ответов в рамках одного соединения.
	*/
	go func() {
		for {
			var msg map[string]interface{}
			if err := conn.ReadJSON(&msg); err != nil {
				log.Println("Read error:", err)
				break
			}
			fmt.Println("Received:", msg)
		}
	}()

	/*
		Проверка обмена сообщениями между сервером и клиентом.
	*/
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("Enter message: ")
		if !scanner.Scan() {
			break
		}
		text := scanner.Text()

		err := conn.WriteJSON(map[string]string{
			"message": text,
		})
		if err != nil {
			log.Println("Write error:", err)
			break
		}
	}
}
