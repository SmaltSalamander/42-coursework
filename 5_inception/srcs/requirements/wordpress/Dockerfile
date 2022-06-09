FROM alpine:3.15.3

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"
RUN apk update && apk upgrade
RUN apk add php-fpm openrc
WORKDIR /data/wordpress
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz && rm latest.tar.gz
COPY ./tools/wp-config.php /data/wordpress/wordpress

EXPOSE 9000
EXPOSE 3306
# RUN rc-service php-fpm7 restart