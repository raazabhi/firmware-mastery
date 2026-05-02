#ifndef PRACTICE_03_DMA_H
#define PRACTICE_03_DMA_H

#include <stdint.h>

/**
 * @brief Practice Set: Direct Memory Access (DMA)
 * 
 * Formal practice for offloading data transfers from the CPU.
 */

// 1. DMA Initialization (Memory to Peripheral)
void Practice_DMA_Config(uint32_t src_address, uint32_t dest_address, uint16_t size);

#endif // PRACTICE_03_DMA_H
