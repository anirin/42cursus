FROM alpine:3.20

# php-fpm
RUN apk update && apk upgrade;
RUN apk add php82 php82-fpm php82-mysqli php82-phar php82-mbstring php82-iconv;
RUN cd /etc/php82/; \
	sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' php-fpm.d/www.conf;
RUN ln -s /usr/bin/php82 /usr/bin/php; \
	ln -s /usr/sbin/php-fpm82 /usr/sbin/php-fpm;

# wordpress
ENV WP_PATH="/var/www/html"

RUN apk add curl;
RUN set -eux; \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
	chmod +x wp-cli.phar; \
	mv wp-cli.phar /usr/local/bin/wp;

RUN mkdir -p /scripts

COPY run.sh /scripts/run.sh

RUN set -eux; \
	apk add mysql-client; \
	chmod +x /scripts/run.sh;

WORKDIR $WP_PATH

EXPOSE 9000

ENTRYPOINT ["/scripts/run.sh"]
