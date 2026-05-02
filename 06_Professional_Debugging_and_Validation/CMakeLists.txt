add_library(ProfessionalDebugging 
    practice_01_hardfaults.c
)

target_include_directories(ProfessionalDebugging PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
