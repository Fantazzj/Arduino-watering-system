cmake_minimum_required(VERSION 3.20)

project(Arduino-watering-system VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (DEFINED ENV{TYPE})
    add_compile_definitions($ENV{TYPE})
else ()
    message(FATAL_ERROR "Build type is not defined")
endif ()

add_compile_definitions(VALVE_NUM=9)
add_compile_definitions(DISPLAY_LENGTH=16)
add_compile_definitions(DISPLAY_HEIGHT=2)

if (MSVC)
    add_compile_definitions(MSVC=0)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
elseif (MINGW)
    add_compile_definitions(MINGW=0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif ()

if ($ENV{TYPE} STREQUAL "CLAYDESKTOP")
    add_compile_definitions(DEBUG=1)
    add_subdirectory(lib/clay-lib)
endif ()

add_subdirectory(src)
add_subdirectory(lib/date-time-lib)
add_subdirectory(lib/core-lib)
