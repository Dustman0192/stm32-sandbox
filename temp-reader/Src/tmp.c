#include "tmp.h"

#define GPIOAEN			(1U<<0)
#define ADC_EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	0x00
#define CR2_ADON		(1U<<0)
#define CR2_CONT		(1U<<1)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)

void tmp_init(void)
{
	// enable clock on PORTA
	RCC->AHB1ENR |= GPIOAEN;

	// put PA1 in Analog mode
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	// reset ADC interface
	RCC->APB2ENR |= ADC_EN;

	// set conversion sequence start = 1
	ADC1->SQR3 = ADC_CH1;

	// set conversion sequence count = 1
	ADC1->SQR1 = ADC_SEQ_LEN_1;

	// Turn ADC - ON
	ADC1->CR2 |= CR2_ADON;
}
uint32_t tmp_read_raw(void)
{
	// enable continuous conversion
	ADC1->CR2 |= CR2_CONT;

	// start the conversion
	ADC1->CR2 |= CR2_SWSTART;

	while (!(ADC1->SR & SR_EOC)) {}

	return ADC1->DR;

//	return temp * 0.020899;
}
