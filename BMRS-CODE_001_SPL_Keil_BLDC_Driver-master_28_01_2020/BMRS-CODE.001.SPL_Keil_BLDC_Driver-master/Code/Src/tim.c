#include "tim.h"

void TIM2_init(void) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitTypeDef timer2_init;
	TIM_TimeBaseStructInit(&timer2_init);
	timer2_init.TIM_Period = INC_period-1;// ---> 100 microsec
	timer2_init.TIM_Prescaler = 2-1; // ---> 42 MHz
	TIM_TimeBaseInit(TIM2, &timer2_init);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

void TIM4_init(void) {
	// PWM LED Visualisation timer
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_TimeBaseInitTypeDef timer_init;
	TIM_TimeBaseStructInit(&timer_init);
	timer_init.TIM_Period = PWM_period-1;// ---> 20kHz
	timer_init.TIM_Prescaler = 2-1; // ---> 42 MHz
	TIM_TimeBaseInit(TIM4, &timer_init);
	
	//channel 1;	
	TIM_OCInitTypeDef tim_oc_init1;
	TIM_OCStructInit(&tim_oc_init1);
	tim_oc_init1.TIM_Pulse = 0;  
	tim_oc_init1.TIM_OCMode = TIM_OCMode_PWM1;
	tim_oc_init1.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM4, &tim_oc_init1);// 
	
	
	//channel 2;
	TIM_OCInitTypeDef tim_oc_init2;
	TIM_OCStructInit(&tim_oc_init2);
	tim_oc_init2.TIM_Pulse = 0;  
	tim_oc_init2.TIM_OCMode = TIM_OCMode_PWM1;
	tim_oc_init2.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM4, &tim_oc_init2);// 
	
	//channel 3;
	TIM_OCInitTypeDef tim_oc_init3;
	TIM_OCStructInit(&tim_oc_init3);
	tim_oc_init3.TIM_Pulse = 0;  
	tim_oc_init3.TIM_OCMode = TIM_OCMode_PWM1;
	tim_oc_init3.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM4, &tim_oc_init3);// 
	
	TIM_Cmd(TIM4, ENABLE);
}

void TIM5_init(void) { // Time measuring timer
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	//base settings
	TIM_TimeBaseInitTypeDef TIM5_Base;
	TIM5_Base.TIM_Period = 0xFFFFFFFF;
  	TIM5_Base.TIM_Prescaler = 84-1; // 1MHz
  	TIM5_Base.TIM_ClockDivision = TIM_CKD_DIV1 ; //
  	TIM5_Base.TIM_CounterMode = TIM_CounterMode_Up;
  	TIM5_Base.TIM_RepetitionCounter = 0x0000;
	TIM_TimeBaseInit(TIM5, &TIM5_Base);
	TIM_Cmd(TIM5, ENABLE);
}

void TIM7_init(void) { // TIM for FOC control loop
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	
	TIM_TimeBaseInitTypeDef timer7_init;
	TIM_TimeBaseStructInit(&timer7_init);
	timer7_init.TIM_Period = 4200-1;// ---> 10kHz
	timer7_init.TIM_Prescaler = 2-1; // ---> 42 MHz
	TIM_TimeBaseInit(TIM7, &timer7_init);
	
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM7, ENABLE);
}

void TIM1_init(void) {
	// BLDC PWM
// TIM1_CH1    PE9
// TIM1_CH1N   PE8
// TIM1_CH2    PE11
// TIM1_CH2N   PE10
// TIM1_CH3    PE13
// TIM1_CH3N   PE12	
		
	GPIO_InitTypeDef GPIO_InitStructure;
 	TIM_TimeBaseInitTypeDef TIM_BaseStruct;
 	TIM_OCInitTypeDef TIM_OCStruct;
 	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
	// Clock configuration
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	// GPIO Configuration
 	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_TIM1);
 	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 |GPIO_Pin_11 |GPIO_Pin_12 |GPIO_Pin_13 ;
 	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
 	GPIO_Init(GPIOE, &GPIO_InitStructure);
	// Timer 1 Configuration PWM Channels
 	TIM_BaseStruct.TIM_Period = PWM_period-1;
 	TIM_BaseStruct.TIM_Prescaler = 4-1; // ---> 42 MHz 
 	TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
 	TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
 	TIM_TimeBaseInit(TIM1, &TIM_BaseStruct);
 	TIM_Cmd(TIM1, ENABLE);
	// PWM_ Configuration
 	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
 	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;//TIM_OCPolarity_Low;//TIM_OCPolarity_High;
 	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
 	TIM_OCStruct.TIM_OutputNState = TIM_OutputNState_Enable;
 	TIM_OCStruct.TIM_OCNPolarity = TIM_OCPolarity_High;//TIM_OCPolarity_Low;//TIM_OCNPolarity_High; 
 	TIM_OCStruct.TIM_Pulse = 0;

	TIM_OC1Init(TIM1, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
//------------------------------------------------------------------ 
 /*Инвертирование каналов для новой платы, полярность Low*/
 /*#define CC1NP_LOW (0x1)<<3
 #define CC1P_LOW (0x1)<<1
 #define CC2NP_LOW (0x1)<<7
 #define CC2P_LOW (0x1)<<5
 #define CC3NP_LOW (0x1)<<11
 #define CC3P_LOW (0x1)<<9
 TIM1->CCER = CC1NP_LOW|CC1P_LOW|CC2NP_LOW|CC2P_LOW|CC3NP_LOW|CC3P_LOW;*/
 //---------------------------------------------------------------------------------
 	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
 	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
 	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
 	TIM_BDTRInitStructure.TIM_DeadTime = 168; // 1 microsec(168)
 	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;
 	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low;
 	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;

	TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
 
 	TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
 	TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
 	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);
 
 	TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1);
 	TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
 	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
 
 	TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
 	TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
 	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);
 
 	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
