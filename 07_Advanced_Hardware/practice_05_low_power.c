#include "practice_05_low_power.h"

// -----------------------------------------------------------------------------
// USE CASE 1: Entering Sleep Mode (WFI)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * If your device runs on a coin cell battery, a standard `while(1)` loop will 
 * drain the battery in hours. 
 * 
 * THE HOW:
 * You must execute the Assembly instruction `WFI` (Wait For Interrupt). This 
 * physically stops the CPU clock, dropping power consumption from milliamperes 
 * down to microamperes. The CPU will wake up automatically when an interrupt fires.
 * 
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Debugger Drain"
 * Beginner: Writes the sleep code. Tests it while the ST-Link debugger is plugged 
 *           in via USB. Measures the current and sees it's drawing 10mA! 
 *           Concludes the sleep code doesn't work.
 * Pro: Knows that the JTAG/SWD Debug Hardware *forces* the core clock to stay 
 *      running so the debugger doesn't disconnect. 
 *      Fix: To truly test Low Power modes, you MUST physically unplug the debugger 
 *      and measure current with a specialized tool like a Nordic Power Profiler 
 *      or a Joulescope.
 */
void Practice_Power_EnterSleepMode(void) {
    // Goal: Describe or implement the WFI instruction (usually wrapped by CMSIS `__WFI();`)
    
    // Reference Solution:
    // __WFI(); // Halt the CPU clock until the next Interrupt
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
