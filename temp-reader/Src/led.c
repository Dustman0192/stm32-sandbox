#include "led.h"

#define LED_PIN			(1U<<5)
#define AHB1ENR_CLKEN	(1U<<0)

static bool led_on = false;

void led_init(void)
{
	RCC->AHB1ENR |= AHB1ENR_CLKEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
}
void led_toggle(void)
{
	GPIOA->ODR ^= LED_PIN;
}
