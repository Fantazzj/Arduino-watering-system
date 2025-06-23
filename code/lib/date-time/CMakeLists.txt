set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(date-time SHARED
        MyTime.cpp
        MyDate.cpp
        MyDateTime.cpp
)
