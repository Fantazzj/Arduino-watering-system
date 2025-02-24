cmake_minimum_required(VERSION 3.5)

project(Arduino-watering-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (DEFINED ENV{TYPE})
    add_compile_definitions($ENV{TYPE})
else ()
    message(FATAL_ERROR "Build type is not defined")
endif ()

add_compile_definitions(VALVE_NUM=9)

if ($ENV{TYPE} STREQUAL "QTDESKTOP")
    add_subdirectory(lib/qt-lib)
elseif ($ENV{TYPE} STREQUAL "CLAYDESKTOP")
    message(FATAL_ERROR "CLAY not yet supported")
endif ()

add_subdirectory(src)
add_subdirectory(lib/date-time-lib)
add_subdirectory(lib/core-lib)
