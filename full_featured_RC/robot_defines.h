#ifndef __ROBOT_DEFINES_
#define __ROBOT_DEFINES_


// motor defines
#define LEFT_MOTOR_FLAG  0x4C
#define RIGHT_MOTOR_FLAG 0x52
#define LEFT_MOTOR_STEPS_FLAG  0x39
#define RIGHT_MOTOR_STEPS_FLAG 0x40
#define SERVO_CLAW_CLOSE_TAG   0x41
#define SERVO_CLAW_RAISE_TAG   0x42

//communication defines
#define ROBOT_BAUDRATE 57600
#define ARDUINO_COMM_LOCATION "/dev/robot/arduino"
#define ARDUINO_RECEIVED_BYTE 0x13


#define SENSOR_REQUEST 0x37
#endif
