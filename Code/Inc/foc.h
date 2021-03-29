#ifndef __FOC_H__
#define __FOC_H__

#include "stm32f4xx.h"                  // Device header
#include "tim.h"
#include "func.h"
#include "math.h"
#include "arm_math.h"
#include "as5048.h"

#define High			0x01
#define Low				0x00
#define average		 100
#define Pole_Pairs 10 //small ankor = 10// 15 -- normal 6.5//12 = 10 "
#define Vdc 				12
#define Pi 3.1415926535897932384
#define SINE_STEPS 20000
#define SPEED_STEPS 20000

	// PA1 - EN1
	// PA2 - EN2  (nReset)
	// PA3 - EN3 (EN2)
	// PA4 - nSLEEP
	// PA5 - nRESET (EN3)
	// IN1(PWM1) - PD12
	// IN2(PWM2) - PD13
	// IN3(PWM3) - PD14

typedef struct {
	float Vq;
	float Vd;
	float Va; 
	float	Vb;
	float Vc; 
	float Va_ang; 
	float Vb_ang; 
	float Vc_ang;
	float Vinv1;
	float	Vinv2; 
	float Vinv3;
} Voltage;

typedef enum {
	DISABLED, 
	CALIBRATION,
	SINE,
	STATIC, 	
	SPEED,
  SMOOTH_ACCEL,
	SMOOTH_ACCEL_WITH_NEGATIVE_VELOCITY,
	SMOOTH_POSITION_CONTROL,
	GOT_TIME,
	GOT_LINEAR_VEL,
	GOT_ROUND_VEL
} Mode;

void FOC_InitPosition(CQ_average_filter_typedef* filter, Mode MODE);
void FOC(float angle, float error_angle, float K_p, float K_d, float K_i);

#endif /* __FOC_H__ */
