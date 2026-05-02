#include "practice_01_gpio_basics.h"

// Define our simulated hardware in memory
GPIO_TypeDef GPIOA_Hardware = {0}; 
GPIO_TypeDef *GPIOA = &GPIOA_Hardware;

// -----------------------------------------------------------------------------
// USE CASE 1: GPIO Initialization (Setting a specific Pin Mode safely)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Microcontroller pins are highly multiplexed (they can be inputs, outputs, 
 * UART TX lines, ADC inputs, etc.). Before you can use a pin, you MUST tell 
 * the hardware what you want it to do by writing to the "Mode Register" (MODER).
 * 
 * THE HOW:
 * Unlike a simple 1-bit on/off switch, modes usually require a "Multi-bit Field" 
 * (typically 2 bits per pin). Because it's a multi-bit field, you MUST clear 
 * the old value before setting the new one.
 * 
 * SENIOR TIP:
 * If you skip the "Clear" step and just OR the new mode in, you will create a 
 * bug that only happens if the pin was previously initialized to something else. 
 * Those bugs are notoriously hard to find!
 *
 * 🐞 BEGINNER TO PRO HARDWARE DEBUGGING: "The Phantom Output"
 * Beginner: Checks the `ODR` register in the debugger, sees it is '1', and 
 *           assumes the LED is on. But it's not!
 * Pro: Understands that the *Debugger* only sees the CPU's intent, not reality.
 *      Hooks up a Logic Analyzer to the physical pin. If the Logic Analyzer reads 
 *      '0' but the debugger reads '1', it means the pin is configured as an Input 
 *      or it is physically shorted to Ground.
 * Hardware Pro: Hooks up an Oscilloscope. Sees the voltage is stuck at 1.2V 
 *      instead of 3.3V. Realizes they are trying to drive an LED without a 
 *      current-limiting resistor, pulling the entire MCU rail down!
 */
void Practice_Init_GPIO_Pin(void) {
    // Goal: Safely set Pin 5's mode bits to '01' (Output) in GPIOA->MODER.
    // In our MCU datasheet, Pin 5 uses bits 10,11.
    // Remember the Golden Rule: Clear the field first, then set the new value!
    
    // Reference Solution:
    // uint32_t clear_mask = ~(0b11 << 10);
    // GPIOA->MODER &= clear_mask;
    // GPIOA->MODER |= (0b01 << 10);
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// USE CASE 2: GPIO Data Toggling (Blinking an LED)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Banging out a physical square wave (like blinking an LED, or generating a 
 * software clock line for SPI) requires rapidly flipping a pin between High (1) 
 * and Low (0).
 * 
 * THE HOW:
 * You *could* check the state first, then set or clear it:
 * `if (ODR & (1 << 5)) { ODR &= ~(1 << 5); } else { ODR |= (1 << 5); }`
 * 
 * But the Bitwise XOR (^) operator flips the bit in a single instruction!
 * `val ^ 1` flips the bit. `val ^ 0` leaves it alone.
 */
void Practice_Toggle_GPIO_Pin(void) {
    // Goal: Write a single line of code that toggles Bit 5 in GPIOA->ODR.
    
    // Reference Solution:
    // GPIOA->ODR ^= (1 << 5);
    
    // TODO: Write your implementation here
    /* FILL HERE */
}

// -----------------------------------------------------------------------------
// RUNNER
// -----------------------------------------------------------------------------
void Run_GPIO_Practice(void) {
    printf("\n--- Running Formal GPIO Practice ---\n");
    // Call your functions here to test!
}
