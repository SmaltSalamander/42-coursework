FROM alpine:3.15.3
RUN apk update && apk add valgrind && mkdir test
RUN apk add clang && apk add make
WORKDIR ./test
ENTRYPOINT make
ENTRYPOINT ["valgrind"]