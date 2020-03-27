#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "joystick.h"
#include "robot_defines.h"
#include "easy_serial.h"
#include "360_controller_map.h"
#include "sensors.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

unsigned char map_stick(short input)
{
  //printf("%li", map(input, SHRT_MIN, SHRT_MAX, -127, 127));
  return map(input, SHRT_MIN, SHRT_MAX, 255, 0); //centerpoint @ 127;
}

void button_update(struct js_event *jse, int *button_update_array)
{
	button_update_array[jse->number] = jse->value;
	return;
}

void axis_update(struct js_event *jse, int *axis_update_array)
{
	axis_update_array[jse->number] = jse->value;
	return; 
}

int  send_button_updates(int *old_button_array, int *new_button_array, int send_port, int receive_port)
{
	int i = 0;
	for(i = 0; i < BUTTON_COUNT; i++)
		if(new_button_array[i] != old_button_array[i])
		{
			update_button(i, new_button_array[i], send_port, receive_port);
			old_button_array[i] = new_button_array[i];
		}
	return 0;
}
int  send_axis_updates(int *old_axis_array, int *new_axis_array, int send_port)
{
	int i = 0;
	for(i = 0; i < AXIS_COUNT; i++)
		if(new_axis_array[i] != old_axis_array[i])
		{
			update_axis(i, new_axis_array[i], send_port);
			old_axis_array[i] = new_axis_array[i];
		}
	return 0;
}

int send_command(unsigned char *flag, unsigned char *value, int send_port)
{
	unsigned char received = 0;
	clearPort(send_port);
	write(send_port, flag, 1);
	write(send_port, value, 1);
//	while(received != ARDUINO_RECEIVED_BYTE);
//		read(receive_port, &received, 1);
	return 0;
}

int update_button(int button, int button_state, int send_port, int receive_port)
{
	unsigned char flag = 0;
	char value = 0;
	char buffer[512] = "";

	switch(button)
	{
		case BUTTON_LEFT_BUMPER:
			flag = LEFT_MOTOR_FLAG;
			if(button_state == 1)
			{
				value = 255;
				printf("Driving left motor.\n");
				send_command(&flag, &value, send_port);//do left bumper pressed thing
			}
			if(button_state == 0)
			{
				value = 127;
				send_command(&flag, &value, send_port);//do left bumper released things
			}
			break;
		case BUTTON_RIGHT_BUMPER:
			flag = RIGHT_MOTOR_FLAG;
			if(button_state == 1)
			{
				value = 255;
				printf("Driving right motor.\n");
				send_command(&flag, &value, send_port);//do left bumper pressed thing
			}
			if(button_state == 0)
			{
				value = 127;
				send_command(&flag, &value, send_port);		
			}
			break;
		case BUTTON_A:
			flag = SERVO_CLAW_RAISE_TAG;
			if(button_state == 1)
			{
                value = 0;
                printf("Lowering claw.\n");
                send_command(&flag, &value, send_port);//do A button pressed thing
            }
			break;
		case BUTTON_Y:
            flag = SERVO_CLAW_RAISE_TAG;
            if(button_state == 1)
            {
                value = 255;
                printf("Raising claw.\n");
                send_command(&flag, &value, send_port);//do Y button pressed thing
            }
			break;
		case BUTTON_X:
            flag = SERVO_CLAW_CLOSE_TAG;
            if(button_state == 1)
            {
                value = 255;
                printf("Closing claw.\n");
                send_command(&flag, &value, send_port);//do A button pressed thing
            }
			break;
        case BUTTON_B:
            flag = SERVO_CLAW_CLOSE_TAG;
            if(button_state == 1)
            {
                value = 0;
                printf("Opening claw.\n");
                send_command(&flag, &value, send_port);//do Y button pressed thing
            }
			break;
        case BUTTON_BACK:
            flag = LEFT_MOTOR_STEPS_FLAG;
            if(button_state == 1)
            {
                int steps = 400;
                int seconds = 2;
                printf("\nMoving %i(%x) steps in %i(%x) seconds.\n", steps, steps, seconds, seconds);
                int n = write(send_port, &flag, 1);
                n = n + write(send_port, &steps, sizeof(steps));
                n = n + write(send_port, &seconds, sizeof(seconds));
                printf("Wrote %i bytes.\n", n);
             }
			break;
        case BUTTON_START:
            flag = RIGHT_MOTOR_STEPS_FLAG;
            if(button_state == 1)
            {
                int steps = 400;
                int seconds = 2;
                printf("\nMoving %i(%x) steps in %i(%x) seconds.\n", steps, steps, seconds, seconds);
                int n = write(send_port, &flag, 1);
                n = n + write(send_port, &steps, sizeof(steps));
                n = n + write(send_port, &seconds, sizeof(seconds));
                printf("Wrote %i bytes.\n", n);
             }
			break;
        case BUTTON_XBOX:
            flag = SENSOR_REQUEST;
            if ( button_state == 1 )
            {
                printf("Requesting sensor input\n");
                poll_sensors( send_port, receive_port );
            }
            break;
	}
    //printf("\33[2K"); //clear the line
    fflush(stdout); //flush the buffer
	return 0;
}
		
