#include "practice_01_interrupts_nvic.h"
#include <stdio.h>

// -----------------------------------------------------------------------------
// USE CASE 1: The "Volatile" Shared Variable
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * When an Interrupt Service Routine (ISR) fires, it changes data outside the 
 * normal flow of your main() while loop. If you don't tell the compiler this, 
 * the compiler will optimize out your variable checks, assuming they never change!
 * 
 * THE HOW:
 * Any global variable modified in an ISR and read in main() MUST be declared 
 * as `volatile`.
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Infinite Loop"
 * Beginner: Has a `while(!flag);` loop in main(). The ISR sets `flag = 1`. 
 *           The code works in Debug mode (-O0) but freezes completely in 
 *           Release mode (-O3). Spends a week thinking the compiler is broken.
 * Pro: Looks at the disassembly. Sees the compiler cached `flag` into a CPU 
 *      register and never actually checked the RAM address again. Adds `volatile`.
 */
volatile bool uart_rx_complete = false;

void Practice_Interrupt_ReadFlag(void) {
    // Goal: Write a while loop that waits for uart_rx_complete to become true.
    
    // Reference Solution:
    // while(!uart_rx_complete) { /* Wait */ }
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// USE CASE 2: NVIC Preemption Priorities
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * What happens if a 1ms Timer Interrupt fires *while* you are inside a slow 
 * UART Interrupt? Does it wait, or does it interrupt the interrupt?
 * 
 * THE HOW:
 * The ARM NVIC (Nested Vector Interrupt Controller) uses "Preemption Priorities".
 * Lower numbers = Higher Priority. A priority 1 interrupt will preempt a priority 2.
 * 
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Priority Inversion Crash"
 * Beginner: Uses an RTOS queue inside an ISR. The RTOS asserts and halts the CPU.
 * Pro: Knows that FreeRTOS requires interrupts that use FreeRTOS APIs to have a 
 *      priority numerically *higher* (logically lower) than configMAX_SYSCALL_INTERRUPT_PRIORITY.
 *      Fix: Changes the NVIC priority register to a safe level before enabling the IRQ.
 */
void Practice_Interrupt_SetPriority(uint8_t irq_number, uint8_t priority) {
    // Goal: Describe how you would set an NVIC priority (e.g., using CMSIS NVIC_SetPriority).
    (void)irq_number;
    (void)priority;
    
    // Reference Solution:
    // NVIC_SetPriority(irq_number, priority);
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
