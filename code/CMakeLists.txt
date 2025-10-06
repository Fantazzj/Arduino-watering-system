cmake_minimum_required(VERSION 3.20)

if ($ENV{TYPE} STREQUAL "HWARDUINO")
    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_SYSTEM_PROCESSOR avr)
endif ()

project(Arduino-watering-system VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (DEFINED ENV{TYPE})
    add_compile_definitions($ENV{TYPE})
else ()
    message(FATAL_ERROR "Build type is not defined")
endif ()

add_compile_definitions(VALVE_NUM=9 DISPLAY_LENGTH=16 DISPLAY_HEIGHT=2)

if ($ENV{TYPE} STREQUAL "CLAYDESKTOP")
    if (MSVC)
        add_compile_definitions(MSVC=0)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
    elseif (MINGW)
        add_compile_definitions(MINGW=0)
        add_compile_options(-fPIC)
        add_link_options(-fPIC)
    endif ()

    add_compile_definitions(DEBUG=1)
    add_subdirectory(lib/desktop-clay)

elseif ($ENV{TYPE} STREQUAL "HWARDUINO")
    set(AVR_MCU "atmega328p")
    set(AVR_PROGRAMMER "arduino")

    add_compile_options(-mmcu=${AVR_MCU} -Os -Wall -ffunction-sections -fdata-sections -flto)
    add_link_options(-mmcu=${AVR_MCU} -Os -Wall -ffunction-sections -fdata-sections -flto)

    add_compile_definitions(ARDUINO=100 F_CPU=16000000UL)
    add_subdirectory(lib/hardware-arduino)

    find_program(AVR_OBJCOPY avr-objcopy)
    add_custom_command(OUTPUT ${PROJECT_NAME}.hex
            COMMAND
            ${AVR_OBJCOPY} -j .text -j .data -O ihex ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.hex
            DEPENDS ${PROJECT_NAME}
    )

    find_program(AVR_SIZE avr-size)
    #add_custom_command(TARGET ${PROJECT_NAME}.size
    #        COMMAND
    #        ${AVR_SIZE} --mcu=${AVR_MCU} -C ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.elf
    #        DEPENDS ${PROJECT_NAME}
    #)

    find_program(AVRDUDE avrdude)
    add_custom_target(UPLOAD
            ${AVRDUDE}
            -C C:/msys64/ucrt64/etc/avrdude.conf
            -v
            -D
            -p ${AVR_MCU}
            -c ${AVR_PROGRAMMER}
            -U flash:w:${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.hex:i
            -P COM3
            -b 57600
            DEPENDS ${PROJECT_NAME}.hex #${PROJECT_NAME}.size
            COMMENT "Uploading ${PROJECT_NAME}.hex to ${AVR_MCU} using ${AVR_PROGRAMMER}"
    )
endif ()

add_subdirectory(src)
add_subdirectory(lib/date-time)
add_subdirectory(lib/core)
