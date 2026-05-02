add_library(CorePeripherals 
    practice_01_gpio_basics.c
)

target_include_directories(CorePeripherals PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
