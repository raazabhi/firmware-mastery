#include "practice_01_rtos_tasks.h"
#include <stddef.h>

// Simulated FreeRTOS API
extern int xTaskCreate(TaskFunction_t, const char * const, uint16_t, void * const, uint32_t, TaskHandle_t *);
extern SemaphoreHandle_t xSemaphoreCreateMutex(void);
extern int xQueueSend(QueueHandle_t, const void * const, uint32_t);

// -----------------------------------------------------------------------------
// USE CASE 1: Task Creation
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * Unlike bare-metal super-loops, an RTOS requires you to explicitly define 
 * isolated threads (tasks), assign them memory (stack), and give them a priority.
 * 
 * THE HOW:
 * Call the RTOS creation API. ALWAYS check the return value to ensure you didn't 
 * run out of heap memory!
 *
 * 🐞 BEGINNER TO PRO INLINE DEBUGGING: "The Silent Stack Overflow"
 * Beginner: Variables inside the task start getting randomly corrupted. Spends 
 *           days trying to find a bad pointer.
 * Pro: Uses FreeRTOS `vApplicationStackOverflowHook()`. Realizes the task 
 *      simply ran out of RAM and overwrote adjacent memory.
 * RTOS Pro: Uses "Thread-Aware Debugging" in GDB/OpenOCD. Can pause the CPU 
 *           and see the individual Call Stacks and exact CPU registers for 
 *           every single sleeping task, not just the currently running one!
 */
bool Practice_RTOS_CreateTask(TaskFunction_t taskCode, const char * const name, uint16_t stackDepth, void * const parameters, uint32_t priority) {
    // Goal: Wrap xTaskCreate and return true if successful.
    
    // Reference Solution:
    // TaskHandle_t handle = NULL;
    // if (xTaskCreate(taskCode, name, stackDepth, parameters, priority, &handle) == pdPASS) {
    //     return true;
    // }
    // return false;
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return false;
}

// -----------------------------------------------------------------------------
// USE CASE 2: Mutex vs Semaphore (Priority Inversion)
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * A Binary Semaphore is just a flag. A Mutex has "Priority Inheritance". 
 * If a low-priority task holds a Mutex and a high-priority task wants it, 
 * the RTOS temporarily boosts the low-priority task so it finishes faster. 
 * This prevents a catastrophic bug called "Priority Inversion".
 * 
 * THE HOW:
 * Always use a Mutex for protecting shared resources (like an I2C bus).
 * Only use Semaphores for signalling events (like an ISR waking up a task).
 */
SemaphoreHandle_t Practice_RTOS_CreateMutex(void) {
    // Goal: Create and return a Mutex.
    
    // Reference Solution:
    // return xSemaphoreCreateMutex();
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return NULL;
}

// -----------------------------------------------------------------------------
// USE CASE 3: Queue Management
// -----------------------------------------------------------------------------
/*
 * THE WHY:
 * You cannot safely modify global variables from multiple tasks without locks. 
 * Instead, tasks should communicate by passing copies of data through thread-safe Queues.
 */
bool Practice_RTOS_SendToQueue(QueueHandle_t queue, const void * itemToQueue) {
    // Goal: Send an item to the queue with a maximum timeout of 100 ticks.
    
    // Reference Solution:
    // if (xQueueSend(queue, itemToQueue, 100) == pdTRUE) return true;
    // return false;
    
    // TODO: Write your implementation here
    /* FILL HERE */
    return false;
}
