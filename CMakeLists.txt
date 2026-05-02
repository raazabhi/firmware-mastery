cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(FirmwareMastery VERSION 1.0.0 LANGUAGES C)

# Set C standard to C99/C11 (Standard for most embedded systems)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable compiler warnings (Crucial for robust firmware)
# -Wall -Wextra: Enable standard warnings
# -Werror: Treat warnings as errors (Senior best practice)
# -Wshadow: Warn whenever a local variable shadows another variable
add_compile_options(-Wall -Wextra -Wshadow)

# Add subdirectories for each module
add_subdirectory(01_Architecture_and_Foundations)
add_subdirectory(02_Core_Peripherals)
add_subdirectory(03_Communication_Protocols)
add_subdirectory(04_RTOS_and_Concurrency)
add_subdirectory(05_Advanced_System_Engineering)
add_subdirectory(06_Professional_Debugging_and_Validation)
