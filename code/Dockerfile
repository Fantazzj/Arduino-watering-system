FROM fedora:latest AS desktop-env
LABEL authors="Fantazzj"
RUN dnf update -y && dnf install -y gcc g++ clang ninja cmake gdb
RUN dnf update -y && dnf install -y raylib-devel jetbrains-mono-fonts

FROM python:3 AS hardware-env
LABEL authors="Fantazzj"

RUN pip install platformio py-make
