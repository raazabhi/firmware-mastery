#ifndef PRACTICE_04_ANALOG_ADC_H
#define PRACTICE_04_ANALOG_ADC_H

#include <stdint.h>

/**
 * @brief Practice Set: Analog to Digital Converter (ADC)
 * 
 * Formal practice for sampling analog signals and noise filtering.
 */

// 1. Reading an ADC value
uint16_t Practice_ADC_ReadValue(void);

// 2. Simple Low-Pass Filter (Rolling Average)
uint16_t Practice_ADC_FilterNoise(uint16_t new_sample);

#endif // PRACTICE_04_ANALOG_ADC_H
