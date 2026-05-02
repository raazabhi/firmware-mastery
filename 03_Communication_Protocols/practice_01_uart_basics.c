#include "practice_01_uart_basics.h"

UART_TypeDef UART1_Hardware = {0}; 
UART_TypeDef *UART1 = &UART1_Hardware;

// -----------------------------------------------------------------------------
// USE CASE 1: Polling Transmit
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You need to send a character to a PC terminal for debugging (printf). 
 * 
 * THE HOW:
 * You cannot just shove bytes into the Data Register (DR) as fast as the CPU 
 * runs. The CPU is millions of times faster than a 115200 baud UART.
 * You MUST wait for the hardware to tell you the Transmit Register is Empty 
 * (TXE flag) before writing the next byte.
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Silent Terminal"
 * Beginner: Stares at a blank PuTTY terminal. Adds random delays to code.
 * Pro: Uses SWO (Serial Wire Output) ITM Tracing. Modern ARM debuggers can 
 *      transmit `printf` over the SWDIO debug cable natively! It takes 0% CPU 
 *      time and doesn't require setting up a UART at all.
 * Hardware Pro: Hooks a Logic Analyzer to the TX pin. Decodes the baud rate. 
 *      If the analyzer sees `0x41` ('A') but PuTTY sees `0xFF`, it proves the 
 *      PC and the MCU have mismatched baud rates!
 */
void Practice_UART_SendChar(char c) {
    // Goal: Wait for TXE flag to be 1, then write 'c' into UART1->DR.
    // NOTE: In a real system, use a timeout here to prevent infinite loops!
    
    // Reference Solution:
    // while (!(UART1->SR & UART_SR_TXE)) { /* Wait */ }
    // UART1->DR = c;
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// USE CASE 2: Handling Overrun Errors
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * If a new byte arrives on the physical wire before you've read the previous 
 * byte out of the DR, the hardware raises an Overrun Error (ORE). If you don't 
 * clear it, the UART peripheral permanently locks up and stops receiving.
 * 
 * THE HOW:
 * Check the SR for the ORE bit. If it's set, read the DR to flush it and clear 
 * the error state.
 */
bool Practice_UART_CheckOverrun(void) {
    // Goal: Check if ORE is set. If true, clear it by reading DR into a dummy variable.
    
    // Reference Solution:
    // if (UART1->SR & UART_SR_ORE) {
    //     volatile uint32_t dummy = UART1->DR; // Reading flushes the error
    //     return true;
    // }
    // return false;
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return false;
}
