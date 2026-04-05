#ifndef __SPI_H_
#define	__SPI_H_

#include "stm32f4xx.h"
#include <stdint.h>

void spi_init(void);
uint32_t spi_read(uint8_t* buffer, uint32_t buffer_length);
void spi_write(uint8_t* buffer, uint32_t buffer_length);

#endif
