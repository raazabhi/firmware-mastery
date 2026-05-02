add_library(ArchitectureFoundations 
    bit_manipulation.c
    practice_01_bit_math.c
)

target_include_directories(ArchitectureFoundations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
