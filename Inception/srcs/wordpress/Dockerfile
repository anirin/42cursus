# php-fpm
FROM alpine:3.20

ENV PHPIZE_DEPS \
		g++ \
		gcc \
		make \
		pkgconfig \
		curl \
		tar \
		libxml2-dev \
		linux-headers \
		sqlite-dev

ENV PHP_INI_DIR /usr/local/etc/php
ENV PHP_URL="https://www.php.net/distributions/php-8.3.15.tar.xz"

RUN set -eux; \
	adduser -u 82 -D -S -G www-data www-data;

RUN set -eux; \
	mkdir -p "$PHP_INI_DIR/conf.d"; \
	mkdir -p /var/www/html; \
	chown -R www-data:www-data /var/www/html; \
	chmod 1777 /var/www/html;

RUN set -eux; \
	apk add $PHPIZE_DEPS; \
	mkdir -p /usr/src/php; \
	cd /usr/src/; \
	curl -f -o php.tar.xz $PHP_URL;

RUN	tar -xJf /usr/src/php.tar.xz -C "/usr/src/php" --strip-components=1;

RUN	cd /usr/src/php; \
	./configure \
		--enable-fpm \
		--with-mysqli \
		--with-config-file-path=$PHP_INI_DIR \
		--with-fpm-user=www-data \
		--with-fpm-group=www-data \
		--with-zlib;

RUN	cd /usr/src/php; \
	make -j "$(nproc)"; \
	make install; \
	make clean;

#! 設定類はADDで追加した方がいい説あり
RUN mkdir -p $PHP_INI_DIR; \
	cp /usr/src/php/php.ini-development $PHP_INI_DIR/php.ini;
RUN cd /usr/local/etc/; \
	sed 's!=NONE/!=!g' php-fpm.conf.default | tee php-fpm.conf > /dev/null; \
	cp php-fpm.d/www.conf.default php-fpm.d/www.conf; \
	#! 0.0.0.0ではなくてnginxにするとうまくいくかも
	sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' php-fpm.d/www.conf;
RUN cp /usr/src/php/sapi/fpm/php-fpm.8 /usr/local/bin/php-fpm.8;

# wordpress
ENV WP_PATH="/var/www/html"

RUN set -eux; \
	version='6.7.1'; \
	curl -o wordpress.tar.gz -fL "https://wordpress.org/wordpress-$version.tar.gz";

RUN tar -xzf wordpress.tar.gz -C $WP_PATH --strip-components=1; \
	rm wordpress.tar.gz;

COPY wp-config.php $WP_PATH/wp-config.php

#debug
RUN chmod -R 777 $WP_PATH;

# RUN chown -R www-data:www-data $WP_PATH; \
# 	chown -R www-data:www-data $WP_PATH/wp-content; \
# 	chmod -R 1777 $WP_PATH/wp-content

# VOLUME $WP_PATH

EXPOSE 9000

CMD ["php-fpm", "--nodaemonize"]

WORKDIR $WP_PATH
# test用
# cgi-fcgi -bind -connect localhost:9000
