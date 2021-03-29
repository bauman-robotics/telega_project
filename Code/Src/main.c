#include "main.h"

#define size_buf 10

float des_val=0;
float v_vala = 0.00;
float sine_desval[SINE_STEPS];
float Kp=0.3, Kd=50, Ki=0.0002;

float fl_uart_send = 0.0;
uint8_t count_uart_send = 0;

STATUS uart_data_ready, cmd_ready, is_sm_chosen = not_ready;
uint8_t receive_buffer[size_buf];
CQ_average_filter_typedef AngleFilter;
Mode sys_mode = CALIBRATION;
CMD cmd;

uint8_t flag_10_ms = 0; // debug
float angle; // debug
uint8_t angel_1b = 0; // debug
uint8_t angle_to_encoded[4];
uint8_t angle_encoded[6];
uint8_t v_vala_encoded[6];
uint8_t v_vala_to_encoded[4];

uint16_t sm_receive_time, sm_receive_vel; // FOR SMOOTH ACCELERATION
float sm_des_time=1, sm_des_vel=0, sm_des_pos=0, sm_step_inc, L_vel = 0, W_vel = 0, x_pos = 0, y_pos = 0, path_of_left = 0, path_of_right = 0, transfer_time= 3.0, acceleration = 0;
uint16_t sm_counter=0;

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
if (flag_10_ms) {
// angel_1b = (uint8_t)angle;
// UART_2_Send_Byte(angel_1b);

memcpy(angle_to_encoded, &angle, 4);
cobs_encode(angle_to_encoded, 4, angle_encoded);
SendStrz((char *)angle_encoded);
// UART_2_Send_Byte(0);
flag_10_ms = 0;
}
}
}
/***************************************/

void BIG_INIT(void) {
SPI3_init(); // Encoder
TIM5_init(); // Delay timer
TIM1_init(); // init PWM timer
TIM4_init(); // PWM LED Visualisation timer
GPIO_init();
FOC_InitPosition(&AngleFilter, sys_mode);
fill_sine(sine_desval, SINE_STEPS);
TIM2_init(); // Timer for setting desired sine point
TIM7_init(); // FOC start
USART_2_init();
}

void Set_inc_freq(uint32_t freq) {
TIM2->ARR = freq;
TIM2->CNT = 0;
}
uint8_t tmp_mass[5];

void CMD_processing(void) {
// COBS
// static uint8_t replace;
 static uint8_t tmp_mass[5];
 //static uint8_t tmp_mass1[7];

if(uart_data_ready) {
                                uart_data_ready = not_ready;
        cobs_decode(receive_buffer, 6, tmp_mass);
        cmd.mode = tmp_mass[0];
                cmd_ready = ready;
                if (cmd.mode == 'g')
{/*
        if (is_sm_chosen == not_ready) // one execution
{
is_sm_chosen = ready;
//memcpy(&tmp_mass[1], &(cmd.data), 4); */
sm_receive_time = tmp_mass[2] << 8 | tmp_mass[1];
sm_receive_vel = tmp_mass[4] << 8 | tmp_mass[3];

sm_des_time = sm_receive_time*0.01; /* float time & vel were packed as int due to compress them into 4 bytes, it's an unpacking here */
sm_des_vel = (float)sm_receive_vel*0.00036;
sm_step_inc = 0.001*(sm_des_vel-v_vala)/sm_des_time;
sm_counter=0;
  //}
}
								else if (cmd.mode == 'G')
									{
										memcpy(&(cmd.data), &tmp_mass[1], 4);
										sm_des_time = transfer_time;
										sm_des_vel = cmd.data*0.036;
										sm_step_inc = 0.001*(sm_des_vel-v_vala)/sm_des_time;
									}
									else if (cmd.mode == 'P')
									{
										memcpy(&(cmd.data), &tmp_mass[1], 4);
										sm_des_time = transfer_time;
										sm_des_pos = cmd.data;
										 acceleration = 8*(sm_des_pos/2-des_val)/(sm_des_time*sm_des_time);
										v_vala = 0;
										sm_step_inc = 0.002*acceleration; 
										
									}
								else {memcpy(&(cmd.data), &tmp_mass[1], 4);}
}
}

