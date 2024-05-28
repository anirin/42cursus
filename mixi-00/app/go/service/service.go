package service

import (
	"database/sql"
	"fmt"
	"net/http"
	"problem1/apperrors"
	"problem1/configs"
	"problem1/repository"

	"github.com/labstack/echo/v4"
)

func Hello(c echo.Context) error {
	return c.String(http.StatusOK, "minimal_sns_app")
}

func GetFriendList(c echo.Context) error {
	conf := configs.Get()
	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		err = apperrors.SqlError.Wrap(err, "failed to open db")
		apperrors.ErrorHandler(c, err)
		return err
	}
	defer db.Close()

	id := c.QueryParam("ID")

	fmt.Println("try")
	friendList, err := repository.GetFriendLinkList(db, id)
	if err != nil {
		apperrors.ErrorHandler(c, err)
		return err
	}	
	friendUserList, err := repository.GetUserNameList(db, friendList)
	if err != nil {
		apperrors.ErrorHandler(c, err)
		return err
	}	

	return c.JSON(http.StatusOK, friendUserList)
}

func GetFriendOfFriendList(c echo.Context) error {
	return nil
}

func GetFriendOfFriendListPaging(c echo.Context) error {
	return nil
}