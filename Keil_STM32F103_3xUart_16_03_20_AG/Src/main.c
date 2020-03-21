/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "cobs.h"


/* USER CODE BEGIN Includes */
 uint8_t buffer[10];
 uint8_t buffer2[5];
 uint8_t buffer3[5];
  static uint8_t tmp_mass[5];

 int dr_count, dr_count_saved, dr_count2, dr_count_saved2, dr_count3, dr_count_saved3;
 int check_uart, check_uart2, check_uart3;
 int j=0;
 volatile int saved_number;
 int uart_number;
 int multiplayer=1;
 int ch=1;
 float L_vel_left = 0,					// актуальная v левого колеса
			L_vel_right = 0,
			L_vel_left_des = 0,				// желаемая v левого колеса
			L_vel_right_des = 0,
			tmp,											// еще буфер
			W_vel = 0, 
			x_pos = 0, 
			y_pos = 0,
			angle_left = 0,
			angle_right = 0,
			path_of_left = 0, 				// одометр левого колеса
			path_of_right = 0,
			R_wheel = 0.05; // например
 
 
 uint8_t transmitBuffer[1];
 uint8_t recieved_word=0;
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
//float ODOMETER(float);													
//float PATH_TO_COORDINATES(int, float, float);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void send_to_uart(uint8_t data) {						// USART 1 к Rpi, USART 2 3 - драйвера, STM32F103 to rule them all

while(!(USART1->SR & USART_SR_TC)); 

USART1->DR=data; //UART

} 
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

	uint8_t sp1 = 160;
    uint8_t sp1_2 = 115;
	uint8_t sp2 = 1;
	uint8_t u_buf1[1]; 
	uint8_t u_buf2[1]; 
 int test_num=0;
 int count=0;
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
    u_buf1[0] = 0x30;
    u_buf2[0] = 0x30;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();

  /* USER CODE BEGIN 2 */
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);  // Включаю прерывания по приему данных в дата регистр 
  __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
  __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);

	
/*	for (unsigned char i = 0; i < 32; i++)
  {
    transmitBuffer[i] = i + 1;
  }*/ 
   

	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if (check_uart==1)  // проверяю флаг который меняется в stm32xx_it.c в USART1_IRQHandler (начиная с 195 строки)
		{
			for(j=0;j<dr_count_saved;j++) //dr_count переменная, значение которой я беру из stm32xx_it.c в USART1_IRQHandler
			{
				if (((buffer[j] != 0)&&(buffer[j] != 13)&&(buffer[j]>=48)&&(buffer[j]<=57))||(buffer[j]==65))
				{
					recieved_word=buffer[j]; // берем нужное нам значение 
				}
/*				if ((buffer[j] != 0)&&(buffer[j] != 13))
        {
					uart_number=uart_number+multiplayer*(buffer[j]-48);  // если мы принимаем цифру 
					multiplayer=multiplayer*10;
				*/
				
			}
			 multiplayer=1;
			 check_uart=0;
			// saved_number=uart_number;  // для цифры 
			// uart_number=0;
			 USART1->DR=0;
			 for(j=0;j<9;j++) {buffer[j]=0;}
			 
			 if (recieved_word!=0) // когда мы подключились к bluetooth модулю 
			 {
				 transmitBuffer[0]=recieved_word; 
				 switch (recieved_word)
				 {
				 case 0x31:			 	 
					u_buf1[0] = sp1;
					u_buf2[0] = ((uint8_t)((double)sp1)*0.91);
					break;
				 case 0x32:			 
					u_buf1[0] = 1;
					u_buf2[0] = 1;			
					break;
				 case 0x34:
					u_buf1[0] = sp1*0.85;
					u_buf2[0] = ((uint8_t)((double)sp1)*0.91);	 
					break;
				 case 0x33:
					u_buf1[0] = sp1;
					u_buf2[0] = sp1*0.91*0.85;				 
					break;
				 case 0x37:
					 sp1 = 200; 
					 break;
				 case 0x38:			 
					 sp1 = 180;
					 break;
				 case 0x39:			 
					 sp1 = 160;
					 break; 
         case 'L':																	// прием линейной v тележки
					memcpy(&L_vel_left_des, &buffer[0], 4);		
					memcpy(&L_vel_right_des, &buffer[0], 4);
					case 'W':
					memcpy(&tmp, &buffer[0], 4);							// прием угловой v тележки
					L_vel_left_des += tmp;
					L_vel_right_des -= tmp;
					//x_pos = PATH_TO_COORDINATES(1, path_of_left, path_of_right);		// на будущее
					//y_pos = PATH_TO_COORDINATES(2, path_of_left, path_of_right);
					//memcpy(&u_buf1[0], &x_pos, 4);
					//memcpy(&u_buf2[0], &y_pos, 4);
                }
				 
				 //HAL_UART_Transmit_IT(&huart2, transmitBuffer ,1); //отправляем данные по 2 уарту 
				 HAL_UART_Transmit(&huart2, u_buf1, 1, 100); //отправляем данные по 2 уарту 
				 HAL_UART_Transmit(&huart3, u_buf2, 1, 100); //отправляем данные по 3 уарту 
				 HAL_Delay(100);  // отправка 10 раз в секунду 
			}
			 
  }
  /* USER CODE END WHILE */

      
        // }
  /* USER CODE BEGIN 3 */
				if (check_uart2==1)  // проверяю флаг который меняется в stm32xx_it.c в USART1_IRQHandler (начиная с 195 строки)
		{
			cobs_decode(buffer2, 6, tmp_mass);
			memcpy(&tmp, &tmp_mass[1], 4);
			if (tmp+angle_left >= 360) angle_left -= 360;
			path_of_left = path_of_left + (tmp - angle_left)*R_wheel;
			angle_left = tmp;
			 check_uart2=0;
						 USART2->DR=0;
			 for(j=0;j<6;j++) {buffer2[j]=0;}			 
  }
			 
  }
	
		if (check_uart3==1)  // проверяю флаг который меняется в stm32xx_it.c в USART1_IRQHandler (начиная с 195 строки)
		{
			cobs_decode(buffer3, 6, tmp_mass);
			memcpy(&tmp, &tmp_mass[1], 4);
			if (tmp+angle_right >= 360) angle_right -= 360;
			path_of_right = path_of_right + (tmp - angle_right)*R_wheel;
			angle_right = tmp;
			 check_uart3=0;
						 USART3->DR=0;
			 for(j=0;j<6;j++) {buffer3[j]=0;}			 
  }	
	
}
  /* USER CODE END 3 */



/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
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

}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
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

}

/* USART3 init function */
static void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
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

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
