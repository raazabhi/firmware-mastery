#ifndef PRACTICE_01_GPIO_BASICS_H
#define PRACTICE_01_GPIO_BASICS_H

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Practice Set 2: Memory-Mapped IO (Core Peripherals)
 * 
 * This module formalizes how bits interact with physical hardware registers.
 */

// Simulated Hardware Register Block (Typical ARM Cortex layout)
typedef struct {
    uint32_t MODER;  // Mode Register
    uint32_t IDR;    // Input Data Register
    uint32_t ODR;    // Output Data Register
} GPIO_TypeDef;

// Expose our simulated hardware globally for the practice functions
extern GPIO_TypeDef GPIOA_Hardware;
extern GPIO_TypeDef *GPIOA;

// --- Practice Functions ---
void Run_GPIO_Practice(void);

// 1. Initializing a Pin safely
void Practice_Init_GPIO_Pin(void);

// 2. Toggling a Pin (Blinking an LED)
void Practice_Toggle_GPIO_Pin(void);

#endif // PRACTICE_01_GPIO_BASICS_H
