find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)

qt_add_library(core-lib
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
        PRIVATE Qt6::Widgets
        PUBLIC date-time-lib
)
