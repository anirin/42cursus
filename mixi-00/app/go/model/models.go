package model

type User struct {
	ID	 int
	UserID int
	Name string
}

type FriendLink struct {
	ID int
	User1ID int
	User2ID int
}

type BlockList struct {
	ID int
	User1ID int
	User2ID int
}