find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)

qt_add_library(core-lib
        AutoCycle.hpp AutoCycle.cpp
        Clock.hpp
        Keypad.hpp
        Moisture.hpp
        PageSelector.hpp PageSelector.cpp
        MainSwitch.hpp
        UnitDisplay.hpp UnitDisplay.cpp
        Valve.hpp Valve.cpp
        Memory.hpp Memory.cpp
        Overrider.hpp
        ValveGroup.hpp ValveGroup.cpp
        ../pages/EditClock.hpp ../pages/EditClock.cpp
        ../pages/EditEtvDays.hpp ../pages/EditEtvDays.cpp
        ../pages/EditEtvTime.hpp ../pages/EditEtvTime.cpp
        ../pages/EditSRWatered.hpp ../pages/EditSRWatered.cpp
        ../pages/EditTStart.hpp ../pages/EditTStart.cpp
        ../pages/Home.hpp ../pages/Home.cpp
        ../pages/ManualEtv.hpp ../pages/ManualEtv.cpp
        ../pages/Page.hpp ../pages/Page.cpp
        ../pages/PageController.hpp ../pages/PageController.cpp
        ../pages/Settings1.hpp ../pages/Settings1.cpp
        ../pages/Settings2.hpp ../pages/Settings2.cpp
        ../pages/Settings3.hpp ../pages/Settings3.cpp
        ../pages/Settings4.hpp ../pages/Settings4.cpp
        ../pages/Settings5.hpp ../pages/Settings5.cpp
        ../pages/Settings6.hpp ../pages/Settings6.cpp
)

target_link_libraries(core-lib
        PRIVATE Qt6::Widgets
        PUBLIC date-time-lib
)
