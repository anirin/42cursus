package repository

import (
	"database/sql"
	"strings"
	"problem1/model"
	"problem1/apperrors"
)

func GetFriendLinkList(db *sql.DB, id string) ([]int, error) {
	const sqlStr = `SELECT * FROM friend_link WHERE user1_id = ?`
	rows, err := db.Query(sqlStr, id)
	if err != nil {
		err = apperrors.QueryError.Wrap(err, "failed to query friend link")
		return nil, err
	}
	friendList := []int{}
	for rows.Next() {
		frindLink := model.FriendLink{}
		err = rows.Scan(&frindLink.ID, &frindLink.User1ID, &frindLink.User2ID)
		if err != nil {
			err = apperrors.ScanError.Wrap(err, "failed to scan friend link")
			return nil, err
		}
		friendList = append(friendList, frindLink.User2ID)
	}
	return friendList, nil
}

func GetUserNameList(db *sql.DB, friendlist []int) ([]model.User, error) {
	args := make([]interface{}, len(friendlist))
	for i, id := range friendlist {
		args[i] = id
	}
	sqlStr2 := `SELECT * FROM users WHERE id IN (?` + strings.Repeat(",?", len(friendlist)-1) + `)`

	rows, err := db.Query(sqlStr2, args...)
	if err != nil {
		err = apperrors.QueryError.Wrap(err, "failed to query user")
		return nil, err
	}
	friendUserList := []model.User{}
	for rows.Next() {
		user := model.User{}
		err = rows.Scan(&user.ID, &user.UserID, &user.Name)
		if err != nil {
			err = apperrors.ScanError.Wrap(err, "failed to scan user")
			return nil, err
		}
		friendUserList = append(friendUserList, user)
	}
	return friendUserList, nil
}