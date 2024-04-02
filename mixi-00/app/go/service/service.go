package service

import (
	"database/sql"
	"net/http"
	"problem1/configs"
	"problem1/repository"
	"fmt"

	"github.com/labstack/echo/v4"
)

func Hello(c echo.Context) error {
	return c.String(http.StatusOK, "minimal_sns_app")
}

func GetFriendList(c echo.Context) error {
	conf := configs.Get()
	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	id := c.QueryParam("ID")

	fmt.Println("try")
	friendList := repository.GetFriendLinkList(db, id)
	friendUserList := repository.GetUserNameList(db, friendList)

	return c.JSON(http.StatusOK, friendUserList)
}

func GetFriendOfFriendList(c echo.Context) error {
	return nil
}

func GetFriendOfFriendListPaging(c echo.Context) error {
	return nil
}