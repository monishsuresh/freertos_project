/*
 * led.c
 *
 *  Created on: 15 Nov 2026
 *      Author: monish
 */

#include "led.h"
#include "stm32f4xx.h"

#define LED_PORT  GPIOA
#define LED_PIN   5U

void led_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	// enable gpio A port clock

	LED_PORT->MODER &= ~(3U << (LED_PIN * 2));	// clear mode register bits corresponding to PA5
	LED_PORT->MODER |= (1U  << (LED_PIN * 2));	// set mode to general purpose output
}

void led_set(int on)
{
	// led state is set using bsr register
	if (on)
	{
		LED_PORT->BSRR = (1U << 5);
	}

	else
	{
		LED_PORT->BSRR = (1U << (5 + 16));	// write to reset half of bsr register to switch off gpio pin
	}
}

void led_toggle(void)
{
	if (LED_PORT->IDR & (1 << LED_PIN))	// check input data register to see led pin's state
	{
		led_set(0);
	}
	else
	{
		led_set(1);
	}
}
