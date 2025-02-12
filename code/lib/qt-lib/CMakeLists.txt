set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)

qt_add_library(qt-lib
        ControlUnit.ui ControlUnit.cpp
        QtClock.cpp
        QtDisplay.cpp
        QtKeypad.cpp
        QtMainSwitch.cpp
        QtMoisture.cpp
        QtMemory.cpp
        QtValveGroup.cpp
        QtDebugger.cpp
        QtTimer.cpp
)

target_link_libraries(qt-lib
        PUBLIC Qt6::Widgets
        PUBLIC core-lib
)
