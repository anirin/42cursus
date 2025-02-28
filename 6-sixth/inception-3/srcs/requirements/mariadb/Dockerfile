FROM alpine:3.20

RUN apk add --no-cache mariadb mariadb-client

COPY ./conf/my.cnf /etc/my.cnf
COPY ./run.sh /scripts/run.sh

RUN chmod +x /scripts/run.sh

EXPOSE 3306

ENTRYPOINT ["/scripts/run.sh"]