#ifndef __FUNC_H__
#define __FUNC_H__

#include "stm32f4xx.h"     
#include "math.h"

#define Pi 3.1415926535897932384




void myDelay_ms(uint32_t delay);
void fill_sine(float* sine_arr, float steps);

#endif /* __FUNC_H__ */
