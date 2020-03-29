#include "func.h"



void myDelay_ms(uint32_t delay) { 
	static uint32_t tmp;
	tmp = TIM5->CNT;
	while( ((TIM5->CNT) - tmp) < 1000*delay) {}
}

void fill_sine(float* sine_arr, float steps) {
	for ( int i =0; i < steps; i++){
		sine_arr[i] = sin( ((float)(i/(steps-1)) *2*Pi))*90 ;
	}
}
