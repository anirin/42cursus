#!/bin/sh

# ディレクトリの作成
if [ -d /run/mysqld ]; then
	echo ""; echo "[dockerfile log] mariadb data already exists"; echo ""
else
	echo ""; echo "[dockerfile log] mariadb data not found"; echo ""

	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

if [ -d /var/lib/mysql/mysql ]; then
	echo ""; echo "[dockerfile log] mariadb data already exists"; echo ""
else
	echo ""; echo "[dockerfile log] mariadb data not found"; echo ""

	# mariadb dataを作成 (最終的に保存する必要あり)
	echo ""; echo "[dockerfile log] mariadb data creating..."; echo ""
	chown -R mysql:mysql /var/lib/mysql
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

	echo ""; echo "[dockerfile log] mariadb data initializing..."; echo ""
	/usr/bin/mariadbd --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;

-- rootユーザーの設定
 ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
# CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
# GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
# GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;

-- データベースとユーザーの作成
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;

-- wordpressユーザーの作成
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF
fi

# 実行
echo ""; echo "[dockerfile log] mariadb running..."; echo ""
exec /usr/bin/mariadbd-safe --user=mysql