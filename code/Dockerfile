FROM fedora:latest
LABEL authors="Fantazzj"
RUN dnf update -y && dnf install -y gcc g++ clang ninja cmake gdb raylib-devel
RUN dnf update -y && dnf install -y jetbrains-mono-fonts
WORKDIR /tmp/code
COPY CMakeLists.txt .
COPY lib ./lib
COPY src ./src
ENV TYPE=CLAYDESKTOP
RUN cmake -S . -B build -G Ninja
RUN ninja -C build
#CMD ["./build/bin/Arduino-watering-system"]
