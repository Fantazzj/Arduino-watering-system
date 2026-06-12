set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (TARGET_ARCHITECTURE STREQUAL AVR)
    add_executable(Arduino-watering-system
            arduinoMain.cpp
    )
    target_link_libraries(Arduino-watering-system PUBLIC hardware-arduino)
    set_target_properties(Arduino-watering-system PROPERTIES
            SUFFIX ".elf"
    )

elseif (TARGET_ARCHITECTURE STREQUAL DESKTOP)
    add_executable(Arduino-watering-system
            desktopMain.cpp
    )
    target_link_libraries(Arduino-watering-system
            PUBLIC simulator-std
            PUBLIC ui-clay
    )
    set_target_properties(Arduino-watering-system PROPERTIES
            WIN32_EXECUTABLE FALSE
    )

elseif (TARGET_ARCHITECTURE STREQUAL WEB)
    add_executable(Arduino-watering-system
            webMain.cpp
    )
    target_link_libraries(Arduino-watering-system
            PUBLIC simulator-std
            PUBLIC ui-clay
    )
    set_target_properties(Arduino-watering-system PROPERTIES
            SUFFIX ".html"
    )

endif ()
