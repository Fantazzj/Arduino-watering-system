FROM alpine:latest
LABEL authors="Fantazzj"
RUN apk update && apk add --no-interactive gcc g++ clang ninja cmake gdb raylib-dev
WORKDIR /tmp/code
COPY CMakeLists.txt .
COPY lib ./lib
COPY src ./src
ENV TYPE=CLAYDESKTOP
RUN cmake -S . -B build
RUN make -C build
CMD ["./build/bin/Arduino-watering-system"]
