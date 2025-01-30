set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    endif ()
endif ()

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

target_link_libraries(clay-lib
        PUBLIC core-lib
        PRIVATE raylib
)
