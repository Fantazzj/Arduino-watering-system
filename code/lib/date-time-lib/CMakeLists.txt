set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(date-time-lib SHARED
        MyTime.cpp
        MyDate.cpp
        MyDateTime.cpp
)
