#ifndef COMMUNICATION
#define COMMUNICATION

#include "stm32h7xx_hal.h"

#define COMMUNICATION_DELAY 1
#define COMMUNICATION_WAITTING COMMUNICATION_DELAY * 5

#define ALIGN32_SIZE(SIZE_ALIGN) (((SIZE_ALIGN + 31)/32)*32)

enum _BOOL_
{
	_TRUE_ = 1,
	_FALSE_ = 0 
};

enum OP_TYPE
{
	READ,
	WRITE,
	CPLT,
	COMMAND,
	NONE
};

void ReceiveUARTPackage(UART_HandleTypeDef *huart, uint8_t *buf, uint8_t len);
void TransmitUARTPackage(UART_HandleTypeDef *huart, uint8_t *buf, uint8_t len);

void WriteToRegisterBySPI(SPI_HandleTypeDef *hspi, uint8_t addr, uint8_t *buf, uint8_t len);
void ReadFromRegisterBySPI(SPI_HandleTypeDef *hspi, uint8_t addr, uint8_t *buf, uint8_t len);
void TransmitCommandBySPI(SPI_HandleTypeDef *hspi, uint8_t *command, uint8_t *callback, uint8_t len);

#endif