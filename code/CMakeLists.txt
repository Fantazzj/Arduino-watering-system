cmake_minimum_required(VERSION 3.5)

project(Arduino-watering-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(QTDESKTOP)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)

qt_add_library(core-lib
        lib/core/AutoCycle.hpp lib/core/AutoCycle.cpp
        lib/core/Clock.hpp lib/core/Clock.cpp
        lib/core/Keypad.hpp lib/core/Keypad.cpp
        lib/core/Moisture.hpp lib/core/Moisture.cpp
        lib/core/PageSelector.hpp lib/core/PageSelector.cpp
        lib/core/MainSwitch.hpp lib/core/MainSwitch.cpp
        lib/core/UnitDisplay.hpp lib/core/UnitDisplay.cpp
        lib/core/Valve.hpp lib/core/Valve.cpp
        lib/core/MyTime.hpp lib/core/MyTime.cpp
        lib/core/MyDate.hpp lib/core/MyDate.cpp
        lib/core/MyDateTime.hpp lib/core/MyDateTime.cpp
        lib/core/MyString.hpp lib/core/MyString.cpp
        lib/core/Memory.hpp lib/core/Memory.cpp
        lib/core/Overrider.hpp
        lib/pages/EditClock.hpp lib/pages/EditClock.cpp
        lib/pages/EditEtvDays.hpp lib/pages/EditEtvDays.cpp
        lib/pages/EditEtvTime.hpp lib/pages/EditEtvTime.cpp
        lib/pages/EditSRWatered.hpp lib/pages/EditSRWatered.cpp
        lib/pages/EditTStart.hpp lib/pages/EditTStart.cpp
        lib/pages/Home.hpp lib/pages/Home.cpp
        lib/pages/ManualEtv.hpp lib/pages/ManualEtv.cpp
        lib/pages/Page.hpp lib/pages/Page.cpp
        lib/pages/PageController.hpp lib/pages/PageController.cpp
        lib/pages/Settings1.hpp lib/pages/Settings1.cpp
        lib/pages/Settings2.hpp lib/pages/Settings2.cpp
        lib/pages/Settings3.hpp lib/pages/Settings3.cpp
        lib/pages/Settings4.hpp lib/pages/Settings4.cpp
        lib/pages/Settings5.hpp lib/pages/Settings5.cpp
        lib/pages/Settings6.hpp lib/pages/Settings6.cpp
)

target_link_libraries(core-lib
        PUBLIC Qt6::Widgets
)

qt_add_library(qt-lib
        lib/qt-lib/ControlUnit.ui lib/qt-lib/ControlUnit.h lib/qt-lib/ControlUnit.cpp
        lib/qt-lib/QtClock.hpp lib/qt-lib/QtClock.cpp
        lib/qt-lib/QtDisplay.hpp lib/qt-lib/QtDisplay.cpp
        lib/qt-lib/QtKeypad.hpp lib/qt-lib/QtKeypad.cpp
        lib/qt-lib/QtMainSwitch.hpp lib/qt-lib/QtMainSwitch.cpp
        lib/qt-lib/QtMoisture.hpp lib/qt-lib/QtMoisture.cpp
        lib/qt-lib/QtValve.hpp lib/qt-lib/QtValve.cpp
        lib/qt-lib/QtMemory.hpp lib/qt-lib/QtMemory.cpp
)

target_link_libraries(qt-lib
        PUBLIC core-lib
)

qt_add_executable(Arduino-watering-system
        MANUAL_FINALIZATION src/main.cpp
)

target_link_libraries(Arduino-watering-system
        PRIVATE qt-lib
)

set_target_properties(Arduino-watering-system PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(Arduino-watering-system)
