add_library(RtosConcurrency 
    practice_01_rtos_tasks.c
)

target_include_directories(RtosConcurrency PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
