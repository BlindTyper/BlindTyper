package middleware

import (
	"log"
)

/*
TODO
set up the sample for any function for giving same argument and the same answer type as the caller.
IMPORTANT: we can use *any parameter for caller req&answer
TODO
	wrap function to set caller's return type after validation to execute same code.
TODO
	sign every function to http.Handler type for providing aviability to wrap it for the middleware runtime.
*/

// middleware will provide shared functions to check auth
/*
	Scenarios:
		gateway:
			- isAuth?
			- JWTtoken?
		db:
			- isAllowed?
		game:
			- isAccess?
			- JWTtoken?
			toDo()
				- Websockets access?

*/

type UserObject struct {
	JWT string
}

func (User *UserObject) IsAuth() bool {
	log.Printf("MW: Access granted %s", User.JWT)
	return true
}

func (User *UserObject) JWTisValid() bool {
	/* TODO
	decompose JWT to header, payload e.t.c
	*/
	log.Printf("MW: JWT is validated %s", User.JWT)
	/* TODO
	JWT.Validate(JWT) -> JWT module.
	*/
	return true
}

// func (User *UserObject) HaveAccess(Source string) bool {
// 	log.Printf("MW: User Have access to the resource %s", User.UID)
// 	/* TODO
// 	compare DATA.User.Rights and Source.Rights
// 	*/
// 	return true
// }

/* TODO
WebSocket Validation to the client
*/
