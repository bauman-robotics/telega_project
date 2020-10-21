#include "main.h"

#define size_buf 10

float des_val;
float v_vala = 0.005;
float sine_desval[SINE_STEPS];
//float Kp=0.3, Kd=50, Ki=0.0002; ///
float Kp=0.2, Kd=10, Ki=0.0001;


float fl_uart_send = 0.0;
uint8_t count_uart_send = 0;

STATUS uart_data_ready, cmd_ready;
uint8_t receive_buffer[size_buf]; 
CQ_average_filter_typedef AngleFilter;
Mode sys_mode = CALIBRATION;
CMD cmd;

uint8_t flag_100_ms = 0; // debug
float angle;             // debug
uint8_t angel_1b = 0;    // debug
uint8_t angle_to_encoded[4];
uint8_t angle_encoded[6];

void BIG_INIT(void);
void Set_inc_freq(uint32_t freq);
void CMD_processing(void);
void CMD_execution(void);


/************* MAIN *****************/
int main(void) {
	static uint8_t calibrate_flag;
	BIG_INIT();
  des_val = CQ_average_angle(&AngleFilter);
	
	while(1) {
		CMD_processing();
		CMD_execution();
        if (flag_100_ms) {
  //          angel_1b = (uint8_t)angle; 
  //          UART_2_Send_Byte(angel_1b);
           
            memcpy(angle_to_encoded, &angle, 4);
            cobs_encode(angle_to_encoded, 4, angle_encoded);
            SendStrz((char *)angle_encoded);
          //  UART_2_Send_Byte(0);
            flag_100_ms = 0;            
      }
	}
}
/***************************************/

void BIG_INIT(void) {
	SPI3_init();	// Encoder
	TIM5_init(); 	// Delay timer   
	TIM1_init(); 	// init PWM timer
	TIM4_init(); 	// PWM LED Visualisation timer
	GPIO_init();
	FOC_InitPosition(&AngleFilter, sys_mode);
	fill_sine(sine_desval, SINE_STEPS);
	TIM2_init(); 	// Timer for setting desired sine point
	TIM7_init(); 	// FOC start
	USART_2_init();
}

void Set_inc_freq(uint32_t freq) {
	TIM2->ARR = freq;
	TIM2->CNT = 0;
}

	
void CMD_processing(void) {
	// COBS
//	static uint8_t replace;
	static uint8_t tmp_mass[5];
    static uint8_t tmp_mass1[7];
    
	if(uart_data_ready) {
		uart_data_ready = not_ready;
        cobs_decode(receive_buffer, 6, tmp_mass);
//		replace = receive_buffer[0];
//		for (uint8_t i = 1; i < size_buf; i++) {
//			if (i == replace) {
//				if (receive_buffer[replace] == 0x00) {
//					break;
//				}
//				tmp_mass[i-1] = 0x00;
//				replace = i + receive_buffer[i];
//			} else {
//				tmp_mass[i-1] = receive_buffer[i];
//			}
//		}
//		cmd.mode = tmp_mass[0];
//		memcpy(&(cmd.data), &tmp_mass[1], 4);
        
		cmd.mode = tmp_mass[0];
		memcpy(&(cmd.data), &tmp_mass[1], 4);        
		cmd_ready = ready;
        
  //      cobs_encode(tmp_mass, 5, tmp_mass1);  // work
  //      SendStr((char *)tmp_mass1);           // work     
        
	}

}

void CMD_execution(void) {
	static uint32_t tmp;
	if(cmd_ready) {
			cmd_ready = not_ready;
			switch (cmd.mode) {
				case 'd':
					sys_mode = DISABLED;
				case 'c':
					__disable_irq();
					sys_mode = CALIBRATION;
					FOC_InitPosition(&AngleFilter, sys_mode);
					sys_mode = DISABLED;
					__enable_irq();
				case 'p':
					sys_mode = STATIC;
					Set_inc_freq(INC_period - 1);
					des_val = cmd.data;
					break;
				case 'v':
					sys_mode = SPEED;
					Set_inc_freq(INC_period - 1);					
					v_vala = 0.036 * cmd.data;
					break;
				case 's':
					sys_mode = SINE;
					tmp = INC_period / cmd.data;
					Set_inc_freq(tmp - 1);
					break;
				case '1':
					Kp = cmd.data;
					break;
				case '2':
					Ki = cmd.data;
					break;
				case '3':
					Kd = cmd.data;
					break;
				case '4':
					break;
				case '5':
					break;
				case '6':
					break;
			}
		}
}


/******** IRQHandlers ********/
void TIM2_IRQHandler(void) { // 100mcs
	static uint16_t angle_counter;
    static uint16_t time_counter;
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {		
			
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
      
		switch (sys_mode){ 
		case (SPEED):
			des_val += v_vala;
			while (des_val >= 360 ) des_val -= 360.0; ///
			while (des_val < 0 ) des_val += 360.0;    ///
			break;       
		case (SINE):
			des_val = sine_desval[angle_counter++];
			if(angle_counter > (SINE_STEPS-1)) angle_counter=0;
			break;
		default:
			break;
		}
        
     time_counter ++;   
     if (time_counter > 100) {
        time_counter = 0;
        flag_100_ms = 1;
     } 
	}
}
 


void TIM7_IRQHandler(void){
	//static float angle, angle_error;
    static float angle_error;
	if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET) {		
			
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
		 
		if(sys_mode != DISABLED) {
			angle = CQ_average_angle(&AngleFilter);
			angle_error = des_val - angle;
			FOC(angle, angle_error, Kp, Kd, Ki); 
		} else {
			TIM4->CCR1 = 0; 
			TIM4->CCR2 = 0;
			TIM4->CCR3 = 0;

			TIM1->CCR1 = 0; 
			TIM1->CCR2 = 0;
			TIM1->CCR3 = 0;
		}
	}	
}
  
void USART2_IRQHandler() {
	static uint8_t res_buf_cnt;
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET) {
		
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
		
		receive_buffer[res_buf_cnt] = USART_ReceiveData(USART2);
	 	if(receive_buffer[res_buf_cnt] == 0x00) {
			res_buf_cnt = 0;
			uart_data_ready = ready;
			return;
		} 
		res_buf_cnt++;
	}
}
