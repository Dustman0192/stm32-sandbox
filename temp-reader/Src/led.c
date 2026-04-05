#include "led.h"

#define AHB1ENR_CLKEN	(1U<<0)

static bool led_on = false;

void led_init(void)
{
	RCC->AHB1ENR |= AHB1ENR_CLKEN;
	GPIOA->MODER &= ~(1U<<11);
	GPIOA->MODER |= (1U<<10);
}
void led_toggle(void)
{
	if (led_on)
	{
		GPIOA->BSRR |= (1U<<5);
		led_on = false;
	}
	else
	{
		GPIOA->BSRR |= (1U<<21);
		led_on = true;
	}
}
