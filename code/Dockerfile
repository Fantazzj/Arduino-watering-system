FROM fedora:latest AS clay
LABEL authors="Fantazzj"
RUN dnf update -y && dnf install -y gcc g++ clang ninja cmake gdb
RUN dnf update -y && dnf install -y raylib-devel jetbrains-mono-fonts

FROM clay AS clay-run
ENV TYPE=CLAYDESKTOP
WORKDIR /tmp/code
COPY CMakeLists.txt .
COPY lib ./lib
COPY src ./src
RUN cmake -S . -B build -G Ninja
RUN ninja -C build
#CMD ["./build/bin/Arduino-watering-system"]
