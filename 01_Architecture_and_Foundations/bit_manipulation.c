#include "bit_manipulation.h"

// Define specific bits for Pin 5
#define GPIO_PIN_5                 (1 << 5)
#define GPIO_MODER_MODER5_Pos      (10U)
#define GPIO_MODER_MODER5_Msk      (0x3UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_OUTPUT   (0x1UL << GPIO_MODER_MODER5_Pos)

/**
 * @brief Initializes GPIO Pin 5 as an output.
 */
void Init_Led_Pin(void) {
    // 1. NON-ATOMIC operation (Read-Modify-Write)
    // If an interrupt occurs here and modifies GPIOA->MODER, those changes 
    // will be overwritten when this function resumes.
    MODIFY_REG(GPIOA->MODER, GPIO_MODER_MODER5_Msk, GPIO_MODER_MODER5_OUTPUT);
}

/**
 * @brief Toggles the LED using a Read-Modify-Write (RMW) approach.
 * 
 * WARNING: This is non-atomic. If an interrupt occurs between the read and the write
 * and modifies the ODR, the interrupt's modification will be lost.
 * "Heisenbugs" are born here.
 */
void Toggle_Led_NonAtomic(void) {
    GPIOA->ODR ^= GPIO_PIN_5; 
}

/**
 * @brief Toggles the LED using an Atomic Register (BSRR).
 * 
 * Senior approach: Use hardware-provided atomic set/reset registers.
 * Writing to BSRR takes 1 clock cycle and cannot be interrupted.
 * No Read-Modify-Write is required.
 */
void Toggle_Led_Atomic(void) {
    // If the pin is currently high, reset it. Otherwise, set it.
    if (READ_BIT(GPIOA->ODR, GPIO_PIN_5)) {
        // Reset Pin 5 (Usually upper 16 bits in BSRR)
        GPIOA->BSRR = (uint32_t)GPIO_PIN_5 << 16;
    } else {
        // Set Pin 5 (Lower 16 bits in BSRR)
        GPIOA->BSRR = (uint32_t)GPIO_PIN_5;
    }
}
