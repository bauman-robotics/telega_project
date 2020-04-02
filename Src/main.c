/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "cobs.h"
#include <string.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define BUF_SIZE_UPLEVEL	11								// 9 databyte + 2 byte overhead
#define BUF_SIZE_DRV			6
#define BUF_SIZE_DRV_SEND	7

uint8_t buf_uplevel[BUF_SIZE_UPLEVEL];			// uint8_t code + float (angle_speed + linear_speed)
uint8_t buf_drv1[BUF_SIZE_DRV];							// float speed
uint8_t buf_drv2[BUF_SIZE_DRV];							// float speed
uint8_t buf_drv_send[BUF_SIZE_DRV_SEND];					// uint8_t code + float speed

uint8_t buf_to_uplevel[BUF_SIZE_UPLEVEL-2];					//		uint8_t code + float (angle_speed + linear_speed)
uint8_t buf_to_uplevel_send[BUF_SIZE_UPLEVEL];					// uint8_t code + float (angle_speed + linear_speed): 9 databyte + 2 byte overhead

int uart_uplevel_ready, uart_to_uplevel_ready, uart_drv1_ready, uart_drv2_ready;
int uart_uplevel_send, uart_to_uplevel_send, uart_drv_send;

float	pos_drv1, pos_drv2;
uint32_t count_recieve = 0;
uint32_t count_send = 0;
float	speed_l= 0.0f;
float	speed_a= 0.0f;
float	speed_l_up = 0.0f;
float	speed_a_up = 0.0f;
float speed_drv1 =0.0f;
float speed_drv2 =0.0f;
float path_of_1 = 0.0f;
float path_of_2 = 0.0f;

const float width_platform = 1.0f;  // need precise width, in meters
const float wheel_radius = 0.05f;  // need precise radius, in meters


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART2->CR1 |= USART_CR1_RXNEIE;
	USART3->CR1 |= USART_CR1_RXNEIE;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	uint8_t buf_uplevel_decoded[BUF_SIZE_UPLEVEL - 2];
	uint8_t buf_drv_decoded[BUF_SIZE_DRV - 2];
	uint8_t buf_drv_send_decoded[BUF_SIZE_DRV_SEND - 2];

	uint8_t code;

	int DEBUG = 0;
	if (DEBUG)
	{
		
	}
	
	speed_l = 0.0f;
  while (1)
 {
	  if (DEBUG)
	  {
			
	  }
		if (uart_uplevel_ready == 1)
		{
			uart_uplevel_ready = 0; 
			cobs_decode(buf_uplevel, BUF_SIZE_UPLEVEL, buf_uplevel_decoded);
			
			code = buf_uplevel_decoded[0];
			memcpy(&speed_l, buf_uplevel_decoded + sizeof(uint8_t), sizeof(float));
			memcpy(&speed_a, buf_uplevel_decoded + sizeof(uint8_t) + sizeof(float), sizeof(float));
	
			speed_drv1 = (2*speed_l - speed_a*width_platform)/(2*wheel_radius);
			speed_drv2 = (2*speed_l + speed_a*width_platform)/(2*wheel_radius);			
			
			if (speed_drv1 > 1.0) speed_drv1 = 1.0;
			if (speed_drv1 < -1.0) speed_drv1 = -1.0;
			if (speed_drv2 > 1.0) speed_drv2 = 1.0;
			if (speed_drv2 < -1.0) speed_drv2 = -1.0;
						
			uart_drv_send = 1;
			
			if (DEBUG)
			{
				count_recieve ++;
			}
		}
		 
		if (uart_drv1_ready == 1 && uart_drv2_ready == 1)
		{
			uart_drv1_ready = 0;
			uart_drv2_ready = 0;						
			
			speed_a_up = (speed_drv2 - speed_drv1)*wheel_radius/width_platform;
			speed_l_up = (speed_drv1 + speed_drv2)*wheel_radius/2;
			
			buf_to_uplevel[0] = 'v';
			memcpy(buf_to_uplevel + 1, &speed_a_up, sizeof(float));
			memcpy(buf_to_uplevel + 5, &speed_l_up, sizeof(float));
			cobs_encode(buf_to_uplevel, BUF_SIZE_UPLEVEL - 2, buf_to_uplevel_send);			
			HAL_UART_Transmit(&huart1, buf_to_uplevel_send, BUF_SIZE_UPLEVEL, 0x0FFF);
			 
			buf_to_uplevel[0] = 'o';
			memcpy(buf_to_uplevel + 1, &path_of_1, sizeof(float));
			memcpy(buf_to_uplevel + 5, &path_of_2, sizeof(float));
			cobs_encode(buf_to_uplevel, BUF_SIZE_UPLEVEL - 2, buf_to_uplevel_send);			
			HAL_UART_Transmit(&huart1, buf_to_uplevel_send, BUF_SIZE_UPLEVEL, 0x0FFF);
		}
		
		if (uart_drv1_ready == 1)
		{
			cobs_decode(buf_drv1, BUF_SIZE_DRV, buf_drv_decoded);
			memcpy(&pos_drv1, buf_drv_decoded, sizeof(float));
			path_of_1 += pos_drv1*wheel_radius;
		
			// TODO add math model
			//cobs_encode(buf_drv_decoded, sizeof(float), buf_drv1);
			//HAL_UART_Transmit(&huart1, buf_drv1, BUF_SIZE_DRV, 0x0FFF);
		}

		if (uart_drv2_ready == 1)
		{
			cobs_decode(buf_drv2, BUF_SIZE_DRV, buf_drv_decoded);
			memcpy(&pos_drv2, buf_drv_decoded, sizeof(float));		
			path_of_2 += pos_drv2*wheel_radius;
			
			//HAL_UART_Transmit(&huart1, buf_drv2, BUF_SIZE_DRV, 0x0FFF);
		}
		
		if (uart_drv_send)
		{
			uart_drv_send = 0;
			
			buf_drv_send_decoded[0] = 'v';
			memcpy(buf_drv_send_decoded + 1, &speed_drv1, sizeof(float));
			cobs_encode(buf_drv_send_decoded, BUF_SIZE_DRV_SEND - 2, buf_drv_send);
			HAL_UART_Transmit(&huart2, buf_drv_send, BUF_SIZE_DRV_SEND, 0x0FFF);
			
			buf_drv_send_decoded[0] = 'v';
			memcpy(buf_drv_send_decoded + 1, &speed_drv2, sizeof(float));
			cobs_encode(buf_drv_send_decoded, BUF_SIZE_DRV_SEND - 2, buf_drv_send);
			HAL_UART_Transmit(&huart3, buf_drv_send, BUF_SIZE_DRV_SEND, 0x0FFF);
			count_send ++;
		}
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
 }
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;

  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)   
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
