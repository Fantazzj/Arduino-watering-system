add_executable(Arduino-watering-system
        main.cpp
)

if ($ENV{TYPE} STREQUAL "QTDESKTOP")
    target_link_libraries(Arduino-watering-system PUBLIC qt-lib)

elseif ($ENV{TYPE} STREQUAL "CLAYDESKTOP")
    target_link_libraries(Arduino-watering-system PUBLIC clay-lib)

endif ()

set_target_properties(Arduino-watering-system PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE FALSE
)
