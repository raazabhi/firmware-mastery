#include "practice_01_bit_math.h"

// -----------------------------------------------------------------------------
// USE CASE 1: Setting Multiple Bits
// -----------------------------------------------------------------------------
/*
 * THE WHY: 
 * Often you need to configure multiple pins at once (e.g., turning on multiple 
 * LEDs on the same port, or setting multiple configuration flags).
 * 
 * THE HOW:
 * We use the Bitwise OR (|) operator. 
 * `val | 0` leaves the bit unchanged.
 * `val | 1` forces the bit to 1.
 * 
 * SENIOR TIP: 
 * Never use "Magic Numbers" (like `current_val |= 5;`). Always use explicit 
 * bit shifts like `(1 << 2) | (1 << 0)`. The compiler calculates this at 
 * compile-time, so it costs zero CPU cycles but saves hours of debugging!
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Phantom Bit Flip"
 * Beginner: Uses `printf` to print the value of `current_val` every loop to see when it changes.
 * Pro: Uses a Hardware "Data Watchpoint" (DWT).
 *      In your IDE (Eclipse/CubeIDE), right-click `current_val` -> Add Watchpoint -> Type: Write.
 *      The CPU hardware will literally pause execution the exact nanosecond that 
 *      ANY rogue code (or wild pointer) attempts to change this bit, instantly 
 *      showing you the culprit in the Call Stack.
 */
uint16_t Practice_Set_Multiple_Bits(uint16_t current_val) {
    // Goal: Turn ON Bit 4, Bit 2, and Bit 0 without changing other bits.
    
    // Reference Solution:
    // current_val |= (1 << 4);
    // current_val |= (1 << 2) | (1 << 0);
    
    // TODO: Write your implementation here
    /* FILL HERE */
    
    return current_val;
}

// -----------------------------------------------------------------------------
// USE CASE 2: Single Bit Checking 
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You need to read the state of a single physical pin, like checking if a 
 * button is currently pressed or if a sensor is ready.
 * 
 * THE HOW:
 * We use the Bitwise AND (&) operator to create a "Mask". 
 * A Mask acts like a filter: `val & 0` forces the result to 0. `val & 1` lets 
 * the original value pass through.
 * 
 * SENIOR CAVEAT:
 * Junior engineers often do `if (val >> 13)`. If *any* higher bit (like Bit 14) 
 * is also 1, this will still evaluate to true! You must explicitly mask it.
 */
void Practice_Check_Button_State(uint32_t port_val) {
    // Goal: Write an IF statement to safely check if Bit 13 is set (1).
    
    // Reference Solution:
    // if (port_val & (1 << 13)) { /* button is pressed */ }
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// USE CASE 3: Extracting Multi-bit Fields
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Hardware registers pack multiple pieces of data into a single 32-bit word. 
 * For example, an ADC status register might hold a 4-bit error code tucked 
 * away in the middle of the register. You need to read *only* that error code.
 * 
 * THE HOW:
 * 1. Shift the data to the right so the field starts at Bit 0.
 * 2. AND it with a mask that has 1s covering exactly the width of your field.
 *    (e.g., A 4-bit field needs a mask of 0b1111, which is 0x0F in Hex).
 */
uint8_t Practice_Extract_Error_Code(uint32_t status_reg) {
    // Goal: Extract a 4-bit error code located at Bits 12, 13, 14, and 15.
    
    // Reference Solution:
    // uint8_t error_code = (status_reg >> 12) & 0x0F;
    
    uint8_t error_code = 0; // Replace this
    
    // TODO: Write your implementation here
    /* FILL HERE */
    
    return error_code;
}

// -----------------------------------------------------------------------------
// USE CASE 4: Strict Multiple Flag Checking 
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * In complex protocols like UART or DMA, you often need to wait until *both* 
 * the Transmit (Tx) and Receive (Rx) operations are complete before proceeding.
 * 
 * THE HOW:
 * You create a target mask containing both flags. You AND the hardware register 
 * with that mask, and check if the result *exactly equals* your target mask.
 * This guarantees both bits are 1, regardless of what other bits are doing.
 */
void Practice_Check_Uart_Flags(uint32_t flag_reg) {
    // Goal: Evaluate to TRUE *only* if BOTH Bit 0 and Bit 1 are exactly 1.
    
    // Reference Solution:
    // uint32_t target_flags = (1 << 0) | (1 << 1);
    // if ( (flag_reg & target_flags) == target_flags ) { /* both complete */ }
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// RUNNER
// -----------------------------------------------------------------------------
void Run_Bit_Math_Practice(void) {
    printf("\n--- Running Formal Bit Math Practice ---\n");
    // You can call your functions here to test them!
}
