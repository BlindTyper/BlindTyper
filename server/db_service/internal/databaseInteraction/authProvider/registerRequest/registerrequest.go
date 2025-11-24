package registerrequest

import (
	"database/sql"

	"golang.org/x/crypto/bcrypt"
	"google.golang.org/grpc/status"

	_ "github.com/lib/pq"
)

/*
Structure for Data Transfering between services; Tipization for JSON unwrapping.
*/
type ProfileObject struct {
	Username       string `json:"username"`
	Password       string `json:"password"`
	PasswordRepeat string `json:"password_repeat"`
	Email          string `json:"email"`
}

/*
s parameter - opened in main.go sql connection, which will be used for every transaction.

	Function provides the query to database with the given data from a caller.
*/
func (profile *ProfileObject) RegisterProfile(s *sql.DB) (message string, error error) {
	// email and username processing
	var exists bool

	err := s.QueryRow(`
		Select exists(
			select 1 from users where username = $1 Or email = $2
		)
	`, profile.Username, profile.Email).Scan(&exists)
	if err != nil {
		// internal error while processing
		return "", status.Errorf(500, "%s", err.Error())
	}

	if exists {
		return "", status.Errorf(403, "username or email already taken")
	}

	// password processing
	if profile.Password != profile.PasswordRepeat {
		// invalid password input from the user
		return "", status.Errorf(400, "passwords do not match")
	}

	hashedPassword, err := bcrypt.GenerateFromPassword([]byte(profile.Password), bcrypt.DefaultCost)
	if err != nil {
		// internal error while processing
		return "", status.Errorf(500, "%s", err.Error())
	}

	// inserting into database
	_, err = s.Exec(`
		Insert into users (username, email, password)
		Values ($1, $2, $3)
	`,
		profile.Username, profile.Email, string(hashedPassword))
	if err != nil {
		// internal error while processing
		return "", status.Errorf(500, "%s", err.Error())
	}

	return "registration successful", nil
}

/*
interface between object and foreign functions.
*/
func SendRegisterRequest(Resourse *ProfileObject, s *sql.DB) (message string, error error) {
	return Resourse.RegisterProfile(s)
}
