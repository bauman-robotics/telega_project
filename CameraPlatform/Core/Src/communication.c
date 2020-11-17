#include "communication.h"
#include "cmsis_os.h"

extern UART_HandleTypeDef huart3;
ALIGN_32BYTES(volatile uint8_t uart3TxBuf[ALIGN32_SIZE(256)] __attribute__((section(".SRAM"))));
ALIGN_32BYTES(volatile uint8_t uart3RxBuf[ALIGN32_SIZE(256)] __attribute__((section(".SRAM"))));
enum _BOOL_ uart3PkgTransmited = _FALSE_;
enum _BOOL_ uart3PkgReceived = _FALSE_;

extern SPI_HandleTypeDef hspi1;
ALIGN_32BYTES(volatile uint8_t spi1TxBuf[ALIGN32_SIZE(256)] __attribute__((section(".SRAM"))));
ALIGN_32BYTES(volatile uint8_t spi1RxBuf[ALIGN32_SIZE(256)] __attribute__((section(".SRAM"))));
ALIGN_32BYTES(volatile uint8_t spi1AddrBuf __attribute__((section(".SRAM"))));
enum _BOOL_ spi1PkgTransmited = _FALSE_; 
enum _BOOL_ spi1PkgReceived = _FALSE_;
enum OP_TYPE spi1OpType = NONE;
//uint8_t *spi1Buf;
uint8_t spi1Len;

extern I2C_HandleTypeDef hi2c2;
ALIGN_32BYTES(volatile uint8_t i2c2Buf[ALIGN32_SIZE(256)] __attribute__((section(".SRAM"))));
enum _BOOL_ i2c2PkgTransmited = _FALSE_; 
enum _BOOL_ i2c2PkgReceived = _FALSE_;
enum OP_TYPE i2c2OpType = NONE;
uint8_t i2c2Len;
uint8_t i2c2DevAddr;

void ReceiveUARTPackage(UART_HandleTypeDef *huart, uint8_t *buf, uint8_t len)
{
	TickType_t timeBegin = xTaskGetTickCount();

	HAL_StatusTypeDef err = HAL_UART_Receive_DMA(huart, buf, len);
  while (!uart3PkgReceived  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING) osDelay(COMMUNICATION_DELAY);
  
	uart3PkgReceived = _FALSE_;
}



void TransmitUARTPackage(UART_HandleTypeDef *huart, uint8_t *buf, uint8_t len)
{
	TickType_t timeBegin = xTaskGetTickCount();
	memcpy((void*)&uart3TxBuf, (void*)buf, len);
	SCB_CleanDCache_by_Addr((uint32_t*)&uart3TxBuf, ALIGN32_SIZE(len));
	HAL_StatusTypeDef err = HAL_UART_Transmit_DMA(huart, (uint8_t*)&uart3TxBuf, len);
  while (!uart3PkgTransmited  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING) osDelay(COMMUNICATION_DELAY);
	
  uart3PkgTransmited = _FALSE_;
}



void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart3) {
		uart3PkgTransmited = _TRUE_;
  }
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart == &huart3){
    uart3PkgReceived = _TRUE_;
  }
}



void WriteToRegisterBySPI(SPI_HandleTypeDef *hspi, uint8_t addr, uint8_t *buf, uint8_t len)
{
	TickType_t timeBegin = xTaskGetTickCount();

	enum _BOOL_ *cpltCheck;
	if(hspi == &hspi1) {
		//spi1Buf = buf;
		spi1Len = len;
		spi1OpType = WRITE;
		cpltCheck = &spi1PkgTransmited;
  } 
	memcpy((void*)&spi1AddrBuf, (void*)&addr, 1);
	memcpy((void*)&spi1TxBuf, (void*)buf, 1);
	SCB_CleanDCache_by_Addr((uint32_t*)&spi1AddrBuf, ALIGN32_SIZE(1));
	HAL_SPI_Transmit_DMA(hspi, (uint8_t*)&spi1AddrBuf, 1);
  while (!*cpltCheck  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING) osDelay(COMMUNICATION_DELAY);
	*cpltCheck = _FALSE_;
}



void ReadFromRegisterBySPI(SPI_HandleTypeDef *hspi, uint8_t addr, uint8_t *buf, uint8_t len)
{
	TickType_t timeBegin = xTaskGetTickCount();
	
	enum _BOOL_ *cpltCheck;
	if(hspi == &hspi1) {
		//spi1Buf = buf;
		spi1Len = len;
		spi1OpType = READ;
		cpltCheck = &spi1PkgReceived;
  } 
	
	memcpy((void*)&spi1AddrBuf, (void*)&addr, 1);
	SCB_CleanDCache_by_Addr((uint32_t*)&spi1AddrBuf, ALIGN32_SIZE(1));
	HAL_SPI_Transmit_DMA(hspi, (uint8_t*)&spi1AddrBuf, 1);
  while (!*cpltCheck  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING)
	{
		osDelay(COMMUNICATION_DELAY);
	}
	*cpltCheck = _FALSE_;
	memcpy((void*)buf, (void*)&spi1RxBuf, spi1Len);
}



