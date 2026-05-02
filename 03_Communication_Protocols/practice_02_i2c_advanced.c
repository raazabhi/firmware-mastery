#include "practice_02_i2c_advanced.h"

extern uint32_t GetSysTickMs(void); // Simulated system timer

// -----------------------------------------------------------------------------
// USE CASE 1: Safe Hardware Polling
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Junior engineers write: `while (!(I2C->SR & TXE));`
 * If the hardware glitches and the flag never sets, the entire product freezes forever.
 * 
 * THE HOW:
 * Senior engineers ALWAYS include a timeout in any hardware while-loop.
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The I2C Deadlock"
 * Beginner: Steps over the `while` loop with an IDE debugger (F6). Suddenly, the 
 *           I2C bus stops working entirely until the board is physically rebooted.
 * Pro: Knows that the hardware I2C clock *keeps ticking* while the debugger is 
 *      paused! This causes the MCU to miss the ACK bit, throwing the hardware 
 *      state machine into an unrecoverable state.
 *      Fix: Never step *through* an I2C transaction. Set a breakpoint *after* 
 *      the transaction completes.
 */
I2C_Status_t Practice_I2C_WaitForFlag(uint32_t start_time_ms, uint32_t timeout_ms) {
    // Goal: Loop until the simulated flag is set. If `GetSysTickMs() - start_time_ms` 
    // exceeds `timeout_ms`, return I2C_ERR_TIMEOUT immediately.
    
    // Reference Solution:
    // while (/* checking hardware flag */ 0) {
    //     if ((GetSysTickMs() - start_time_ms) > timeout_ms) {
    //         return I2C_ERR_TIMEOUT;
    //     }
    // }
    // return I2C_OK;
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return I2C_OK;
}

// -----------------------------------------------------------------------------
// USE CASE 2: The Dreaded "Bus Hang"
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * If a master resets in the middle of reading a byte, the slave might be stuck 
 * holding the SDA line LOW (waiting for the next clock pulse). The bus is hung.
 * 
 * THE HOW:
 * You must temporarily disable the hardware I2C peripheral, configure the SCL 
 * pin as a standard output GPIO, and manually toggle it up to 9 times until the 
 * slave releases SDA.
 */
I2C_Status_t Practice_I2C_RecoverBus(I2C_Handle_t *handle) {
    (void)handle;
    // Goal: Describe or implement the 9-clock recovery sequence.
    
    // Reference Concept:
    // 1. Reconfigure SCL as Output, SDA as Input.
    // 2. Loop 9 times: drive SCL high, delay, drive SCL low, delay.
    // 3. If SDA goes high, break early.
    // 4. Generate STOP condition.
    
    // TODO: Write your implementation/notes here
    /* FILL HERE */
    return I2C_OK;
}
