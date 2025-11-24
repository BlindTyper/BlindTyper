package loginrequest

import (
	"database/sql"

	_ "github.com/lib/pq"
	"golang.org/x/crypto/bcrypt"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"
)

/*
Structure for Data Transfering between services; Tipization for JSON unwrapping.
*/
type ProfileObject struct {
	Username string `json:"Username"`
	Email    string `json:"Email"`
	Password string `json:"Password"`
}

/*
s parameter - opened in main.go sql connection, which will be used for every transaction.

	Function provides the query to database with the given data from a caller.
*/
func (profile *ProfileObject) LoginProfile(s *sql.DB) (bool, error) {
	var storedHash string
	var query string
	var arg string

	// Logic for elimination of necessity of Email&Username in requests.
	switch {
	case profile.Username != "":
		query = "SELECT password FROM users WHERE username = $1"
		arg = profile.Username
	case profile.Email != "":
		query = "SELECT password FROM users WHERE email = $1"
		arg = profile.Email
	default:
		return false, status.Errorf(codes.InvalidArgument, "Username or email must be provided")
	}

	err := s.QueryRow(query, arg).Scan(&storedHash)
	if err == sql.ErrNoRows {
		return false, status.Errorf(codes.NotFound, "User not found")
	}
	if err != nil {
		return false, status.Errorf(codes.Internal, "Database query failed: %v", err)
	}

	err = bcrypt.CompareHashAndPassword([]byte(storedHash), []byte(profile.Password))
	if err != nil {
		return false, status.Errorf(codes.PermissionDenied, "Invalid username/email or password")
	}

	return true, nil
}

/*
interface between object and foreign functions.
*/
func SendLoginRequest(Resourse *ProfileObject, s *sql.DB) (message bool, error error) {
	return Resourse.LoginProfile(s)
}
