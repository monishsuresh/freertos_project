/*
 * led_blink_task.c
 *
 *  Created on: 18 Nov 2026
 *      Author: monish
 */

#include "led_blink_task.h"
#include "task.h"
#include "led.h"

#define BLINK_PERIOD	1000U
#define BLINK_STACK_WORDS	configMINIMAL_STACK_SIZE	// 128 words; minimum stack size is sufficient for led blinking

static void BlinkTask(void *param)
{
	(void)param;
	TickType_t last_wake = xTaskGetTickCount();	// starting system tick to be used for blink timing

	while (1)
	{
		led_toggle();
		xTaskDelayUntil(&last_wake, pdMS_TO_TICKS(BLINK_PERIOD));
	}
}

void blink_start(UBaseType_t priority)
{
	BaseType_t task_create = xTaskCreate(BlinkTask, "blink", BLINK_STACK_WORDS,
										 NULL, priority, NULL);
	configASSERT(task_create == pdPASS);
}
