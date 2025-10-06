cmake_minimum_required(VERSION 4.0)

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
    set(TARGET_ARCHITECTURE AVR)

    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_SYSTEM_PROCESSOR avr)

    find_program(AVRDUDE avrdude.exe)
    find_program(AVR_SIZE avr-size.exe)
    find_program(AVR_OBJCOPY avr-objcopy.exe)

    set(AVR_MCU "atmega328p" CACHE STRING "Target AVR device")
    set(AVR_PROGRAMMER "arduino" CACHE STRING "Target upload protocol")
    set(AVR_PORT CACHE STRING "Target upload port")
    set(AVR_BAUD CACHE STRING "Target upload baud rate")
    set(AVRDUDE_CONF CACHE STRING "Path of avrdude configuration file")

elseif (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set(TARGET_ARCHITECTURE DESKTOP)

else ()
    message(FATAL_ERROR "Only supported Debug and Release build types")

endif ()

project(Arduino-watering-system VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_definitions(VALVE_NUM=9 DISPLAY_LENGTH=16 DISPLAY_HEIGHT=2)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    add_compile_definitions(CLAYDESKTOP=0 DEBUG=0)

    if (MSVC)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
    elseif (MINGW)
        add_compile_options(-fPIC)
        add_link_options(-fPIC)
    endif ()

    add_subdirectory(lib/desktop-clay)

elseif (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_compile_definitions(HWARDUINO=0 RELEASE=0)
    add_compile_options(-mmcu=${AVR_MCU} -Os -Wall -ffunction-sections -fdata-sections -flto)
    add_link_options(-mmcu=${AVR_MCU} -Os -Wall -ffunction-sections -fdata-sections -flto)

    add_compile_definitions(ARDUINO=100 F_CPU=16000000UL)
    add_subdirectory(lib/hardware-arduino)

    add_custom_target(CONVERT_AND_CHECK_SIZE
            COMMAND
            ${AVR_OBJCOPY} -j .text -j .data -O ihex ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.hex
            COMMAND
            ${AVR_SIZE} -C --mcu=${AVR_MCU} ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.elf
            DEPENDS ${PROJECT_NAME}
    )

    add_custom_target(UPLOAD
            ${AVRDUDE}
            -C ${AVRDUDE_CONF}
            -v
            -D
            -p ${AVR_MCU}
            -c ${AVR_PROGRAMMER}
            -U flash:w:${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.hex:i
            -P ${AVR_PORT}
            -b ${AVR_BAUD}
            DEPENDS ${PROJECT_NAME}.hex
            COMMENT "Uploading ${PROJECT_NAME}.hex to ${AVR_MCU} using ${AVR_PROGRAMMER} as programmer"
    )
endif ()

add_subdirectory(src)
add_subdirectory(lib/date-time)
add_subdirectory(lib/core)
