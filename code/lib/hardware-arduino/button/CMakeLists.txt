set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(Button
        GIT_REPOSITORY https://github.com/Fantazzj/button-lib.git
        GIT_TAG a5a3cf3b8453a6062ffacf2603f93f6f4077e1fc # latest
)
FetchContent_MakeAvailable(Button)
FetchContent_GetProperties(Button)

add_library(button STATIC
        ${button_SOURCE_DIR}/src/Button.cpp
)

target_include_directories(button
        PUBLIC ${button_SOURCE_DIR}/src
)

target_link_libraries(button
        PUBLIC arduinocore
)
