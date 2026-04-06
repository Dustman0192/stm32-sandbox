#include "timer.h"

#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define SR_UIF		(1U<<0)

#define DIER_UIE	(1U<<0)

// SYSCLOCK
#define PRESCALER	1600U
#define AUTO_RELOAD	10000U

void timer_init()
{
	RCC->APB1ENR |= TIM2EN;
	TIM2->PSC = PRESCALER-1;	// sub 1 because counter(s) start at 0
	TIM2->ARR = AUTO_RELOAD-1;
	TIM2->CNT = 0;

	__disable_irq();

	TIM2->DIER |= (1U<<0);
	NVIC->ISER[0] |= (1U<<28);

	__enable_irq();
}
void timer_reset(void)
{
	TIM2->SR &= ~SR_UIF;
}
void timer_set_enabled(bool is_enabled)
{
	if (is_enabled)
	{
		TIM2->CNT = 0;
		TIM2->CR1 |= CR1_CEN;
	}
	else
	{
		TIM2->CR1 &= ~CR1_CEN;
	}
}
bool timer_get_enabled(void)
{
	return TIM2->CR1 & CR1_CEN;
}
