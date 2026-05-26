set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${TARGET_ARCHITECTURE} STREQUAL WEB)
    include(FetchContent)
    set(PLATFORM Web)
    FetchContent_Declare(raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 5.5
    )
    FetchContent_MakeAvailable(raylib)
else ()
    find_package(raylib CONFIG REQUIRED)
endif ()

add_library(desktop-clay STATIC
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

add_library(desktop-clay-ui STATIC
        desktop-clay-ui/ClayControlUnitUi.cpp
        desktop-clay-ui/ClayDisplayUi.cpp
        desktop-clay-ui/ClayKeypadUi.cpp
        desktop-clay-ui/ClayDebuggerUi.cpp
        desktop-clay-ui/ClayClockUi.cpp
        desktop-clay-ui/ClayValveGroupUi.cpp
        desktop-clay-ui/ClayMoistureUi.cpp
)

target_link_directories(desktop-clay-ui
        PRIVATE ${RAYLIB_DIR}
)

target_link_libraries(desktop-clay-ui
        PUBLIC raylib
)

target_link_libraries(desktop-clay
        PUBLIC desktop-clay-ui
        PUBLIC core
)
