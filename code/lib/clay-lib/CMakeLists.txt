add_library(clay-lib
        ClayControlUnit.cpp
        ClayClock.cpp
        ClayDisplay.cpp
        ClayKeypad.cpp
        ClayMainSwitch.cpp
        ClayMoisture.cpp
        ClayMemory.cpp
        ClayValveGroup.cpp
        ClayDebugger.cpp
        ClayTimer.cpp
)

target_link_libraries(clay-lib
        PUBLIC core-lib
)
