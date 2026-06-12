set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(simulator-std STATIC
        StdClock.cpp
        StdDisplay.cpp
        StdKeypad.cpp
        StdMainSwitch.cpp
        StdMoisture.cpp
        StdMemory.cpp
        StdValveGroup.cpp
        StdDebugger.cpp
        StdTimer.cpp
)

target_link_libraries(simulator-std
        PUBLIC core
)
