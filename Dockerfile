FROM alpine:3.14

RUN apk add g++ cmake ninja pkgconfig 
RUN apk add guile-dev gmp-dev

RUN mkdir -p /opt/src
WORKDIR /opt/src

ADD CMakeLists.txt .
ADD guile-test.cc .

RUN cmake -B /opt/build /opt/src -G Ninja
RUN cmake --build /opt/build
RUN cmake --install /opt/build

