#ifndef PRACTICE_01_BOOTLOADER_H
#define PRACTICE_01_BOOTLOADER_H

#include <stdint.h>

/**
 * @brief Practice Set: Advanced System Engineering
 * 
 * Formal practice for Bootloader branching and Memory Protection.
 */

// 1. Function Pointers to Absolute Memory
void Practice_Bootloader_JumpToApp(uint32_t app_address);

// 2. Relocating the Vector Table
void Practice_Relocate_VTOR(uint32_t new_vector_table_address);

#endif // PRACTICE_01_BOOTLOADER_H
