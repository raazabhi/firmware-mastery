#ifndef PRACTICE_01_HARDFAULTS_H
#define PRACTICE_01_HARDFAULTS_H

#include <stdint.h>

/**
 * @brief Practice Set: Professional Debugging
 * 
 * Formal practice for analyzing system crashes and HardFaults.
 */

// Simulated ARM Cortex Fault Registers
#define SCB_CFSR  (*((volatile uint32_t*)0xE000ED28)) // Configurable Fault Status Reg
#define SCB_HFSR  (*((volatile uint32_t*)0xE000ED2C)) // HardFault Status Reg

// CFSR Bits
#define CFSR_PRECISERR  (1 << 9)  // Precise data access error
#define CFSR_IMPRECISERR (1 << 10) // Imprecise data access error
#define CFSR_UNALIGNED  (1 << 24) // Unaligned access usage fault

// 1. Decoding a HardFault
void Practice_Debug_AnalyzeFault(void);

#endif // PRACTICE_01_HARDFAULTS_H
