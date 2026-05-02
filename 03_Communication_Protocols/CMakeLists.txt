add_library(CommunicationProtocols 
    practice_01_uart_basics.c
    practice_02_i2c_advanced.c
)

target_include_directories(CommunicationProtocols PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
