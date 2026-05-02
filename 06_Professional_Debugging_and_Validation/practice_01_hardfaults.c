#include "practice_01_hardfaults.h"
#include <stdio.h>

// -----------------------------------------------------------------------------
// USE CASE 1: Decoding the Configurable Fault Status Register (CFSR)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * When your C code tries to read from an invalid pointer (like NULL), the CPU 
 * instantly crashes into the "HardFault Handler" infinite loop. 
 * If you don't know how to decode *why* you are in that loop, you are flying blind.
 * 
 * THE HOW:
 * The ARM core has a register called CFSR. By checking specific bits in this 
 * register, you can figure out if you divided by zero, accessed bad memory, 
 * or executed an invalid assembly instruction.
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Link Register Trick"
 * Beginner: Sees the CPU is stuck in `HardFault_Handler`. Has absolutely no 
 *           idea which line of C code caused it. Guesses by commenting out code.
 * Pro: Pauses the debugger. Opens the CPU Registers view. Looks at the `LR` 
 *      (Link Register) and the `PC` (Program Counter) pushed onto the Stack.
 * Hardcore Pro: Writes an Assembly wrapper around the HardFault Handler that 
 *      automatically extracts the Stack Pointer, reads the exact PC that caused 
 *      the fault, and prints the C filename and line number to the SWO trace!
 */
void Practice_Debug_AnalyzeFault(void) {
    // Goal: Check the simulated SCB_CFSR register.
    // If it's a PRECISERR, print "Data Access Violation!".
    // If it's an UNALIGNED, print "Unaligned Memory Access!".
    
    // Reference Solution:
    // if (SCB_CFSR & CFSR_PRECISERR) {
    //     printf("Data Access Violation!\n");
    // }
    // if (SCB_CFSR & CFSR_UNALIGNED) {
    //     printf("Unaligned Memory Access!\n");
    // }
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
