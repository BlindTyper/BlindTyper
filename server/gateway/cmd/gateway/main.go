package main

import (
	"gateway/internal/listener"
	"log"
)

func main() {
	log.Println("gateway started")

	listener.ConnHandler()

	/*
		TODO
		* wrap connection to the middleware to approve any request inside of the internal programm.
	*/
	/*
		start listening
		if conn -> handle( get type of req)
			-> send to determined service worker.
	*/
}

/*
	internal:
		- listen for connections
		- analyze connections
		- route connections
	global:
		- currently nothing
*/
