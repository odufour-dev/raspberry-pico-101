
set(COMPONENT_NAME pico_led)

add_library(${COMPONENT_NAME} INTERFACE)
target_sources(${COMPONENT_NAME} INTERFACE pico_led.c)
target_include_directories(${COMPONENT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries(${COMPONENT_NAME} INTERFACE pico_stdlib pico_cyw43_arch_none)
