set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(arduino)
add_subdirectory(button)
add_subdirectory(liquidcrystal-i2c)
add_subdirectory(time)

add_library(hardware-arduino STATIC
        HwClock.cpp
        HwDisplay.cpp
        HwKeypad.cpp
        HwMainSwitch.cpp
        HwMoisture.cpp
        HwMemory.cpp
        HwValveGroup.cpp
        HwDebugger.cpp
        HwTimer.cpp
)

target_link_libraries(hardware-arduino
        PUBLIC core
        PUBLIC arduinocore
        PUBLIC liquidcrystal-i2c
        PUBLIC button
        PUBLIC time
)
