/*
 * freertos_hooks.c
 *
 *  Created on: 15 Nov 2026
 *      Author: monish
 */


#include "FreeRTOS.h"
#include "task.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;          /* inspect in the debugger to see which task overflowed */
    __asm volatile("cpsid i");
    for (;;);
}

void vApplicationMallocFailedHook(void)
{
    __asm volatile("cpsid i");
    for (;;);
}
