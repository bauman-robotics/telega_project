#ifndef __UART_h__
#define __UART_h__

#include "stm32f4xx.h"                  

void USART_2_init(void);
void UART2_Send_16bValue(uint16_t data, char key);
void UART_Send_Byte(uint8_t byte);
void UART_2_Send_Byte(uint8_t byte); 
void SendStr(char *str_p);
void SendStrz(char *str_p);
#endif /* __UART_h__ */
