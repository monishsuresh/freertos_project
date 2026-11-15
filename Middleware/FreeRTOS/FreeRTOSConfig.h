/*
 * FreeRTOSConfig.h
 *
 *  Created on: 15 Nov 2026
 *      Author: monish
 */

#ifndef FREERTOS_FREERTOSCONFIG_H_
#define FREERTOS_FREERTOSCONFIG_H_

#include <stdint.h>

/* ---------- Scheduler ---------- */
#define configUSE_PREEMPTION                    1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configCPU_CLOCK_HZ                      16000000UL   /* HSI default, change after PLL setup */
#define configTICK_RATE_HZ                      1000         /* 1 tick = 1 ms */
#define configMAX_PRIORITIES                    5
#define configMINIMAL_STACK_SIZE                128          /* words, not bytes */
#define configMAX_TASK_NAME_LEN                 16
#define configTICK_TYPE_WIDTH_IN_BITS           TICK_TYPE_WIDTH_32_BITS
#define configIDLE_SHOULD_YIELD                 1

/* ---------- Memory ---------- */
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configSUPPORT_STATIC_ALLOCATION         0
#define configTOTAL_HEAP_SIZE                   (16 * 1024)

/* ---------- Hooks ---------- */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCHECK_FOR_STACK_OVERFLOW          2
#define configUSE_MALLOC_FAILED_HOOK            1

/* ---------- Features ---------- */
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             0
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_TASK_NOTIFICATIONS            1
#define configUSE_EVENT_GROUPS                  1
#define configUSE_STREAM_BUFFERS                1
#define configQUEUE_REGISTRY_SIZE               8

/* ---------- Software timers ---------- */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            256

/* ---------- Stats (for StatsTask later) ---------- */
#define configUSE_TRACE_FACILITY                1
#define configGENERATE_RUN_TIME_STATS           0

/* ---------- Cortex-M interrupt priorities (STM32: 4 bits) ---------- */
#define configPRIO_BITS                                 4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5
#define configKERNEL_INTERRUPT_PRIORITY \
        (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
        (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/* ---------- Assert ---------- */
#define configASSERT(x) if ((x) == 0) { __asm volatile("cpsid i"); for (;;); }

/* ---------- Optional API functions ---------- */
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskDelayUntil                 1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_xTaskGetSchedulerState          1

/* ---------- Map FreeRTOS handlers to the startup file's vector names ---------- */
#define vPortSVCHandler     SVC_Handler
#define xPortPendSVHandler  PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_FREERTOSCONFIG_H_ */
