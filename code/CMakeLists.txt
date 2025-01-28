cmake_minimum_required(VERSION 3.5)

project(Arduino-watering-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_definitions(QTDESKTOP)
add_definitions(-DVALVE_NUM=9)

add_subdirectory(src)
add_subdirectory(lib/date-time-lib)
add_subdirectory(lib/core-lib)
add_subdirectory(lib/qt-lib)