int update_axis(int axis, int axis_value, int send_port)
{
	unsigned char flag = 0;
	unsigned char value = 0;
	switch(axis)
	{
		case AXIS_LEFT_STICK_VERTICAL:
			flag = LEFT_MOTOR_FLAG;
			value = map_stick(axis_value);
			if(value > 127 && (value - DEADZONE) < 127) //keeps stuff in the deadzone from being sent.
				value = 127;
			if(value < 127 && (value + DEADZONE) > 127)
				value = 127; 
			printf("Driving left motor to speed: %i\n", value);
			send_command(&flag, &value, send_port);//do left stick up down thing
			break;
		case AXIS_RIGHT_STICK_VERTICAL:
			flag =RIGHT_MOTOR_FLAG;
			value = map_stick(axis_value);
			if(value > 127 && (value - DEADZONE) < 127) //keeps stuff in the deadzone from being sent.
				value = 127;
			if(value < 127 && (value + DEADZONE) > 127)
				value = 127; 
			printf("Driving right motor to speed: %i\n", value);
			send_command(&flag, &value, send_port);//do right stick up down thing
			break;
	}
	return 0;
    fflush(stdout);
}		



/* a little test program */
int main(int argc, char *argv[])
{
	int  joy_file, received, send_port, receive_port; // file IDs for the joy, in serial, and out serial ports
	char joy_address[32] = "/dev/input/js0";
    char buffer[512] = "";
	int  old_axis_values[8] = {0};     // intialize all buttons to "off" (0) this array is check edagainst for button updates and if an update is found the update is sent. Axis stuff is the same
	int  old_button_values[11] = {0};  // array as mentioned above     
	int  new_button_values[11] = {0};  // just look above 
	int  new_axis_values[8] = {0};     // just look above the above 
		
	struct js_event jse;               // stores the joystick data


	if(argc > 2)
	{
		printf("Too many arguments, exiting."); // only one arg for the time being. 
		exit(1);
	}
	if(argc == 2)
	{
		strcpy(joy_address, argv[1]);
		joy_file = open_joystick(joy_address); // sets the joystick to attach to, assumes that the arduino is mapped as seen in the ROBOT_DEFINITIONS.h
	}
	else if(argc == 1)
	{
		joy_file = open_joystick(joy_address); // if not specified use js0
	}
	
	if (joy_file < 0) 
	{
        while(joy_file < 0)
        {
		    printf("Joystick open failed, trying again in 1 sec.\n"); // a thing is broken and you should stop
            sleep(1);
		    open_joystick(joy_address);
        }
	}

	send_port = serialport_init(ARDUINO_COMM_LOCATION, ROBOT_BAUDRATE); // attempts to open the connection to the arduino with the BAUDRATE specified in the ROBOT_DEFINITIONS.h
	
	
	if(send_port < 0)
	{
        while(send_port < 0)
        {
		    printf("Can't open serial port, trying again in 1 sec.\n"); // arduino not located, please stop breaking things
		    sleep(1);
            send_port = serialport_init(ARDUINO_COMM_LOCATION, ROBOT_BAUDRATE);
        }
	}
	clearPort(send_port);
	printf("send_port = %d\n", send_port );

	receive_port = serialport_init(SENSORS_COMM_LOCATION, ROBOT_BAUDRATE );
	if(receive_port < 0)
	{
		while(receive_port < 0)
		{
			printf("can't open receive_port\n");
			sleep(1);
			receive_port = serialport_init(SENSORS_COMM_LOCATION, ROBOT_BAUDRATE );
		}
	}

	clearPort(receive_port);
	printf("receive_port = %d\n", receive_port );

	while (1) {
		received = read_joystick_event(&jse); // check for a joystick update
		//printf("Reading...\n");
		//usleep(1000); // check for updates every 1mS
		if (received == 1) { // if an update is available
			switch(jse.type)
			{
				case TYPE_BUTTON:
					//printf("NOT_BUTTON\n");
					button_update(&jse, new_button_values); // update teh new button array
					break;	
				case TYPE_NOT_BUTTON:
					//printf("BUTTON\n");
					axis_update(&jse, new_axis_values); // udpate the new axis values array
					break;
			}	
		}
		send_button_updates(old_button_values, new_button_values, send_port, receive_port); // checks bot the old and new button arrays for differences, if it finds one then an update is sent
		send_axis_updates(old_axis_values, new_axis_values, send_port); // ditto from above
		usleep(1000);
        int n = read(receive_port, &buffer, sizeof(buffer));

        if(n > 0)
        {
            buffer[n] = '\0';
            printf("buffer (%d bytes):\n==================\n%s\n==================\nEnd buffer. Yay.\n", n, buffer);  // print the part of the buffer that had stuff in it
            fflush(stdout);
        }
	}
}