void TransmitCommandBySPI(SPI_HandleTypeDef *hspi, uint8_t *command, uint8_t *callback, uint8_t len)
{
	TickType_t timeBegin = xTaskGetTickCount();
	
	enum _BOOL_ *cpltCheck;
	if(hspi == &hspi1) {
		//spi1Buf = buf;
		spi1Len = len;
		spi1OpType = COMMAND;
		cpltCheck = &spi1PkgReceived;
  } 
	
	memcpy((void*)&spi1TxBuf, (void*)command, len);
	SCB_CleanDCache_by_Addr((uint32_t*)&spi1AddrBuf, ALIGN32_SIZE(1));
	HAL_SPI_TransmitReceive_DMA(hspi, (uint8_t*)&spi1TxBuf, (uint8_t*)&spi1RxBuf, len);
  while (!*cpltCheck  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING)
	{
		osDelay(COMMUNICATION_DELAY);
	}
	*cpltCheck = _FALSE_;
	memcpy((void*)callback, (void*)&spi1RxBuf, spi1Len);
}



void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi == &hspi1) {
		switch (spi1OpType)
		{
			case WRITE:
				spi1OpType = CPLT;
				SCB_CleanDCache_by_Addr((uint32_t*)&spi1TxBuf, ALIGN32_SIZE(spi1Len));
				HAL_SPI_Transmit_DMA(hspi, (uint8_t*)spi1TxBuf, spi1Len);
			break;
			case READ:
				spi1OpType = CPLT;
				HAL_SPI_Receive_DMA(hspi, (uint8_t*)spi1RxBuf, spi1Len);
			break;
			case CPLT:
				spi1PkgTransmited = _TRUE_;
				spi1OpType = NONE;
			break;
			case NONE:
			break;
		}
  } 
}



void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi == &hspi1) {
		SCB_InvalidateDCache_by_Addr((uint32_t*)&spi1RxBuf, ALIGN32_SIZE(spi1Len));
		spi1PkgReceived = _TRUE_;
		spi1OpType = NONE;
  } 
}
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi == &hspi1) {
		SCB_InvalidateDCache_by_Addr((uint32_t*)&spi1RxBuf, ALIGN32_SIZE(spi1Len));
		spi1PkgReceived = _TRUE_;
		spi1OpType = NONE;
  } 
}



//void WriteToRegisterByI2C(I2C_HandleTypeDef *hi2c, uint8_t devAddr, uint8_t regAddr, uint8_t *buf, uint8_t len)
//{
//	TickType_t timeBegin = xTaskGetTickCount();

//	enum _BOOL_ *cpltCheck;
//	if(hi2c == &hi2c2) {
//		//spi1Buf = buf;
//		i2c2Len = len;
//		i2c2OpType = WRITE;
//		cpltCheck = &i2c2PkgTransmited;
//  } 
//	uint8_t Addr = regAddr;
//	
//	memcpy((void*)&i2c2Buf, (void*)&regAddr, 1);
//	memcpy((void*)(&i2c2Buf[1]), (void*)buf, len);
//	SCB_CleanDCache_by_Addr((uint32_t*)&i2c2Buf, ALIGN32_SIZE(1 + len));
//	HAL_I2C_Master_Transmit_DMA(hi2c, (uint16_t)devAddr, (uint8_t*)&i2c2Buf, 1 + len);
//  while (!*cpltCheck  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING) osDelay(COMMUNICATION_DELAY);
//	*cpltCheck = _FALSE_;
//}



//void ReadFromRegisterByI2C(I2C_HandleTypeDef *hi2c, uint8_t devAddr, uint8_t regAddr, uint8_t *buf, uint8_t len)
//{
//	TickType_t timeBegin = xTaskGetTickCount();
//	
//	enum _BOOL_ *cpltCheck;
//	if(hi2c == &hi2c2) {
//		//spi1Buf = buf;
//		i2c2Len = len;
//		i2c2OpType = READ;
//		cpltCheck = &i2c2PkgReceived;
//		i2c2DevAddr= devAddr;
//  } 
//	uint8_t Addr = regAddr;
//	
//	memcpy((void*)&i2c2Buf, (void*)&Addr, 1);
//	SCB_CleanDCache_by_Addr((uint32_t*)&i2c2Buf, ALIGN32_SIZE(1));
//	HAL_I2C_Master_Seq_Transmit_DMA(hi2c, (uint16_t)devAddr, (uint8_t*)&i2c2Buf, 1, I2C_FIRST_FRAME);
//  while (!*cpltCheck  && xTaskGetTickCount() - timeBegin < COMMUNICATION_WAITTING)
//	{
//		osDelay(COMMUNICATION_DELAY);
//	}
//	*cpltCheck = _FALSE_;
//	memcpy((void*)buf, (void*)&i2c2Buf, i2c2Len);
//}



//void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	if(hi2c == &hi2c2) {
//		switch (i2c2OpType)
//		{
//			case WRITE:
//				i2c2OpType = NONE;
//				i2c2PkgTransmited = _TRUE_;
//			break;
//			case READ:
//				i2c2OpType = CPLT;
//				HAL_I2C_Master_Seq_Receive_DMA(hi2c, (uint16_t)i2c2DevAddr,(uint8_t*)&i2c2Buf, i2c2Len, I2C_LAST_FRAME);
//			break;
//			case CPLT:
//				i2c2PkgTransmited = _TRUE_;
//				i2c2OpType = NONE;
//			break;
//			case NONE:
//			break;
//		}
//  } 
//}



//void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	if(hi2c == &hi2c2) {
//		SCB_InvalidateDCache_by_Addr((uint32_t*)&i2c2Buf, ALIGN32_SIZE(i2c2Len));
//		i2c2PkgReceived = _TRUE_;
//		i2c2OpType = NONE;
//	}
//}
