package service

import (
	"database/sql"
	"net/http"
	"problem1/configs"
	"problem1/model"
	"strings"

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

	const sqlStr = `SELECT * FROM friend_link WHERE user1_id = ?`
	rows, err := db.Query(sqlStr, id)
	if err != nil {
		panic(err)
	}
	friendList := []int{}
	for rows.Next() {
		frindLink := model.FriendLink{}
		err = rows.Scan(&frindLink.ID, &frindLink.User1ID, &frindLink.User2ID)
		if err != nil {
			panic(err)
		}
		friendList = append(friendList, frindLink.User2ID)
	}

	args := make([]interface{}, len(friendList))
	for i, id := range friendList {
		args[i] = id
	}
	sqlStr2 := `SELECT * FROM users WHERE id IN (?` + strings.Repeat(",?", len(friendList)-1) + `)`

	rows, err = db.Query(sqlStr2, args...)
	if err != nil {
		panic(err)
	}
	friendUserList := []model.User{}
	for rows.Next() {
		user := model.User{}
		err = rows.Scan(&user.ID, &user.UserID ,&user.Name)
		if err != nil {
			panic(err)
		}
		friendUserList = append(friendUserList, user)
	}

	return c.JSON(http.StatusOK, friendUserList)
}

func GetFriendOfFriendList(c echo.Context) error {
	return nil
}

func GetFriendOfFriendListPaging(c echo.Context) error {
	return nil
}