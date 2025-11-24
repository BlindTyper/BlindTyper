package deleterequest

import (
	"database/sql"
	"log"

	"golang.org/x/crypto/bcrypt"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"
)

/*
FORMAT THIS.

	TODO
	*username + `json:`
	*password + `json:`
*/
type ProfileObject struct {
	Username string
	Password string
}

// sql request to delete unique record in profile db with id =  id
func (profile *ProfileObject) DeleteProfile(s *sql.DB) (message string, error error) {
	var storedHash string

	/*
		get hashed password from the database.
		select password from users where login or email := ... -> scan to storedHash. ->
	*/
	err := s.QueryRow(`
		select password from users where username = $1
	`, profile.Username).Scan(&storedHash)
	if err == sql.ErrNoRows {
		return "", status.Errorf(codes.NotFound, "User not found")
	}
	if err != nil {
		return "", status.Errorf(codes.Internal, "Database query failed: %v", err)
	}

	// compare hash and gotten data || double password input for delete affirmation
	err = bcrypt.CompareHashAndPassword([]byte(storedHash), []byte(profile.Password))
	if err != nil {
		return "", status.Errorf(codes.PermissionDenied, "Wrong Credentials") // wrong input from the user
	}

	err = s.QueryRow(`
		delete 1 from users where username = $1 and password = $2 
	`, profile.Username, profile.Password).Scan()
	if err != nil {
		return "", status.Errorf(codes.Internal, "Database Query failed") // internal error.
	}

	log.Printf("Profile with Username %v was deleted.", profile.Username)
	return "Profile " + profile.Username + " was deleted", nil
}

func SendDeleteRequest(Resource *ProfileObject, s *sql.DB) (message string, error error) {
	/*
		TODO middleware; authpb client.
			return authpb.Middleware(Resource.DeleteProfile(s))
	*/

	return Resource.DeleteProfile(s)
}
