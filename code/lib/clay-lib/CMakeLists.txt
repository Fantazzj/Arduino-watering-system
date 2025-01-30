find_package(raylib CONFIG REQUIRED)

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
        ClayUi.c
)

target_link_directories(clay-lib PRIVATE ${RAYLIB_DIR})

target_link_libraries(clay-lib
        PRIVATE core-lib
        PRIVATE raylib
)
