#include "practice_04_analog_adc.h"

// -----------------------------------------------------------------------------
// USE CASE 1: Reading Analog Voltages
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You need to read a temperature sensor or a battery voltage. The real world 
 * is analog (0V to 3.3V), but the CPU only understands digital numbers.
 * 
 * THE HOW:
 * A 12-bit ADC converts an analog voltage into a number from 0 to 4095.
 * 
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Jittery Sensor"
 * Beginner: Reads the ADC in a software `while` loop. The values bounce around 
 *           erratically. Thinks the sensor is broken.
 * Pro: Knows that calling ADC_Start() in software introduces "CPU Jitter". 
 *      Instead, they link a Hardware Timer to trigger the ADC natively at exactly 
 *      10kHz. The hardware does it perfectly on time, eliminating sampling noise.
 */
uint16_t Practice_ADC_ReadValue(void) {
    // Goal: Read the data from the simulated ADC Data Register (DR).
    
    // Reference Solution:
    // return (uint16_t)(ADC1->DR & 0x0FFF); // Mask 12 bits
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return 0;
}

// -----------------------------------------------------------------------------
// USE CASE 2: Filtering Analog Noise
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Even with perfect hardware, real wires pick up electromagnetic noise. 
 * If you use raw ADC data to control a motor, the motor will shake violently.
 * 
 * THE HOW:
 * Implement a simple DSP (Digital Signal Processing) filter. The easiest is 
 * an Exponential Moving Average (EMA) or a Rolling Average.
 */
uint16_t Practice_ADC_FilterNoise(uint16_t new_sample) {
    // Goal: Maintain a static state of the average. 
    // Return (previous_avg * 0.9) + (new_sample * 0.1) using integer math!
    
    // Reference Solution:
    // static uint32_t current_avg = 0; // Scaled to avoid floats
    // current_avg = ((current_avg * 9) + (new_sample * 10)) / 10;
    // return (uint16_t)(current_avg / 10);
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return new_sample;
}
