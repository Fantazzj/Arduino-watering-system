cmake_minimum_required(VERSION 3.5)

project(Arduino-watering-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.3.1\\mingw_64")#
#set(QT_DIR "C:\\Qt\\6.3.1\\mingw_64")#

add_compile_definitions(QTDESKTOP)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6Widgets REQUIRED)#

#target_link_libraries(Arduino-watering-system Qt6::Widgets)#

set(PROJECT_SOURCES
        ./main.cpp
        ./code.ino
        ./lib/ControlUnit.cpp
        ./lib/ControlUnit.h
        ./lib/ControlUnit.ui
        )

qt_add_executable(Arduino-watering-system MANUAL_FINALIZATION ${PROJECT_SOURCES})

target_link_libraries(Arduino-watering-system PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Arduino-watering-system PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

    qt_finalize_executable(Arduino-watering-system)
