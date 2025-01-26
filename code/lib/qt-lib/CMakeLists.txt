set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)

qt_add_library(qt-lib
        ControlUnit.ui ControlUnit.h ControlUnit.cpp
        QtClock.hpp QtClock.cpp
        QtDisplay.hpp QtDisplay.cpp
        QtKeypad.hpp QtKeypad.cpp
        QtMainSwitch.hpp QtMainSwitch.cpp
        QtMoisture.hpp QtMoisture.cpp
        QtValve.hpp QtValve.cpp
        QtMemory.hpp QtMemory.cpp
)

target_link_libraries(qt-lib
        PUBLIC Qt6::Widgets
        PUBLIC core-lib
)
