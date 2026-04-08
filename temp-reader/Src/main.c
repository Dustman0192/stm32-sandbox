#include "led.h"
#include "timer.h"
#include "tmp.h"

#include <stdio.h>
#include <stdint.h>
#include <uart.h>

void TIM2_IRQHandler(void);

int main(void) {

	tmp_init();
	led_init();
	uart_init();

	timer_init();
	timer_set_enabled(true);

	while (true) {
	}

	return 0;
}

void TIM2_IRQHandler(void)
{
	timer_reset();

	led_toggle();

	uint32_t raw_temp = tmp_read_raw();
	double mv_temp = (double)raw_temp * 0.805860805861;
	double c_temp = ((double)mv_temp - 500.0) / 10.0;
	double f_temp = c_temp * (9.0/5.0) + 32.0;

	printf("Temperature | Raw: %lu; C: %lu; F: %lu\r\n", raw_temp, (uint32_t)c_temp, (uint32_t)f_temp);
}
