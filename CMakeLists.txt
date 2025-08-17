cmake_minimum_required(VERSION 3.30)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

set(PROJECT_NAME simple_example)
project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME} sources/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE pico_stdlib)

add_subdirectory(sources/pico_led)
target_link_libraries(${PROJECT_NAME} PRIVATE pico_led)

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
# example_auto_set_url(${PROJECT_NAME})

# install(TARGETS ${PROJECT_NAME} DESTINATION /home/dev/bin)