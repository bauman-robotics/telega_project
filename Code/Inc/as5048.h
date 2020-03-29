#ifndef __AS5048_H__
#define __AS5048_H__

#include "stm32f4xx.h"
#include "spi.h"
#include "math.h"
#include "arm_math.h"

#define window 100

typedef struct {
	uint8_t filled_CQ; // flag shows weather the buffer is filled or not
	float sine_sum;
	float cos_sum;	
	float arr_CQ[window];
	float sine_arr[window];
	float cos_arr[window];
	float sine_av;
	float cos_av;
	float X_i_CQ;
	float a_i_CQ;
	float sine_i;
	float cos_i;
	float raw_value;
	uint16_t k_CQ;  // The oldest mean of angle
} CQ_average_filter_typedef;

float get_angle(void);
float CQ_average_angle(CQ_average_filter_typedef* filter);

#endif /* __AS5048_H__ */
