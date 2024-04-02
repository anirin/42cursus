package repository

import (
	"database/sql"
	"fmt"
	"net/http"
	model "problem1/model"
	"problem1/configs"

	"github.com/labstack/echo/v4"
)

func Hello(c echo.Context) error {
	return c.String(http.StatusOK, "minimal_sns_app")
}

func Test(c echo.Context) error {
	conf := configs.Get()
	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	userID := 1
	const sqlStr = `SELECT * FROM friend_link WHERE user1_id = ?`
	rows, err := db.Query(sqlStr, userID)
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

	fmt.Println(friendList)

	return c.String(http.StatusOK, "test")
}

func GetFriendList(c echo.Context) error {
	// userIdの取得
	id := c.QueryParam("ID")

	conf := configs.Get()
	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	// userIdを元に友達リストを取得
	userID := id
	const sqlStr = `SELECT * FROM friend_link WHERE user1_id = ?`
	rows, err := db.Query(sqlStr, userID)
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

	// userIDを元に名前を取得
	userIDs := friendList
	const sqlStr2 = `SELECT * FROM user WHERE user_id IN (?)`
	rows, err = db.Query(sqlStr2, userIDs)
	if err != nil {
			panic(err)
	}
	friendUserList := []model.User{}
	for rows.Next() {
		user := model.User{}
		err = rows.Scan(&user.ID, &user.UserID, &user.Name)
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