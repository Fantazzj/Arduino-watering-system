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

add_library(ui-clay STATIC
        ClayControlUnit.cpp
        ClayControlUnitUi.cpp
        ClayDisplayUi.cpp
        ClayKeypadUi.cpp
        ClayDebuggerUi.cpp
        ClayClockUi.cpp
        ClayValveGroupUi.cpp
        ClayMoistureUi.cpp
)

target_link_directories(ui-clay
        PRIVATE ${RAYLIB_DIR}
)

target_link_libraries(ui-clay
        PUBLIC raylib
)
