set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(TimeLib
        GIT_REPOSITORY https://github.com/PaulStoffregen/Time.git
        GIT_TAG a18e50dcea4ee17285d732d39e7bc559482d1d3d # latest
)
FetchContent_MakeAvailable(TimeLib)
FetchContent_GetProperties(TimeLib)

add_library(time STATIC
        ${timelib_SOURCE_DIR}/Time.cpp
)

target_include_directories(time
        PUBLIC ${timelib_SOURCE_DIR}
)

target_link_libraries(time
        PUBLIC arduinocore
)
