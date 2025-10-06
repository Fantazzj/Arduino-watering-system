set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Arduino-watering-system
        main.cpp
)

if (TARGET_ARCHITECTURE STREQUAL AVR)
    target_link_libraries(Arduino-watering-system PUBLIC hardware-arduino)
    set_target_properties(Arduino-watering-system PROPERTIES
            SUFFIX ".elf"
    )
elseif (TARGET_ARCHITECTURE STREQUAL DESKTOP)
    target_link_libraries(Arduino-watering-system PUBLIC desktop-clay)
    set_target_properties(Arduino-watering-system PROPERTIES
            WIN32_EXECUTABLE FALSE
    )

endif ()
