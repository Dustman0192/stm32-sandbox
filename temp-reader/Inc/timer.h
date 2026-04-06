#ifndef __TIMER_H_
#define __TIMER_H_

#include "stm32f4xx.h"
#include <stdbool.h>

void timer_init(void);
void timer_reset(void);
void timer_set_enabled(bool);
bool timer_get_enabled(void);

#endif
