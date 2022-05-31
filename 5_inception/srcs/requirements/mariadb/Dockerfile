FROM alpine:3.15.3

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"
RUN apk update && apk upgrade
RUN apk add openrc && apk add mariadb mariadb-client
RUN mkdir -p /run/mysqld

COPY ./my.cnf /etc/mysql/
COPY ./initsql.sql /tmp/initsql.sql
COPY ./setupmariadb.sh /tmp/

RUN chmod 775 /tmp/setupmariadb.sh

RUN mkdir /run/openrc && touch /run/openrc/softlevel

EXPOSE 3306

CMD ["./tmp/setupmariadb.sh"]