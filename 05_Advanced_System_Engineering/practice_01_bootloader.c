#include "practice_01_bootloader.h"

// Simulated ARM Cortex core registers
#define SCB_VTOR  (*((volatile uint32_t*)0xE000ED08))

// -----------------------------------------------------------------------------
// USE CASE 1: Function Pointers to Absolute Memory (Bootloader Jump)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * A Bootloader is just a tiny C program. When it's done verifying the firmware, 
 * it needs to literally tell the CPU: "Stop executing here, and jump to memory 
 * address 0x08040000".
 * 
 * THE HOW:
 * In C, we cast a raw integer address into a "Function Pointer", and then 
 * "call" that pointer. This forces the CPU's Program Counter (PC) to that address.
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Pre-Main Crash"
 * Beginner: Adds `printf` inside `main()`. Nothing prints. Board is a brick.
 * Pro: Realizes the crash happened in the Bootloader or during C-runtime 
 *      initialization *before* main() was even called.
 * Hardcore Pro: Uses the IDE's "Instruction Stepping" mode to step through the 
 *      raw Assembly in `startup.s`. Verifies that the CPU successfully loads 
 *      the Stack Pointer (SP) from the first address of the Vector Table before 
 *      jumping to the Reset_Handler.
 */
void Practice_Bootloader_JumpToApp(uint32_t app_address) {
    // Goal: Cast `app_address` to a void function pointer that takes no arguments, 
    // and then execute it.
    
    // Reference Solution:
    // void (*app_reset_handler)(void) = (void (*)(void))app_address;
    // app_reset_handler(); // JUMPS!
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// USE CASE 2: Relocating the Vector Table (VTOR)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * When you jump from the Bootloader to the Main App, the Main App has its own 
 * set of Interrupts (its own Vector Table). If you don't tell the CPU where 
 * the new table is, the first interrupt will crash the system.
 * 
 * THE HOW:
 * The ARM Cortex-M has a System Control Block register called VTOR 
 * (Vector Table Offset Register). You simply write the new address into it.
 */
void Practice_Relocate_VTOR(uint32_t new_vector_table_address) {
    // Goal: Safely write `new_vector_table_address` into the SCB_VTOR register.
    
    // Reference Solution:
    // SCB_VTOR = new_vector_table_address;
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
