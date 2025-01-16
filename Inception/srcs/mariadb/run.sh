#!/bin/sh
# 変数格納
MYSQL_ROOT_PASSWORD=root
MYSQL_DATABASE=wordpress
MYSQL_USER=user
MYSQL_PASSWORD=password

# 足りていないdirを追加
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# データベースのディレクトリを作成
chown -R mysql:mysql /var/lib/mysql
mariadb-install-db --user=mysql --datadir=/var/lib/mysql

# データベースの初期化
tfile=$(mktemp)
cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${MYSQL_ROOT_PASSWORD}');
GRANT ALL ON *.* TO 'user'@'%' IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'user'@'localhost' IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;
SET PASSWORD FOR 'user'@'localhost' = PASSWORD('${MYSQL_PASSWORD}');
DROP DATABASE IF EXISTS test;
CREATE DATABASE $MYSQL_DATABASE;
FLUSH PRIVILEGES;
EOF

/usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < $tfile
rm -f $tfile

# デーモンの起動
exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0 $@