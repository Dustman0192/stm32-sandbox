#include "led.h"
#include "spi.h"
#include "timer.h"
#include "tmp.h"

int main(void) {

	//tmp_init();
	led_init();
	//spi_init();
	timer_init();

	timer_set_enabled(true);
	while (true) {
		if (timer_get_overflowed()) {
			led_toggle();
			timer_reset();
		}
	}

	return 0;
}
