#ifndef __TIM_H__
#define __TIM_H__
 
#include "stm32f4xx.h"              

void TIM2_init(void);
void TIM4_init(void);	// PWM LED Visualisation timer
void TIM5_init(void);
void TIM7_init(void);
void TIM1_init(void) ;

#define PWM_period 2100//3200
#define INC_period 4200

#endif /* __TIM_H__ */
