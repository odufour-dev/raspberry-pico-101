cmake_minimum_required(VERSION 3.30)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

set(PROJECT_NAME simple_example)
project(${PROJECT_NAME})
pico_sdk_init()

add_executable(${PROJECT_NAME} sources/main.c)

target_link_libraries(${PROJECT_NAME} pico_stdlib)

pico_add_extra_outputs(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION /home/dev/bin)