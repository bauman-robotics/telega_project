#include "robot_defines.h"

#include <stdio.h>
#include <unistd.h>

#define IR_DISTANCE_SCALAR 0.5  //(0.5) for blue, anyways

double voltage_to_distance( int voltage )
{
    //where the input "voltage" is the returned ADC 10bit value
    // https://acroname.com/articles/linearizing-sharp-ranger-data
    return IR_DISTANCE_SCALAR * ( (6787.0)/(voltage - 3.0) - 4.0 );
}


void temporary_sensor_request( int send_port, int receive_port )
{
    unsigned char flag = SENSOR_REQUEST;
    char buffer[512] = "";
    int m = 0;

    int nothing = write( send_port, &flag, 1 );

    usleep(SENSOR_PROC_DELAY_US); // wait 2 ms for Arduino to receive flag and send back sensor input

    m = read( receive_port, &buffer, sizeof(buffer) );

    if( m > 0 )
    {
        buffer[m] = '\0';
        printf( "Buffer (%d bytes):\n=======\n%s\n=======\n", m, buffer );
        fflush(stdout);
    }
}

void poll_sensors( int send_port, int receive_port )
{
    //Arduino Mega is little-Endian
    char buffer[8] = "";
    unsigned char flag = SENSOR_REQUEST;

    unsigned short left = 0;
    unsigned short right = 0;
    unsigned short front = 0;
    unsigned short back = 0;

    unsigned char left_byte = 0;
    unsigned char right_byte = 0;

    int nothing = write( send_port, &flag, 1);
    usleep(SENSOR_PROC_DELAY_US);
    int n = read( receive_port, &buffer, sizeof(buffer) );

    //Odroid is little-Endian as well.
    left_byte = (unsigned char) buffer[0];
    right_byte = (unsigned char) buffer[1];
    left = left | left_byte;
    left = left << 8;
    left = left | right_byte;

    left_byte = (unsigned char) buffer[2];
    right_byte = (unsigned char) buffer[3];
    right = right | left_byte;
    right = right << 8;
    right = right | right_byte;

    left_byte = (unsigned char) buffer[4];
    right_byte = (unsigned char) buffer[5];
    front = front | left_byte;
    front = front << 8;
    front = front | right_byte;

    left_byte = (unsigned char) buffer[6];
    right_byte = (unsigned char) buffer[7];
    back = back | left_byte;
    back = back << 8;
    back = back | right_byte;

    printf("Front: %d (Centimeters: %f)\n", front, voltage_to_distance(front) );
    printf("Back: %d (Centimeters: %f)\n", back, voltage_to_distance(back) );
    printf("Left: %d (Centimeters: %f)\n", left, voltage_to_distance(left) );
    printf("Right: %d (Centimeters: %f)\n", right, voltage_to_distance(right) );
    printf("============\n");
}
