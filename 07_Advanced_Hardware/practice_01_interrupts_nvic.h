#ifndef PRACTICE_01_INTERRUPTS_NVIC_H
#define PRACTICE_01_INTERRUPTS_NVIC_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Practice Set: Hardware Interrupts & NVIC
 * 
 * Formal practice for managing preemption and safe ISRs.
 */

// 1. Safe ISR Variable Sharing
void Practice_Interrupt_ReadFlag(void);

// 2. NVIC Priority Configuration
void Practice_Interrupt_SetPriority(uint8_t irq_number, uint8_t priority);

#endif // PRACTICE_01_INTERRUPTS_NVIC_H
