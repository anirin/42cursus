package handler

import (
	"problem1/repository"
	"github.com/labstack/echo/v4"
)

func Rooting(e *echo.Echo) {
	//ルーティング
	e.GET("/", repository.Hello)
	e.GET("/test", repository.Test)
	e.GET("/get_friend_list", repository.GetFriendList)
	e.GET("/get_friend_of_friend_list", repository.GetFriendOfFriendList)
	e.GET("/get_friend_of_friend_list_paging", repository.GetFriendOfFriendListPaging)
}