set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(LiquidCrystal_I2C
        GIT_REPOSITORY https://github.com/johnrickman/LiquidCrystal_I2C.git
        GIT_TAG 738765e388816fb2a687d40436cd2604febce1b1 # latest
)
FetchContent_MakeAvailable(LiquidCrystal_I2C)
FetchContent_GetProperties(LiquidCrystal_I2C)

add_library(liquidcrystal-i2c STATIC
        ${liquidcrystal_i2c_SOURCE_DIR}/LiquidCrystal_I2C.cpp
)

target_include_directories(liquidcrystal-i2c
        PUBLIC ${liquidcrystal_i2c_SOURCE_DIR}
)

target_link_libraries(liquidcrystal-i2c
        PUBLIC wire
)