void CMD_execution(void) {
static uint32_t tmp;

if(cmd_ready) {
cmd_ready = not_ready;
switch (cmd.mode) {
//case 'd':
case 'a': //03.02
        sys_mode = DISABLED;
        is_sm_chosen = not_ready;
        //break;
case 'c':
__disable_irq();
sys_mode = CALIBRATION;
FOC_InitPosition(&AngleFilter, sys_mode);
sys_mode = DISABLED;
        is_sm_chosen = not_ready;
__enable_irq();
case 'p':
sys_mode = STATIC;
Set_inc_freq(INC_period - 1);
des_val = cmd.data;
        is_sm_chosen = not_ready;
break;

case 'P':
sys_mode = SMOOTH_POSITION_CONTROL;
Set_inc_freq(INC_period - 1);
break;

case 'v':
sys_mode = SPEED;
Set_inc_freq(INC_period - 1);
v_vala = 0.036 * cmd.data;
is_sm_chosen = not_ready;

break;
case 's':
sys_mode = SINE;
tmp = INC_period / cmd.data;
Set_inc_freq(tmp - 1);
is_sm_chosen = not_ready;
break;

case 'g':
sys_mode = SMOOTH_ACCEL;
Set_inc_freq(INC_period - 1);
break;

        //is_sm_chosen = ready;
case 'G':
sys_mode = SMOOTH_ACCEL_WITH_NEGATIVE_VELOCITY;
Set_inc_freq(INC_period - 1);
break;

case 't':
sys_mode = GOT_TIME;
transfer_time = cmd.data;

case 'L':
sys_mode = GOT_LINEAR_VEL;
L_vel = cmd.data;    
break;

case 'W':
sys_mode = GOT_ROUND_VEL;
W_vel = cmd.data; 
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
case

'6':
break;
}
}
}

/******** IRQHandlers ********/
void TIM2_IRQHandler(void) { // 100mcs
static uint16_t angle_counter;
static uint16_t time_counter;
if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
/*if (sys_mode != SMOOTH_ACCEL)
{
is_sm_chosen = not_ready;
sm_counter=0;
} */
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
        case (SMOOTH_ACCEL):
                if (((sm_des_vel > v_vala)&&(sm_step_inc>0))||((sm_des_vel < v_vala)&&(sm_step_inc<0))) // ((sm_des_vel >= v_vala)&&(sm_step_inc>0))||((sm_des_vel <= v_vala)&&(sm_step_inc<0))
                {
                        if (time_counter%10) // 1 ms
                        {
                                v_vala += sm_step_inc;
                                des_val += v_vala;
                                if (des_val > 360) des_val = 0.0;
                                sm_counter++;
                        }
                }
                else
                {
                        //uart_data_ready = ready;
                        sys_mode = SPEED;
                        cmd.mode = 'v';
                        //tmp_mass[0]='v';
//			memcpy(v_vala_to_encoded, &v_vala, 4);
//			cobs_encode(v_vala_to_encoded, 4, v_vala_encoded);
//			memcpy(&v_vala_encoded, &(receive_buffer[1]), 6);
                }
                break;
								
						case (SMOOTH_ACCEL_WITH_NEGATIVE_VELOCITY):
                if (((sm_des_vel > v_vala)&&(sm_step_inc>0))||((sm_des_vel < v_vala)&&(sm_step_inc<0))) // ((sm_des_vel >= v_vala)&&(sm_step_inc>0))||((sm_des_vel <= v_vala)&&(sm_step_inc<0))
                {
                        if (time_counter%10) // 1 ms
                        {
                                v_vala += sm_step_inc;
                                des_val += v_vala;
                                if (des_val > 360) des_val = 0.0;
                                sm_counter++;
                        }
                }
                else
                {
                        //uart_data_ready = ready;
                        sys_mode = SPEED;
                        cmd.mode = 'v';
                        //tmp_mass[0]='v';
//			memcpy(v_vala_to_encoded, &v_vala, 4);
//			cobs_encode(v_vala_to_encoded, 4, v_vala_encoded);
//			memcpy(&v_vala_encoded, &(receive_buffer[1]), 6);
//
                }
                break;
								
								case (SMOOTH_POSITION_CONTROL):
                if (((sm_des_pos > des_val)&&(sm_step_inc>0)&&(des_val <= sm_des_pos/2))||((sm_des_pos < des_val)&&(sm_step_inc<0)&&(des_val >= sm_des_pos/2))) 
                {
                        if (time_counter%10) // 1 ms
                        {
                                v_vala += sm_step_inc;
                                des_val += v_vala;
                                if (des_val > 360) des_val = 0.0;
                                sm_counter++;
                        }
                }
								else if (((sm_des_pos > des_val)&&(sm_step_inc>0)&&(des_val > sm_des_pos/2))||((sm_des_pos < des_val)&&(sm_step_inc<0)&&(des_val < sm_des_pos/2))) 
                {
                        if (time_counter%10) // 1 ms
                        {
                                v_vala -= sm_step_inc;
                                des_val += v_vala;
                                if (des_val > 360) des_val = 0.0;
                                sm_counter++;
                        }
                }
								else if (((sm_des_pos > des_val)&&(sm_step_inc < 0))||((sm_des_pos < des_val)&&(sm_step_inc>0))) 
                        {
                                v_vala = 0;
                                des_val = sm_des_pos;
                                sm_counter++;
                        }
												else  
                        {
                                v_vala = 0;
                                des_val = sm_des_pos;
                                sm_counter++;
                        }
                
                break;
default:
break;
}

time_counter ++;
if (time_counter > 100) {
time_counter = 0;
flag_10_ms = 1;
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
