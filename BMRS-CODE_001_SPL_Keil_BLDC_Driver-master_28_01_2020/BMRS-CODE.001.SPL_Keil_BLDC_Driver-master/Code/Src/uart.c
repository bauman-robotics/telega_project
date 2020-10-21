#include "uart.h"

void USART_2_init(void) {
	//PD6,PD5
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	 
	GPIO_InitTypeDef USART2_ini;
	USART2_ini.GPIO_Mode = GPIO_Mode_AF;
	USART2_ini.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;
	USART2_ini.GPIO_Speed = GPIO_Speed_2MHz;
 	USART2_ini.GPIO_OType = GPIO_OType_PP;
  	USART2_ini.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(GPIOD, &USART2_ini);
	 
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2);
	 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE) ;
	 
	USART_InitTypeDef USART2_user;
	USART2_user.USART_BaudRate= 115200;
	USART2_user.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
 	USART2_user.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
 	USART2_user.USART_Parity = USART_Parity_No;
 	USART2_user.USART_StopBits = USART_StopBits_1;
 	USART2_user.USART_WordLength = USART_WordLength_8b;
	 
	USART_Init(USART2, &USART2_user);

 	NVIC_InitTypeDef NVIC_InitStructure2;

	NVIC_InitStructure2.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 5;
	NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure2);
	 
 	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	 
 	USART_Cmd(USART2, ENABLE);
 }

void UART_2_Send_Byte(uint8_t byte) {
	USART_SendData (USART2, (uint16_t)byte);
	while (!USART_GetFlagStatus(USART2, USART_FLAG_TXE)) {}
}

void UART_2_Send_16bValue(uint16_t data, char key) {
	//Деление на 2 байта и добавление символа '\n'
	uint8_t	Data_L = (uint8_t)(data&0x00FF);
	uint8_t	Data_H = (uint8_t)((data&0xFF00)>>8);
	UART_2_Send_Byte((uint8_t)('\n'));
	UART_2_Send_Byte((uint8_t)key);
	UART_2_Send_Byte(Data_L);
	UART_2_Send_Byte(Data_H);
}

void SendStr(char *str_p)
{
	uint16_t i=0;
	
	while(str_p[i] != 0)
	{
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET) {}
		USART_SendData(USART2, str_p[i]);
		i++;	
	}
}

void SendStrz(char *str_p)
{
	uint16_t i=0;
	
	while(str_p[i] != 0)
	{
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET) {}
		USART_SendData(USART2, str_p[i]);
		i++;	
	}
    while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET) {}
	USART_SendData(USART2, str_p[i]);
}
