#include "as5048.h"


float  angle_raw;
float get_angle(void) {
	// with SPI3
	static uint8_t pr = 0;
	static uint16_t ResData1, ResData2;
	static uint16_t angle_raw_16;
	//static float  angle_raw;
	if(!pr) {		
		CS3_ON();		
		SPI_I2S_SendData(SPI3, 0xFFFF );
		while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET) {} 
		ResData1 = SPI_I2S_ReceiveData(SPI3);
		CS3_OFF();		
		pr=1;
	}
	CS3_ON();	
	SPI_I2S_SendData(SPI3, 0xFFFF );
	while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET) {}
	ResData2 = SPI_I2S_ReceiveData(SPI3);
	CS3_OFF();					
	angle_raw_16 = ResData2 & 0x3FFF;
	angle_raw = (double)(angle_raw_16)*0.021973997;
	return 	angle_raw;		// (float)(ResData2 & 0x3FFF)*0.021973997;	
}	
	
	// Mean of circular quantities
	
float CQ_average_angle(CQ_average_filter_typedef* filter) {
	if(!filter->filled_CQ)
	{
		filter->sine_sum = 0;
		filter->cos_sum = 0;
		for (int i=0; i < window; i++) {
			filter->arr_CQ[i] = get_angle()*0.01745329251994329576923690768489 ;//Pi/180; // translating into radians;
			filter->sine_arr[i] = arm_sin_f32(filter->arr_CQ[i]); 
			filter->cos_arr[i] = arm_cos_f32(filter->arr_CQ[i]);
			filter->sine_sum += filter->sine_arr[i];
			filter->cos_sum += filter->cos_arr[i];
		}
		 
		filter->sine_av = filter->sine_sum/window;
		filter->cos_av = filter->cos_sum/window;
		filter->X_i_CQ  = atan2(filter->sine_av, filter->cos_av)*57.295779513082320876798154814105 ; // out of the filter

		filter->filled_CQ = 1;
		filter->k_CQ=0;
		return filter->X_i_CQ; 
	}
	// 2) start filtering
	else {
		filter->raw_value = get_angle();
		filter->a_i_CQ = filter->raw_value*0.01745329251994329576923690768489 ;//Pi/180; // translating into radians;
		filter->sine_i = arm_sin_f32(filter->a_i_CQ);
		filter->cos_i = arm_cos_f32(filter->a_i_CQ);
		filter->sine_sum = filter->sine_sum - filter->sine_arr[filter->k_CQ] + filter->sine_i;
		filter->cos_sum = filter->cos_sum - filter->cos_arr[filter->k_CQ] + filter->cos_i;
		filter->sine_av = filter->sine_sum/window;
		filter->cos_av = filter->cos_sum/window;
		filter->X_i_CQ  = atan2(filter->sine_av, filter->cos_av)*57.295779513082320876798154814105 ;
		filter->sine_arr[filter->k_CQ] = filter->sine_i;
		filter->cos_arr[filter->k_CQ] = filter->cos_i;
		 // substitute thrown out value with new value for cycling
		filter->k_CQ++;
		if(filter->k_CQ >= window) filter->k_CQ=0; // array loop
		return filter->X_i_CQ;
	}
}
