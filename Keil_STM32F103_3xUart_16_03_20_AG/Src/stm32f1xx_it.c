/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "stm32f1xx_it.h"
#include "cobs.h"


/* USER CODE BEGIN 0 */
extern uint8_t buffer[10];
extern int dr_count;
extern int dr_count_saved;
extern int check_uart;
uint8_t dr_data;
extern uint8_t buffer2[5];
extern int dr_count2;
extern int dr_count_saved2;
extern int check_uart2;
uint8_t dr_data2;
extern uint8_t buffer3[5];
extern int dr_count3;
extern int dr_count_saved3;
extern int check_uart3;
uint8_t dr_data3;
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/******************************************************************************/
/*            Cortex-M3 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Prefetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles USART1 global interrupt.
*/
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	//int i;
if (USART1->SR&USART_SR_RXNE) // проверяю случились ли прерывания из-за того что что-то поступило в дата регистр
	{
		dr_data=USART1->DR; // беру значение из дата регистра 
		if ((buffer[dr_count-1] == 13)||((buffer[dr_count-1]>=48)&&(buffer[dr_count-1]<=57))||(buffer[dr_count-1]==65))
		{
			check_uart=1;  // ставлю флаг который проверяется условием в main
			dr_count_saved=dr_count; // когда пришло значение которое мне нужно, я запоминаю сколько занятых мест в массиве
			dr_count=0; // обнуляю индекс масива    
		}
		else 
        {
		    buffer[dr_count]=dr_data; // пишу в массив данные из дата регистра 
			dr_count=dr_count+1; //увеличиваю индекс, в начале у меня индекс 0
		}
	}
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

void USART2_IRQHandler(void)
{
	static uint8_t res_buf_cnt;
  /* USER CODE BEGIN USART2_IRQn 2 */
	//int i;
if (USART2->SR&USART_SR_RXNE) // проверяю случились ли прерывания из-за того что что-то поступило в дата регистр
	{
			USART_ClearITPendingBit(USART2, USART_IT_RXNE);
			receive_buffer[res_buf_cnt] = USART_ReceiveData(USART2);
				
				if(receive_buffer[res_buf_cnt] == 0x00) {
						res_buf_cnt = 0;
					return;
				}
				res_buf_cnt++;

//						dr_data2=USART2->DR; // беру значение из дата регистра 
//		if ((buffer2[dr_count-1] == 13)||((buffer2[dr_count-1]>=48)&&(buffer2[dr_count-1]<=57))||(buffer2[dr_count-1]==65))
//		{
//			check_uart2=1;  // ставлю флаг который проверяется условием в main
//			dr_count_saved2=dr_count; // когда пришло значение которое мне нужно, я запоминаю сколько занятых мест в масиве
//			dr_count=0; // обнуляю индекс массива    
//		}
//		else 
//        {
//		    buffer2[dr_count]=dr_data2; // пишу в массив данные из дата регистра 
//			dr_count=dr_count+1; //увеличиваю индекс, в начале у меня индекс 0
//		}
		
		cobs_decode(receive_buffer, 6, tmp_mass);
        cmd.mode = tmp_mass[0];
		memcpy(&(cmd.data), &tmp_mass[1], 4);
	}
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 2 */

  /* USER CODE END USART2_IRQn 2 */
}

void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 3 */
	//int i;
		static uint8_t res_buf_cnt;

if (USART3->SR&USART_SR_RXNE) // проверяю случились ли прерывания из-за того что что-то поступило в дата регистр
	{
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
			receive_buffer[res_buf_cnt] = USART_ReceiveData(USART2);
				
				if(receive_buffer[res_buf_cnt] == 0x00) {
						res_buf_cnt = 0;
					return;
				}
				res_buf_cnt++;
		
		
//		dr_data3=USART3->DR; // беру значение из дата регистра 
//		if ((buffer3[dr_count-1] == 13)||((buffer3[dr_count-1]>=48)&&(buffer3[dr_count-1]<=57))||(buffer3[dr_count-1]==65))
//		{
//			check_uart3=1;  // ставлю флаг который проверяется условием в main
//			dr_count_saved3=dr_count; // когда пришло значение которое мне нужно, я запоминаю сколько занятых мест в массиве
//			dr_count=0; // обнуляю индекс массива    
//		}
//		else 
//        {
//		    buffer3[dr_count]=dr_data3; // пишу в массив данные из дата регистра 
//			dr_count=dr_count+1; //увеличиваю индекс, в начале у меня индекс 0
//		}
	}
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 3 */

  /* USER CODE END USART3_IRQn 3 */
}
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
