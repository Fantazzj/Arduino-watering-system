set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core-lib
        AutoCycle.cpp
        PageSelector.cpp
        UnitDisplay.cpp
        Valve.cpp
        Memory.cpp
        Debugger.cpp
        ../pages/EditClock.cpp
        ../pages/EditEtvDays.cpp
        ../pages/EditEtvTime.cpp
        ../pages/EditSRWatered.cpp
        ../pages/EditTStart.cpp
        ../pages/Home.cpp
        ../pages/ManualEtv.cpp
        ../pages/Page.cpp
        ../pages/PageController.cpp
        ../pages/Settings1.cpp
        ../pages/Settings2.cpp
        ../pages/Settings3.cpp
        ../pages/Settings4.cpp
        ../pages/Settings5.cpp
        ../pages/Settings6.cpp
)

target_link_libraries(core-lib
        PUBLIC date-time-lib
)
