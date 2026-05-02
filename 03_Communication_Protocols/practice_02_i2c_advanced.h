#ifndef PRACTICE_02_I2C_ADVANCED_H
#define PRACTICE_02_I2C_ADVANCED_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Practice Set: Advanced I2C Driver
 * 
 * Formal practice for synchronous serial communication and bus recovery.
 */

typedef enum {
    I2C_OK = 0,
    I2C_ERR_NACK,
    I2C_ERR_TIMEOUT,
    I2C_ERR_BUS_HANG
} I2C_Status_t;

typedef struct {
    uint8_t   bus_id;
    uint32_t  timeout_ms;
    bool      is_initialized;
} I2C_Handle_t;

// 1. Safe Hardware Polling (Avoiding Infinite Loops)
I2C_Status_t Practice_I2C_WaitForFlag(uint32_t start_time_ms, uint32_t timeout_ms);

// 2. Bus Recovery Bit-Banging
I2C_Status_t Practice_I2C_RecoverBus(I2C_Handle_t *handle);

#endif // PRACTICE_02_I2C_ADVANCED_H
