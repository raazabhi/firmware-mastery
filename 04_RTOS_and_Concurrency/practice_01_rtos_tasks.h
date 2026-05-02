#ifndef PRACTICE_01_RTOS_TASKS_H
#define PRACTICE_01_RTOS_TASKS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Practice Set: RTOS and Concurrency
 * 
 * Formal practice for FreeRTOS-style task management and IPC.
 */

// Simulated FreeRTOS types
typedef void * TaskHandle_t;
typedef void * QueueHandle_t;
typedef void * SemaphoreHandle_t;
typedef void (*TaskFunction_t)(void *);

#define pdPASS 1
#define pdTRUE 1
#define pdFALSE 0

// 1. Task Creation
bool Practice_RTOS_CreateTask(TaskFunction_t taskCode, const char * const name, uint16_t stackDepth, void * const parameters, uint32_t priority);

// 2. Mutexes vs Semaphores
SemaphoreHandle_t Practice_RTOS_CreateMutex(void);

// 3. Queue Management
bool Practice_RTOS_SendToQueue(QueueHandle_t queue, const void * itemToQueue);

#endif // PRACTICE_01_RTOS_TASKS_H
