package main

import (
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
	"github.com/labstack/echo/v4"
	"net/http"
	"problem1/configs"
	"strconv"
	"fmt"
	"sort"
)

type Friend_link struct {
	Id			int
	User1_id	int
	User2_id	int
}

func printIntSlice(slice []int) {
	fmt.Printf("%v\n", slice)
	for _, test := range slice {
		fmt.Printf("%d\n", test);
	}
}

func removeDuplicatesAndBlockFriends(slice []int, blockFriends []int) []int{
	userIdMap := make(map[int]bool)
	var newSlice []int

	for _, id := range blockFriends {
		userIdMap[id] = true
	}
	for _, id := range slice {
		if userIdMap[id] == false {
			userIdMap[id] = true
			newSlice = append(newSlice, id)
		}
	}
	return newSlice
}

func removeMySelf(friends []int, mySelfId int) []int {
	var newSlice []int

	for _, val := range friends {
		if mySelfId != val {
			newSlice = append(newSlice, val)
		}
	}
	return newSlice
}

func getOneHopFriend(db *sql.DB, userId int) ([] int, error) {
	var friends [] int
	var u Friend_link

	rows, err := db.Query("SELECT * FROM friend_link WHERE user1_id = ?", userId)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	for rows.Next() {
		if err := rows.Scan(&u.Id, &u.User1_id, &u.User2_id); err != nil {
			return nil, err;
		}
		friends = append(friends, u.User2_id);
	}
	return friends, nil
} 

func getOneHopFriendUser2(db *sql.DB, userId int) ([] int, error) {
	var friends [] int
	var u Friend_link

	rows, err := db.Query("SELECT * FROM friend_link WHERE user2_id = ?", userId)
	if err != nil {
		return nil, err;
	}
	defer rows.Close()
	for rows.Next() {
		if err := rows.Scan(&u.Id, &u.User1_id, &u.User2_id); err != nil {
			return nil, err;
		}
		friends = append(friends, u.User1_id);
	}
	return friends, nil
} 

func getTwoHopFriend(db *sql.DB, userId int) ([] int, error) {
	var twoHopFriends []int

	oneHopFriends, err := getOneHopFriend(db, userId)
	if err != nil {
		return nil, err;
	}
	for _, val := range oneHopFriends {
		appendTwoHopFriend, err := getOneHopFriend(db, val)
		if err == nil {
			twoHopFriends = append(twoHopFriends, appendTwoHopFriend...)
		}
		appendTwoHopFriend, err = getOneHopFriendUser2(db, val)
		if err == nil {
			twoHopFriends = append(twoHopFriends, appendTwoHopFriend...)
		}
	}
	blockFriends, err := getBlockFriends(db, userId)
	twoHopFriends = removeDuplicatesAndBlockFriends(twoHopFriends, blockFriends)
	twoHopFriends = removeMySelf(twoHopFriends, userId)
	sort.Ints(twoHopFriends)
	return twoHopFriends, nil
}

func getBlockFriend(db *sql.DB, userId int) ([]int, error) {
	var blockFriend []int
	var u Friend_link

	rows, err := db.Query("SELECT * FROM block_list WHERE user1_id = ?", userId)
	if err != nil {
		return nil, err
	}
	for rows.Next() {
		if err := rows.Scan(&u.Id, &u.User1_id, &u.User2_id); err != nil {
			return nil, err;
		}
		blockFriend = append(blockFriend, u.User2_id);
	}
	return blockFriend, nil
}

func getBlockFriendUserId2(db *sql.DB, userId int) ([]int, error) {
	var blockFriend []int
	var u Friend_link

	rows, err := db.Query("SELECT * FROM block_list WHERE user2_id = ?", userId)
	if err != nil {
		return nil, err
	}
	for rows.Next() {
		if err := rows.Scan(&u.Id, &u.User1_id, &u.User2_id); err != nil {
			return nil, err;
		}
		blockFriend = append(blockFriend, u.User1_id);
	}
	return blockFriend, nil
}

func getBlockFriends(db *sql.DB, userId int) ([]int, error) {
	var blockFriends []int
	var tmpFriends []int

	tmpFriends, err := getBlockFriend(db, userId)
	if err != nil {
		return nil, err
	}
	blockFriends = append(blockFriends, tmpFriends...)
	tmpFriends, err = getBlockFriendUserId2(db, userId)
	if err != nil {
		return nil, err
	}
	blockFriends = append(blockFriends, tmpFriends...)
	return blockFriends, nil
}

func getPageLimitFriends(friends []int, limit int, page int) []int {
	var pageLimitFriends []int

	if limit < 1 || page < 1 {
		return nil
	}
	for i, val := range friends {
		if (i >= limit * (page - 1) && i < limit * page) {
			pageLimitFriends = append(pageLimitFriends, val)
		}
	}
	return pageLimitFriends
}

func main() {
	conf := configs.Get()

	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	e := echo.New()

	e.GET("/", func(c echo.Context) error {
		return c.String(http.StatusOK, "minimal_sns_app")
	})

	e.GET("/get_friend_list", func(c echo.Context) error {
		var friends [] int

		userIdStr := c.QueryParam("id")
		userId, err := strconv.Atoi(userIdStr)
		if err != nil {
			return c.String(http.StatusBadRequest, "Invalid id")
		}
		friends, err = getOneHopFriend(db, userId);
		if err != nil {
			return c.String(http.StatusBadRequest, "Get row error")
		}
		// http://127.0.0.1:1323/get_friend_list?id=3
		return c.JSON(http.StatusOK, friends)
	})

	e.GET("/get_friend_of_friend_list", func(c echo.Context) error {
		var twoHopFriends [] int

		userIdStr := c.QueryParam("id")
		userId, err := strconv.Atoi(userIdStr)
		if err != nil {
			return c.String(http.StatusBadRequest, "Invalid id")
		}
		twoHopFriends, err = getTwoHopFriend(db, userId);
		if err != nil {
			return c.String(http.StatusBadRequest, "Get row error")
		}
		// http://127.0.0.1:1323/get_friend_of_friend_list?id=2
		return c.JSON(http.StatusOK, twoHopFriends)
	})

	e.GET("/get_friend_of_friend_list_paging", func(c echo.Context) error {
		var pageLimitFriends [] int
		var twoHopFriends [] int

		userIdStr := c.QueryParam("id")
		userId, err := strconv.Atoi(userIdStr)
		if err != nil {
			return c.String(http.StatusBadRequest, "Invalid id")
		}
		limitStr := c.QueryParam("limit")
		limit, err := strconv.Atoi(limitStr)
		if err != nil {
			return c.String(http.StatusBadRequest, "Invalid limit")
		}
		pageStr := c.QueryParam("page")
		page, err := strconv.Atoi(pageStr)
		if err != nil {
			return c.String(http.StatusBadRequest, "Invalid page")
		}
		twoHopFriends, err = getTwoHopFriend(db, userId);
		if err != nil {
			return c.String(http.StatusBadRequest, "Get row error")
		}
		pageLimitFriends = getPageLimitFriends(twoHopFriends, limit, page)
		if pageLimitFriends == nil {
			return c.JSON(http.StatusBadRequest, "Invalid limit or page")
		} else {
			return c.JSON(http.StatusOK, pageLimitFriends)
		}
	})

	e.Logger.Fatal(e.Start(":" + strconv.Itoa(conf.Server.Port)))
}
