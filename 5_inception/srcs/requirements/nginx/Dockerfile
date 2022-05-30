FROM alpine:3.15.3

LABEL maintainer "sbienias <sbienias@student.42wolfsburg.de>"

RUN apk update && apk upgrade
RUN apk add --update nginx && rm -rf /var/cache/apk/*

# RUN mkdir -p /tmp/nginx/client-body

COPY nginx.conf /etc/nginx/nginx.conf

COPY default.conf /etc/nginx/http.d/default.conf

COPY website /usr/share/nginx/html

EXPOSE 443
#Debugging
#RUN apk add vim

CMD ["nginx", "-g", "daemon off;"]