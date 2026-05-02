add_library(AdvancedHardware 
    practice_01_interrupts_nvic.c
    practice_02_timers_pwm.c
    practice_03_dma.c
    practice_04_analog_adc.c
    practice_05_low_power.c
)

target_include_directories(AdvancedHardware PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
