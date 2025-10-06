set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(ArduinoCore
        GIT_REPOSITORY https://github.com/arduino/ArduinoCore-avr.git
        GIT_TAG 42fa4a1ea1b1b11d1cc0a60298e529d37f9d14bd # latest
)
FetchContent_MakeAvailable(ArduinoCore)
FetchContent_GetProperties(ArduinoCore)

file(GLOB_RECURSE ARDUINOCORE_SRC
        CONFIGURE_DEPENDS
        ${arduinocore_SOURCE_DIR}/cores/arduino/*.c
        ${arduinocore_SOURCE_DIR}/cores/arduino/*.h
        ${arduinocore_SOURCE_DIR}/cores/arduino/*.cpp
)

add_library(arduinocore STATIC
        ${ARDUINOCORE_SRC}
)

target_include_directories(arduinocore
        PUBLIC ${arduinocore_SOURCE_DIR}/cores/arduino
        PUBLIC ${arduinocore_SOURCE_DIR}/libraries/EEPROM/src
        PUBLIC ${arduinocore_SOURCE_DIR}/variants/standard
)

add_library(wire STATIC
        ${arduinocore_SOURCE_DIR}/libraries/Wire/src/Wire.cpp
        ${arduinocore_SOURCE_DIR}/libraries/Wire/src/utility/twi.c
)

target_include_directories(wire
        PUBLIC ${arduinocore_SOURCE_DIR}/libraries/Wire/src
)

target_link_libraries(wire
        PUBLIC arduinocore
)
