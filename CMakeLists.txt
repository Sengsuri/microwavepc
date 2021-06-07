cmake_minimum_required(VERSION 3.16)

include(pico_sdk_import.cmake)

project(microwave_pc)

add_executable(main
    main.cpp
    Display.cpp
    usb_descriptors.c   
 )

 target_include_directories(main PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_sdk_init()

pico_generate_pio_header(main ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

 target_link_libraries(main 
    PRIVATE pico_stdlib
    hardware_spi
    hardware_pio
    hardware_flash
    hardware_dma 
    pico_multicore
    tinyusb_board
    tinyusb_device
 )

 pico_enable_stdio_uart(main 0)

 pico_add_extra_outputs(main)
