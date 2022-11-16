FROM debian:buster-slim
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc cmake libsfml-dev g++ git libxmu-dev xorg-dev
#FROM alpine:3.15.3
# RUN apk update && apk add valgrind
# RUN apk add g++ && apk add make
# CMD ["cd /valgrind"]
#Run it with:
#docker run -tiv $(pwd):/valgrind valgrind