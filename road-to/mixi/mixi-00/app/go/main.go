package main

import (
	"strconv"
	"problem1/handler"
	"problem1/configs"

	_ "github.com/go-sql-driver/mysql"
	"github.com/labstack/echo/v4"
)


func main() {
	conf := configs.Get()

	e := echo.New()
	handler.Rooting(e)

	e.Logger.Fatal(e.Start(":" + strconv.Itoa(conf.Server.Port)))
}
