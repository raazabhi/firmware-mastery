#ifndef PRACTICE_01_UART_BASICS_H
#define PRACTICE_01_UART_BASICS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Practice Set: UART Communication
 * 
 * Formal practice for Serial Communication fundamentals.
 */

typedef struct {
    uint32_t SR;   // Status Register
    uint32_t DR;   // Data Register
} UART_TypeDef;

extern UART_TypeDef UART1_Hardware;
extern UART_TypeDef *UART1;

// Hardware Flags
#define UART_SR_TXE   (1 << 7) // Transmit Data Register Empty
#define UART_SR_RXNE  (1 << 5) // Read Data Register Not Empty
#define UART_SR_ORE   (1 << 3) // Overrun Error

void Run_UART_Practice(void);

// 1. Polling Transmit
void Practice_UART_SendChar(char c);

// 2. Handling Overrun Errors
bool Practice_UART_CheckOverrun(void);

#endif // PRACTICE_01_UART_BASICS_H
