#ifndef __SPI_H__
#define __SPI_H__

#include "stm32f4xx.h"  


#define CS3_ON() GPIO_ResetBits(GPIOC, GPIO_Pin_9)
#define CS3_OFF() GPIO_SetBits(GPIOC, GPIO_Pin_9)

#define CS1_ON() GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define CS1_OFF() GPIO_SetBits(GPIOA, GPIO_Pin_4)

void SPI1_init(void);
void SPI3_init(void);



#endif /* __SPI_H__ */
