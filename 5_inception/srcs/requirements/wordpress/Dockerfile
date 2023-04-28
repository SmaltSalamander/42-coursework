FROM alpine:3.15.6

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"
RUN apk update && apk upgrade

RUN apk add --no-cache \
	php \
	php-fpm \
	php-json \
	php-common \
	php-session \
	php-iconv \
	php-gd \
	php-curl \
	php-xml \
	php-mysqli \
	php-imap \php-cgi \
	fcgi \
	php-pdo \
	php-pdo_mysql \
	php-soap \
	php-xmlrpc \
	php-posix \
	php-gettext \
	php-ldap \
	php-ctype \
	php-dom \
	php-simplexml \
	php-phar \
	php-tokenizer \
	php7-redis \
	mariadb-client

WORKDIR /home/sbienias/data/v-wordprs/
RUN adduser -S nginx && addgroup -S nginx && adduser nginx nginx
COPY ./tools/wp-setup.sh /tmp/wp-setup.sh
# Install WP-CLI, for commands to wp from terminal
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar\
 && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/www.conf /etc/php/php-fpm.d/www.conf
COPY ./tools/www.conf /etc/php7/php-fpm.d/www.conf
COPY ./tools/php-fpm.conf /etc/php7/php-fpm.conf

RUN export DBHOST=127.0.0.1:336
ENTRYPOINT [ "sh", "/tmp/wp-setup.sh"]

# ADD wp-admin at the end of link to access the panel