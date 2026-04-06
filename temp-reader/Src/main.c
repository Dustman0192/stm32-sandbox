#include "led.h"
#include "spi.h"
#include "timer.h"
#include "tmp.h"

void TIM2_IRQHandler(void);

int main(void) {

	//tmp_init();
	led_init();
	//spi_init();
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
}
