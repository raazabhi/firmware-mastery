#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <stdint.h>

/**
 * @brief Senior Embedded Engineers never use magic numbers for bit manipulation.
 * Always define bit macros to ensure code readability and prevent typos.
 */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
 * @brief Example Hardware Register Abstraction
 * 
 * In a real MCU, these are defined in a device header (e.g., stm32f4xx.h).
 * The `volatile` keyword is critical. It tells the compiler that the value
 * at this memory address may change outside the current execution flow 
 * (e.g., by hardware or an interrupt), so the compiler must NEVER optimize 
 * away reads or writes to it.
 */
#define PERIPH_BASE           0x40000000UL
#define GPIOA_BASE            (PERIPH_BASE + 0x00000000UL)

// Simulated Register structure for a GPIO port
typedef struct {
    volatile uint32_t MODER;   // Mode register
    volatile uint32_t OTYPER;  // Output type register
    volatile uint32_t OSPEEDR; // Output speed register
    volatile uint32_t PUPDR;   // Pull-up/pull-down register
    volatile uint32_t IDR;     // Input data register
    volatile uint32_t ODR;     // Output data register
    volatile uint32_t BSRR;    // Bit set/reset register (Atomic operations)
} GPIO_TypeDef;

#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)

// Function Prototypes
void Init_Led_Pin(void);
void Toggle_Led_Atomic(void);
void Toggle_Led_NonAtomic(void);

#endif // BIT_MANIPULATION_H
