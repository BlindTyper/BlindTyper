/*
Package provides Create, Update, Delete actions for authorized user.
*/
package edit_profile

import (
	"log"
	"net/http"
)

type ProfileObject struct {
	Nickname  string
	Email     string
	Password  string
	ImagePath string
}

/*
TODO
gRPC request to the data_service
*/

func ChangeImage(profile *ProfileObject) (bool, error) {
	log.Println("Image Changed")
	return true, nil
}
func (profile *ProfileObject) ChangeImageRequest(req *http.Request, wrt http.ResponseWriter) (bool, error) {
	return ChangeImage(profile)
}

func ChangePassword(profile *ProfileObject) (bool, error) {
	log.Println("Image Changed")
	return true, nil
}
func (profile *ProfileObject) ChangePasswordRequest(req *http.Request, wrt http.ResponseWriter) (bool, error) {
	return ChangePassword(profile)
}

func ChangeEmail(profile *ProfileObject) (bool, error) {
	log.Println("Image Changed")
	return true, nil
}
func (profile *ProfileObject) ChangeEmailRequest(req *http.Request, wrt http.ResponseWriter) (bool, error) {
	return ChangeEmail(profile)
}

func ChangeNickname(profile *ProfileObject) (bool, error) {
	log.Println("Image Changed")
	return true, nil
}
func (profile *ProfileObject) ChangeNicknameRequest(req *http.Request, wrt http.ResponseWriter) (bool, error) {
	return ChangeNickname(profile)
}
