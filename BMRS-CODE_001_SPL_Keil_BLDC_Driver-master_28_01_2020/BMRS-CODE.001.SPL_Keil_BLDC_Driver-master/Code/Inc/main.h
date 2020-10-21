#ifndef __MAIN_N__
#define __MAIN_N__

#include "stm32f4xx.h" 
#include "as5048.h"
#include "func.h"
#include "tim.h"
#include "gpio.h"
#include "spi.h"
#include "foc.h"
#include "uart.h"
#include "cobs.h"

#include <stdio.h>

typedef struct {
	uint8_t mode;
	float data;
} CMD;

typedef enum {
	not_ready,
	ready
} STATUS;

#endif /* __MAIN_H__ */
