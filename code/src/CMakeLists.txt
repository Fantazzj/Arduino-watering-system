set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Arduino-watering-system
        main.cpp
)

if ($ENV{TYPE} STREQUAL "CLAYDESKTOP")
    target_link_libraries(Arduino-watering-system PUBLIC desktop-clay)
    set_target_properties(Arduino-watering-system PROPERTIES
            WIN32_EXECUTABLE FALSE
    )

elseif ($ENV{TYPE} STREQUAL "HWARDUINO")
    target_link_libraries(Arduino-watering-system PUBLIC hardware-arduino)
    set_target_properties(Arduino-watering-system PROPERTIES
            SUFFIX ".elf"
    )
endif ()
