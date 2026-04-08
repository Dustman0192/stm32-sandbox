#ifndef __TMP_DRV_
#define __TMP_DRV_

#include "stm32f4xx.h"

void tmp_init(void);
uint32_t tmp_read_raw(void);

#endif
