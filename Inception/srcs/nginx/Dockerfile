FROM alpine:3.20

RUN apk update && apk upgrade; \
	apk add nginx;

ENV NGINX_DIR=/etc/nginx/

COPY ./conf/nginx.conf $NGINX_DIR/nginx.conf
COPY ./conf/conf.d/virtual.conf $NGINX_DIR/conf.d/virtual.conf
COPY ./conf/conf.d/common.conf $NGINX_DIR/conf.d/common.conf
COPY ./conf/conf.d/wordpress.conf $NGINX_DIR/conf.d/wordpress.conf

COPY ./ssl/passwd $NGINX_DIR/ssl/passwd
COPY ./ssl/crt.pem $NGINX_DIR/ssl/crt.pem
COPY ./ssl/key.pem $NGINX_DIR/ssl/key.pem

EXPOSE 443

RUN adduser -u 82 -D -S -G www-data www-data;

CMD ["nginx", "-g", "daemon off;"]