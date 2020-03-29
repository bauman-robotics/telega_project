#include "foc.h"

float angle_init;

/*** Channel 1 - A, Channel 2 - B, Channel 3 - C ***/

void FOC_InitPosition(CQ_average_filter_typedef* filter, Mode MODE) {
	
	// establishing zero position, d-axis directed to A winding, theta = 90
	static Voltage volt;
	if (MODE == CALIBRATION) {
		volt.Vq=2;
		
		volt.Va_ang = arm_cos_f32(0);//cos(theta);     
		volt.Vb_ang = arm_cos_f32(0 - 2.0943951023931954923084289221863);//cos(theta - 2.0943951023931954923084289221863 ); //2*Pi/3
		volt.Vc_ang = arm_cos_f32(0 + 2.0943951023931954923084289221863);//cos(theta + 2.0943951023931954923084289221863);
		
		volt.Va = volt.Va_ang * volt.Vq; // projection calculation of Vq into A phase
		volt.Vb = volt.Vb_ang * volt.Vq; // projection calculation of Vq into B phase
		volt.Vc = volt.Vc_ang * volt.Vq; // projection calculation of Vq into C phase
		
		volt.Vinv1 = volt.Va + 6; // Obtaining value for inverter, +6 because Vinv relates with V_phase as Vinv = Vphase + Vdc/2 in order to avoid negative values for invertor voltage.
		volt.Vinv2 = volt.Vb + 6; // should also be taken into account that Vphase(max) = Vdc/2 (with sine PWM) 
		volt.Vinv3 = volt.Vc + 6;
		
		TIM1->CCR1 = (uint32_t)(volt.Vinv1*PWM_period/Vdc)  ; 
			TIM1->CCR2 = (uint32_t)(volt.Vinv2*PWM_period/Vdc)  ;
			TIM1->CCR3 = (uint32_t)(volt.Vinv3*PWM_period/Vdc)  ;
		
		myDelay_ms(1000);	
		
		/* Reset "filled" flag for filter */
		filter->filled_CQ=0;
		
		angle_init = CQ_average_angle(filter);
		TIM1->CCR1 = 0 ; 
		TIM1->CCR2 = 0 ;
		TIM1->CCR3 = 0 ;
	}
	else{
	angle_init = -173.669754; 
	TIM1->CCR1 = 0 ; 
  TIM1->CCR2 = 0 ;
  TIM1->CCR3 = 0 ;
	}
	// init angle was calculated once. Now it is used like starting point for electrical angles and engine does not need position initialization
}

void FOC(float angle, float error_angle, float K_p, float K_d, float K_i) {
	static float theta, theta_elec_degrees, error_angle_last;
	static float err_i;
	static Voltage volt;
	
	
	
	theta_elec_degrees = ((angle - angle_init)*Pole_Pairs + 90 ); // 11 - pole pairs (22P). + 90 because at initial position theta = 90  
	theta = theta_elec_degrees * 0.01745329251994329576923690768489;//Pi/180; // translating into radians
	 
	volt.Vd = 0; // !
	
	if(error_angle > 180) {
		error_angle = 360 - error_angle;
		error_angle = - error_angle;
	}
	if(error_angle < -180) {
		error_angle = 360 + error_angle;
	}
	
	err_i = err_i + error_angle;
	if(err_i>6000) err_i=6000;
	if(err_i<-6000) err_i = -6000;
	volt.Vq = K_p*error_angle + (error_angle - error_angle_last)*K_d + err_i*K_i; //Speed; //
	error_angle_last = error_angle;
	
	/*
	if(volt.Vq < -3) volt.Vq = -3; // 6V = Vdc/2 , voltage limitation4
	if(volt.Vq > 3) volt.Vq = 3;
	*/
    
	if(volt.Vq < -6) volt.Vq = -6; // no voltage limitation
	if(volt.Vq > 6) volt.Vq = 6;
	
	volt.Va_ang = arm_cos_f32(theta);//cos(theta         );     
	volt.Vb_ang = arm_cos_f32(theta - 2.0943951023931954923084289221863);//cos(theta - 2.0943951023931954923084289221863 /* 2*Pi/3 */);
	volt.Vc_ang = arm_cos_f32(theta + 2.0943951023931954923084289221863);//cos(theta + 2.0943951023931954923084289221863);
	
	volt.Va = volt.Va_ang * volt.Vq; // projection calculation of Vq into A phase
	volt.Vb = volt.Vb_ang * volt.Vq; // projection calculation of Vq into B phase
	volt.Vc = volt.Vc_ang *volt.Vq; // projection calculation of Vq into C phase
	
	volt.Vinv1 = volt.Va + 6; // Obtaining value for invertor, +6 because Vinv relates with V_phase as Vinv = Vphase + Vdc/2 in order to avoid negative values for invertor voltage.
	volt.Vinv2 = volt.Vb + 6; // should also be taken into account that Vphase(max) = Vdc/2 (with sine PWM) 
	volt.Vinv3 = volt.Vc + 6;
	
	// Vinx_max = 12V, PWM = Vinv*PWM_period/Vinv_max
	TIM4->CCR1 = (uint32_t)(volt.Vinv1*PWM_period/Vdc); 
	TIM4->CCR2 = (uint32_t)(volt.Vinv2*PWM_period/Vdc);
	TIM4->CCR3 = (uint32_t)(volt.Vinv3*PWM_period/Vdc);
	
	TIM1->CCR1 = (uint32_t)(volt.Vinv1*PWM_period/Vdc); 
	TIM1->CCR2 = (uint32_t)(volt.Vinv2*PWM_period/Vdc);
	TIM1->CCR3 = (uint32_t)(volt.Vinv3*PWM_period/Vdc);
}
