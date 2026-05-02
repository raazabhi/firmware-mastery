#include "practice_03_dma.h"

// -----------------------------------------------------------------------------
// USE CASE 1: CPU Offloading (DMA Transfers)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You have an SPI Display that requires 10,000 bytes of image data to be sent.
 * If you use the CPU in a `while` loop, the entire OS freezes while it sends 
 * data. 
 * 
 * THE HOW:
 * You give the DMA controller a Source Address (RAM), a Destination Address 
 * (SPI Data Register), and a length. You tell it "Go", and the DMA hardware 
 * pipes the data automatically while the CPU goes to sleep or runs other tasks!
 * 
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Stale Cache Illusion"
 * Beginner: Uses DMA to receive data into an array. Prints the array. It's empty.
 *           Assumes DMA is broken.
 * Pro: Knows about "Cache Coherency". On fast CPUs (Cortex-M7), the CPU reads 
 *      data from its high-speed L1 Data Cache, NOT the actual RAM. The DMA 
 *      writes directly to the RAM. 
 *      Fix: Uses `SCB_InvalidateDCache_by_Addr()` to force the CPU to fetch 
 *      fresh data from the RAM before reading the array!
 */
void Practice_DMA_Config(uint32_t src_address, uint32_t dest_address, uint16_t size) {
    // Goal: Describe the 3 mandatory configuration steps for a DMA Stream.
    (void)src_address;
    (void)dest_address;
    (void)size;
    
    // Reference Solution:
    // DMA1_Stream0->PAR = dest_address;  // Peripheral Address
    // DMA1_Stream0->M0AR = src_address;  // Memory Address
    // DMA1_Stream0->NDTR = size;         // Number of Data items to Transfer
    // DMA1_Stream0->CR |= (1 << 0);      // Enable DMA Stream
    
    // TODO: Write your implementation here
    /* FILL HERE */
}
