#ifndef PRACTICE_02_TIMERS_PWM_H
#define PRACTICE_02_TIMERS_PWM_H

#include <stdint.h>

/**
 * @brief Practice Set: Hardware Timers and PWM
 * 
 * Formal practice for generating precise frequencies and duty cycles.
 */

// 1. Timer Frequency (Prescaler and ARR)
uint32_t Practice_Timer_CalculateFrequency(uint32_t core_clock, uint16_t prescaler, uint16_t arr);

// 2. PWM Duty Cycle
void Practice_Timer_SetPWMDutyCycle(uint16_t arr, uint8_t duty_cycle_percent);

#endif // PRACTICE_02_TIMERS_PWM_H
