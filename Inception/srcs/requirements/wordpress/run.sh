#! /bin/sh

until mysqladmin ping -h ${DBHOST} -u ${DBUSER} -p${DBPASS} ; do
	echo "Waiting for database to be ready..."
	sleep 5
done

php -d memory_limit=258M /usr/local/bin/wp core download --locale=ja --path=/var/www/html
wp core config --dbname=${DBNAME} --dbuser=${DBUSER} --dbpass=${DBPASS} --dbhost=${DBHOST} --dbprefix=${DBPREFIX} --path=/var/www/html;
wp core install --url=${SITE_URL} --title=${SITE_TITLE} --admin_user=${ADMIN_USER} --admin_password=${ADMIN_PASSWORD} --admin_email=${ADMIN_EMAIL} --path=/var/www/html;
wp user create $USER $EMAIL --user_pass=$PASSWORD --role=author --path=/var/www/html;

adduser -u 82 -D -S -G www-data www-data;
chown -R www-data:www-data /var/www/html;

exec php-fpm --nodaemonize;