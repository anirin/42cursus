# php-fpm
FROM alpine:3.20

RUN apk update && apk upgrade;
RUN apk add php82 php82-fpm php82-mysqli;
RUN cd /etc/php82/; \
	sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' php-fpm.d/www.conf;
RUN ln -s /usr/bin/php82 /usr/bin/php; \
	ln -s /usr/sbin/php-fpm82 /usr/sbin/php-fpm;

# wordpress
ENV WP_PATH="/var/www/html"

RUN apk add curl;
RUN set -eux; \
	version='6.7.1'; \
	curl -o wordpress.tar.gz -fL "https://wordpress.org/wordpress-$version.tar.gz";
RUN tar -xzf wordpress.tar.gz -C $WP_PATH --strip-components=1; \
	rm wordpress.tar.gz;

COPY wp-config.php $WP_PATH/wp-config.php

RUN set -eux; \
	adduser -u 82 -D -S -G www-data www-data;
RUN chown -R www-data:www-data $WP_PATH;

WORKDIR $WP_PATH

EXPOSE 9000

ENTRYPOINT ["php-fpm", "--nodaemonize"]

# test用
# cgi-fcgi -bind -connect localhost:9000