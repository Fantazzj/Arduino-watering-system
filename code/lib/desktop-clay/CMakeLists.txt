set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

add_library(desktop-clay SHARED
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

add_library(desktop-clay-ui SHARED
        desktop-clay-ui/ClayControlUnitUi.cpp
        desktop-clay-ui/ClayDisplayUi.cpp
        desktop-clay-ui/ClayKeypadUi.cpp
        desktop-clay-ui/ClayDebuggerUi.cpp
        desktop-clay-ui/ClayClockUi.cpp
        desktop-clay-ui/ClayValveGroupUi.cpp
        desktop-clay-ui/ClayMoistureUi.cpp
        desktop-clay-ui/clay_renderer_raylib.c
)

target_link_directories(desktop-clay-ui PRIVATE ${RAYLIB_DIR})

target_link_libraries(desktop-clay-ui
        PUBLIC raylib
)

target_link_libraries(desktop-clay
        PUBLIC desktop-clay-ui
        PUBLIC core
)
