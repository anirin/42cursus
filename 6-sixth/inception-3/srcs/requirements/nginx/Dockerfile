FROM alpine:3.20

RUN apk update && apk upgrade; \
	apk add nginx;

ENV NGINX_DIR=/etc/nginx

COPY ./conf/nginx.conf $NGINX_DIR/nginx.conf
COPY ./conf/conf.d/virtual.conf $NGINX_DIR/conf.d/virtual.conf
COPY ./conf/conf.d/wordpress.conf $NGINX_DIR/conf.d/wordpress.conf

# openssl
RUN apk add openssl;
RUN set -eux;
RUN mkdir -p $NGINX_DIR/ssl;
RUN openssl genrsa -out $NGINX_DIR/ssl/key.pem 2048;
RUN openssl req -batch -new -key $NGINX_DIR/ssl/key.pem -out $NGINX_DIR/ssl/csr.pem
RUN openssl x509 -req -days 3650 -signkey $NGINX_DIR/ssl/key.pem -in $NGINX_DIR/ssl/csr.pem -out $NGINX_DIR/ssl/crt.pem
RUN rm $NGINX_DIR/ssl/csr.pem

EXPOSE 443

RUN adduser -u 82 -D -S -G www-data www-data;

ENTRYPOINT ["nginx", "-g", "daemon off;"]