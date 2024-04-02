package repository

import (
	"database/sql"
	"strings"
	"problem1/model"
)

func GetFriendLinkList(db *sql.DB, id string) []int {
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
	return friendList
}

func GetUserNameList(db *sql.DB, friendlist []int) []model.User {
	args := make([]interface{}, len(friendlist))
	for i, id := range friendlist {
		args[i] = id
	}
	sqlStr2 := `SELECT * FROM users WHERE id IN (?` + strings.Repeat(",?", len(friendlist)-1) + `)`

	rows, err := db.Query(sqlStr2, args...)
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
	return friendUserList
}