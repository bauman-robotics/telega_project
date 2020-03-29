#include "gpio.h"

void GPIO_init(void) {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	// PWM LED Visualisation by TIM4
	// Channale 1 --> PD12--------------------------
	GPIO_InitTypeDef ledinit_AF;
	GPIO_StructInit(&ledinit_AF);
	ledinit_AF.GPIO_Mode = GPIO_Mode_AF;
	ledinit_AF.GPIO_Pin = GPIO_Pin_12;
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4); 
	GPIO_Init(GPIOD, &ledinit_AF);

	// Channale 2 --> PD13--------------------------
	GPIO_InitTypeDef ledinit_AF2;
	GPIO_StructInit(&ledinit_AF2); 
	ledinit_AF2.GPIO_Mode = GPIO_Mode_AF;
	ledinit_AF2.GPIO_Pin = GPIO_Pin_13;
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_Init(GPIOD, &ledinit_AF2);

	// Channale 3 --> PD14--------------------------
	GPIO_InitTypeDef ledinit_AF3;
	GPIO_StructInit(&ledinit_AF2); 
	ledinit_AF3.GPIO_Mode = GPIO_Mode_AF;
	ledinit_AF3.GPIO_Pin = GPIO_Pin_14; 
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4); 
	GPIO_Init(GPIOD, &ledinit_AF3);
	
	GPIO_InitTypeDef  GPIO_InitStructure;                 
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;           
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;     
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     
	GPIO_Init(GPIOD, &GPIO_InitStructure);                
}
