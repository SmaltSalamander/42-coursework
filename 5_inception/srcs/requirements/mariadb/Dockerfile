FROM alpine:3.15.6

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"
RUN apk update && apk upgrade
RUN apk add openrc mariadb mariadb-client
RUN mkdir -p /data/mysqld && rm -rf /var/cache/apk*

COPY ./tools/my.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY ./tools/initsql.sql /tmp/initsql.sql
COPY ./tools/setupmariadb.sh /tmp/setupmariadb.sh

RUN mkdir -p /var/lib/mysql && chown -R mysql:root /var/lib/mysql \
&& chgrp -R mysql /var/lib/mysql

ENTRYPOINT [ "sh", "/tmp/setupmariadb.sh"]

# LOGIN TO MARIADB, with --user and --password, then USE dbname then show tables;