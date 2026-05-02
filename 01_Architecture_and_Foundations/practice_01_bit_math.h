#ifndef PRACTICE_01_BIT_MATH_H
#define PRACTICE_01_BIT_MATH_H

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Practice Set 1: Bit Manipulation Mastery
 * 
 * This module formalizes the core bit manipulation concepts required for firmware engineering.
 * Each function represents a real-world use case.
 */

// Core Macros (Reference)
#define IS_BIT_SET(val, mask) ((val) & (mask))
#define SET_BIT(val, mask)    ((val) | (mask))
#define CLEAR_BIT(val, mask)  ((val) & ~(mask))
#define TOGGLE_BIT(val, mask) ((val) ^ (mask))

// --- Practice Functions ---
void Run_Bit_Math_Practice(void);

// 1. Setting multiple bits safely
uint16_t Practice_Set_Multiple_Bits(uint16_t current_val);

// 2. Checking single bits
void Practice_Check_Button_State(uint32_t port_val);

// 3. Extracting multi-bit fields
uint8_t Practice_Extract_Error_Code(uint32_t status_reg);

// 4. Checking strict multiple flags
void Practice_Check_Uart_Flags(uint32_t flag_reg);

#endif // PRACTICE_01_BIT_MATH_H
