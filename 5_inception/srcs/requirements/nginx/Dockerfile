FROM alpine:3.15.6

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"

RUN apk update && apk upgrade
RUN apk add openssl nginx && rm -rf /var/cache/apk/*

# RUN mkdir -p /tmp/nginx/client-body

#https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-nginx-in-ubuntu-18-04
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj "/C=DE/ST=Niedersachsen/L=Wolfsburg/O=42Wolfsburg/CN=sbienias.42.fr" \
	-keyout /etc/ssl/nginx-selfsigned.key \
	-out /etc/ssl/nginx-selfsigned.crt

COPY tools/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /run/nginx
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]