FROM alpine:3.15.3

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"
RUN apk update && apk upgrade
RUN apk add php-fpm
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz && rm latest.tar.gz
RUN cp wordpress/wp-config-sample.php wordpress/wp-config.php

EXPOSE 9000
EXPOSE 3306
CMD [ "executable" ]