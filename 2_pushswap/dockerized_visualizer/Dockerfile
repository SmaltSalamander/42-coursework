FROM debian:buster-slim
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc g++ git wget make libssl-dev
# RUN apt-get install -y gcc g++ git libxmu-dev xorg-dev
# INSTALL CURRENT CMAKE
RUN wget https://github.com/Kitware/CMake/releases/download/v3.25.0-rc4/cmake-3.25.0-rc4.tar.gz
RUN tar -zxvf cmake-3.25.0-rc4.tar.gz && cd cmake-3.25.0-rc4 && bash ./bootstrap
RUN make && make install
#FROM alpine:3.15.3
# RUN apk update && apk add valgrind
# RUN apk add g++ && apk add make
# CMD ["cd /valgrind"]
#Run it with:
#docker run -tiv $(pwd):/valgrind valgrind