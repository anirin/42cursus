package repository_test

import (
	"problem1/repository"
	"testing"
	"problem1/configs"
	"database/sql"
	"reflect"
	_ "github.com/go-sql-driver/mysql"
)

func TestGetFriendList(t *testing.T) {
	expected := []int{2, 3}

	conf := configs.Get()
	db, err := sql.Open(conf.DB.Driver, conf.DB.DataSource)
	if err != nil {
		t.Fatal(err)
	}
	defer db.Close()
	id := "1"

	got, err := repository.GetFriendLinkList(db, id)
	if err != nil {
		t.Fatal(err)
	}

	if reflect.DeepEqual(got, expected) == false {
		t.Errorf("got %v\nwant %v", got, expected)
	}
}