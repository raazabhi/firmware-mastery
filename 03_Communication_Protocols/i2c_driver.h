#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief I2C Status return codes.
 * Senior engineers never return `void` for hardware interactions.
 */
typedef enum {
    I2C_OK = 0,
    I2C_ERR_NACK,
    I2C_ERR_TIMEOUT,
    I2C_ERR_BUS_HANG,
    I2C_ERR_ARBITRATION_LOST
} I2C_Status_t;

/**
 * @brief I2C Driver handle structure.
 * This object-oriented approach in C allows supporting multiple I2C buses (e.g., I2C1, I2C2).
 */
typedef struct {
    uint8_t   bus_id;           // Identifier for hardware bus (e.g., 1 for I2C1)
    uint32_t  timeout_ms;       // Critical: max time to wait for a transaction
    bool      is_initialized;   // State flag
} I2C_Handle_t;

// --- Function Prototypes ---

/**
 * @brief Initializes the I2C peripheral hardware.
 */
I2C_Status_t I2C_Init(I2C_Handle_t *handle, uint32_t baudrate);

/**
 * @brief Reads data from an I2C slave.
 * 
 * @param handle The I2C bus handle.
 * @param slave_address The 7-bit slave address.
 * @param reg_address The internal register address to read from.
 * @param buffer Pointer to the memory where read data will be stored.
 * @param length Number of bytes to read.
 * @return I2C_Status_t indicating success or specific failure reason.
 */
I2C_Status_t I2C_ReadRegisters(I2C_Handle_t *handle, uint8_t slave_address, uint8_t reg_address, uint8_t *buffer, uint16_t length);

/**
 * @brief Recovers a locked I2C bus by bit-banging SCL.
 * 
 * If a slave gets stuck holding SDA low, this function manually clocks SCL until SDA is released.
 */
I2C_Status_t I2C_RecoverBus(I2C_Handle_t *handle);

#endif // I2C_DRIVER_H
