#include "practice_02_timers_pwm.h"

// -----------------------------------------------------------------------------
// USE CASE 1: Calculating Timer Frequencies
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You need to trigger an ADC exactly 1,000 times a second (1kHz). Software 
 * delays are highly inaccurate due to interrupts. Hardware timers are perfect.
 * 
 * THE HOW:
 * Timer Freq = Core_Clock / ((Prescaler + 1) * (ARR + 1))
 * (The +1 is because registers count from 0).
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Off-By-One Jitter"
 * Beginner: Uses `Prescaler = 10` instead of `9` to divide by 10. The frequency 
 *           is slightly off, causing audio glitches or UART framing errors.
 * Pro: Always remembers the `+1` in timer hardware math.
 * Hardware Pro: Hooks a logic analyzer to a GPIO toggled by the timer interrupt 
 *      to measure the absolute physical period (e.g., exactly 1.000ms).
 */
uint32_t Practice_Timer_CalculateFrequency(uint32_t core_clock, uint16_t prescaler, uint16_t arr) {
    // Goal: Implement the formula to return the final frequency.
    
    // Reference Solution:
    // return core_clock / ((prescaler + 1) * (arr + 1));
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return 0;
}

// -----------------------------------------------------------------------------
// USE CASE 2: PWM Duty Cycle Configuration
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You want to dim an LED to exactly 50% brightness, or drive a servo motor 
 * to a specific angle.
 * 
 * THE HOW:
 * You write a value into the Timer's Capture/Compare Register (CCR). 
 * If ARR = 1000, and CCR = 500, the pin stays HIGH for 500 ticks, and LOW for 
 * the remaining 500 ticks. (50% Duty Cycle).
 * 
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Inverted PWM"
 * Beginner: Sets 10% duty cycle, but the motor spins at 90% speed.
 * Pro: Opens the IDE Debugger and checks the Timer `CCMR` (Capture/Compare Mode Reg). 
 *      Realizes they selected "PWM Mode 2" instead of "PWM Mode 1", which inverts 
 *      the active logic!
 */
void Practice_Timer_SetPWMDutyCycle(uint16_t arr, uint8_t duty_cycle_percent) {
    // Goal: Calculate the CCR value based on the ARR and desired duty cycle %.
    
    // Reference Solution:
    // uint16_t ccr_value = (arr * duty_cycle_percent) / 100;
    // TIMER->CCR1 = ccr_value;
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
