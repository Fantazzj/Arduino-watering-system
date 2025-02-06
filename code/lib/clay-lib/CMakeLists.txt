set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

add_library(clay-lib SHARED
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

add_library(clayUi-lib
        ClayUi/ClayControlUnitUi.cpp
        ClayUi/ClayDisplayUi.cpp
        ClayUi/ClayKeypadUi.cpp
        ClayUi/ClayDebuggerUi.cpp
        ClayUi/ClayValveGroupUi.cpp
        ClayUi/clay.cpp
)

target_link_directories(clayUi-lib PRIVATE ${RAYLIB_DIR})

target_link_libraries(clayUi-lib
        PUBLIC raylib
)

target_link_libraries(clay-lib
        PRIVATE clayUi-lib
        PUBLIC core-lib
)
