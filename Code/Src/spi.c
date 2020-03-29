#include "spi.h"



void SPI1_init(void) {
	//PA5 - CLCK
	//PA6 - MISO
	//PA7 - MOSI
	//PA4 - CS
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	
	GPIO_InitTypeDef SPI1_pins;
	SPI1_pins.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	SPI1_pins.GPIO_Mode = GPIO_Mode_AF;
	SPI1_pins.GPIO_Speed = GPIO_Speed_2MHz;
	SPI1_pins.GPIO_OType = GPIO_OType_PP;
	SPI1_pins.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &SPI1_pins);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	
	GPIO_InitTypeDef SPI1_CS;
	SPI1_CS.GPIO_Pin = GPIO_Pin_4;
	SPI1_CS.GPIO_Mode = GPIO_Mode_OUT;
	SPI1_CS.GPIO_Speed = GPIO_Speed_2MHz;
	SPI1_CS.GPIO_OType = GPIO_OType_PP;
	SPI1_CS.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &SPI1_CS);
	
	CS1_OFF();
	
	
	SPI_InitTypeDef SPI1_encoder;
	SPI1_encoder.SPI_Direction = SPI_Direction_2Lines_FullDuplex ;
	SPI1_encoder.SPI_Mode = SPI_Mode_Master;
	SPI1_encoder.SPI_DataSize = SPI_DataSize_16b; 
	SPI1_encoder.SPI_CPOL = SPI_CPOL_Low;
	SPI1_encoder.SPI_CPHA = SPI_CPHA_2Edge; 
	SPI1_encoder.SPI_NSS = SPI_NSS_Soft;
	SPI1_encoder.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;//SPI_BaudRatePrescaler_8 ;
	SPI1_encoder.SPI_FirstBit =  SPI_FirstBit_MSB;
	SPI1_encoder.SPI_CRCPolynomial = 7; //??????????????????????????????????????????????????????
	
	SPI_Init(SPI1, &SPI1_encoder);
	SPI_Cmd(SPI1, ENABLE);
	
	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
}

void SPI3_init(void) {
	//PC10 - CLCK
	//PC11 - MISO
	//PC12 - MOSI
	//PC9 - CS
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_SPI3, ENABLE);
	
	GPIO_InitTypeDef SPI3_pins;
	SPI3_pins.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
	SPI3_pins.GPIO_Mode = GPIO_Mode_AF;
	SPI3_pins.GPIO_Speed = GPIO_Speed_2MHz;
	SPI3_pins.GPIO_OType = GPIO_OType_PP;
	SPI3_pins.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOC, &SPI3_pins);
	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_SPI3);
	
	GPIO_InitTypeDef SPI3_CS;
	SPI3_CS.GPIO_Pin = GPIO_Pin_9;
	SPI3_CS.GPIO_Mode = GPIO_Mode_OUT;
	SPI3_CS.GPIO_Speed = GPIO_Speed_2MHz;
	SPI3_CS.GPIO_OType = GPIO_OType_PP;
	SPI3_CS.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &SPI3_CS);
	
	CS3_OFF();
	
	
	SPI_InitTypeDef SPI3_encoder;
	SPI3_encoder.SPI_Direction = SPI_Direction_2Lines_FullDuplex ;
	SPI3_encoder.SPI_Mode = SPI_Mode_Master;
	SPI3_encoder.SPI_DataSize = SPI_DataSize_16b; 
	SPI3_encoder.SPI_CPOL = SPI_CPOL_Low;
	SPI3_encoder.SPI_CPHA = SPI_CPHA_2Edge; 
	SPI3_encoder.SPI_NSS = SPI_NSS_Soft;
	SPI3_encoder.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;//SPI_BaudRatePrescaler_8 ;
	SPI3_encoder.SPI_FirstBit =  SPI_FirstBit_MSB;
	SPI3_encoder.SPI_CRCPolynomial = 7; //??????????????????????????????????????????????????????
	
	SPI_Init(SPI3, &SPI3_encoder);
	SPI_Cmd(SPI3, ENABLE);
	
	SPI_NSSInternalSoftwareConfig(SPI3, SPI_NSSInternalSoft_Set);
}
