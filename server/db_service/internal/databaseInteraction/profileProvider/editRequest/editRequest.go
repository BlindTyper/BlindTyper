package editrequest

import "database/sql"

type ProfileObject struct {
	/* TODO
	add `json:` descriptions to every row.
	*/
	Name            string
	Img             string
	Password        string
	Password_repeat string
	email           string
}

func SendEditProfilePasswordRequest(resource *ProfileObject, s *sql.DB) (status bool, error error) {
	return resource.ChangePassword(s)
}
func SendEditProfileNameRequest(resource *ProfileObject, s *sql.DB) (status bool, error error) {
	return resource.ChangeName(s)
}
func SendEditProfileImageRequest(resource *ProfileObject, s *sql.DB) (status bool, error error) {
	return resource.ChangeImage(s)
}
func SendEditProfileEmailRequest(resource *ProfileObject, s *sql.DB) (status bool, error error) {
	return resource.ChangeEmail(s)
}

func (profile *ProfileObject) ChangePassword(s *sql.DB) (status bool, error error) {
	// подключение к БД и изменение password
	/*
		TODO
		middleware check for auth. -> nah. middleware should be provided only for the gateway.
		gateway -> profile object -> edit current definition of the object inside of the database
	*/

	return status, error
}

func (profile *ProfileObject) ChangeName(s *sql.DB) (status bool, error error) {
	// подключение к БД и изменение юза
	profile.Name = "newName"

	return status, error
}

func (profile *ProfileObject) ChangeImage(s *sql.DB) (status bool, error error) {
	// подключение к БД и изменение img
	profile.Img = "new img path"

	return status, error
}

func (profile *ProfileObject) ChangeEmail(s *sql.DB) (status bool, error error) {
	// подключение к БД и изменение email
	profile.email = "new email"

	return status, error
}
