package handler

import (
	"problem1/service"

	"github.com/labstack/echo/v4"
)

func Rooting(e *echo.Echo) {
	//ルーティング
	e.GET("/", service.Hello)
	e.GET("/get_friend_list", service.GetFriendList)
	e.GET("/get_friend_of_friend_list", service.GetFriendOfFriendList)
	e.GET("/get_friend_of_friend_list_paging", service.GetFriendOfFriendListPaging)
}