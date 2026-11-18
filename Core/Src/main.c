#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "led_blink_task.h"

int main(void)
{
    SCB->CPACR |= (0xFU << 20);     // enable hardware floating point unit
    __DSB(); __ISB();	// data and instruction syncronization barriers to ensure FPU initialization is complete before running further instructions

    NVIC_SetPriorityGrouping(0);	// set all interrupts to preemptive

    led_init();
    blink_start(tskIDLE_PRIORITY + 1);

    vTaskStartScheduler();	// start freertos kernel

    while (1)
    {

    }
}
