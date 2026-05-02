#include "i2c_driver.h"
#include <stddef.h>

// Mock function to represent getting a hardware millisecond tick
// In a real system, this might be `HAL_GetTick()` or `xTaskGetTickCount()`
extern uint32_t GetSysTickMs(void);

// Mock hardware registers
#define I2C_SR1_TXE  (1 << 7) // Transmit data register empty
#define I2C_SR1_RXNE (1 << 6) // Receive data register not empty
#define I2C_SR1_AF   (1 << 10) // Acknowledge failure (NACK)

I2C_Status_t I2C_Init(I2C_Handle_t *handle, uint32_t baudrate) {
    if (handle == NULL) return I2C_ERR_TIMEOUT;
    
    // Hardware specific init goes here...
    (void)baudrate; // Suppress unused parameter warning for mock

    handle->is_initialized = true;
    handle->timeout_ms = 100; // Default timeout 100ms
    
    return I2C_OK;
}

I2C_Status_t I2C_ReadRegisters(I2C_Handle_t *handle, uint8_t slave_address, uint8_t reg_address, uint8_t *buffer, uint16_t length) {
    if (!handle->is_initialized || buffer == NULL || length == 0) {
        return I2C_ERR_TIMEOUT; 
    }

    uint32_t start_time = GetSysTickMs();

    // 1. Send START condition and Slave Address (Write mode)
    // ... Hardware Specific ...

    // 2. Wait for ACK or handle NACK
    // CRITICAL: Notice the timeout check inside the while loop!
    // A junior engineer writes: `while (!(I2C->SR1 & I2C_SR1_TXE));` -> This loops forever if the hardware glitches.
    // A senior engineer writes:
    while (/* waiting for hardware flag */ 0) {
        if ((GetSysTickMs() - start_time) > handle->timeout_ms) {
            return I2C_ERR_TIMEOUT;
        }
        if (/* check for NACK flag */ 0) {
            return I2C_ERR_NACK;
        }
    }

    // 3. Send Register Address
    (void)reg_address; 
    
    // 4. Send REPEATED START condition and Slave Address (Read mode)
    (void)slave_address;

    // 5. Read data in a loop
    for (uint16_t i = 0; i < length; i++) {
        start_time = GetSysTickMs(); // Reset timeout for each byte

        // Wait for Receive Data Register Not Empty (RXNE)
        while (/* waiting for RXNE */ 0) {
             if ((GetSysTickMs() - start_time) > handle->timeout_ms) {
                 return I2C_ERR_TIMEOUT;
             }
        }
        
        // Read byte from hardware register
        // buffer[i] = I2C->DR; 
    }

    // 6. Generate STOP condition
    // ... Hardware Specific ...

    return I2C_OK;
}

I2C_Status_t I2C_RecoverBus(I2C_Handle_t *handle) {
    (void)handle;
    // 1. Reconfigure SCL and SDA as standard GPIO outputs
    // 2. Drive SCL high and low up to 9 times
    // 3. Check SDA state. If it goes high, the slave has released the bus.
    // 4. Generate a STOP condition (SDA low-to-high transition while SCL is high).
    // 5. Reinitialize I2C hardware.
    
    return I2C_OK;
}
