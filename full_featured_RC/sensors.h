#include "robot_defines.h"

#include <stdio.h>
#include <unistd.h>

int map_voltage_to_distance( int voltage )
{
    //where the input "voltage" is the returned ADC 10bit value
    // https://acroname.com/articles/linearizing-sharp-ranger-data
    return ( (6787)/(voltage - 3) - 4 );
}


void temporary_sensor_request( int serial_port )
{
    unsigned char flag = SENSOR_REQUEST;
    char buffer[512] = "";
    int m = 0;

    int nothing = write( serial_port, &flag, 1 );

    usleep(SENSOR_PROC_DELAY_US); // wait 2 ms for Arduino to receive flag and send back sensor input

    m = read( serial_port, &buffer, sizeof(buffer) );

    if( m > 0 )
    {
        buffer[m] = '\0';
        printf( "Buffer (%d bytes):\n=======\n%s\n=======\n", m, buffer );
        fflush(stdout);
    }
}

void poll_sensors( int serial_port )
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

    int nothing = write( serial_port, &flag, 1);
    usleep(SENSOR_PROC_DELAY_US);
    int n = read( serial_port, &buffer, sizeof(buffer) );

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

    printf("Front: %d\n", front );
    printf("Back: %d\n", back );
    printf("Left: %d\n", left );
    printf("Right: %d\n", right );
    printf("============\n");
}

int poll_left_sensor( int serial_port )
{
    unsigned char request_flag = LEFT_SENSOR_REQUEST;
    char buffer[2] = "";
    int n = 0;

    unsigned short value = 0;

    unsigned char left_byte = 0;
    unsigned char right_byte = 0;

    n = write( serial_port, &request_flag, 1 );
    usleep(SENSOR_PROC_DELAY_US);
    n = read( serial_port, &buffer, sizeof(buffer) );

    left_byte = (unsigned char) buffer[0];
    right_byte = (unsigned char) buffer[1];
    value = value | left_byte;
    value = value << 8;
    value = value | right_byte;
    
    if ( n < 2 )
    {
        return -1;
    } else
    {
        return value;
    }
}

int poll_right_sensor( int serial_port )
{
    unsigned char request_flag = RIGHT_SENSOR_REQUEST;
    char buffer[2] = "";
    int n = 0;

    unsigned short value = 0;

    unsigned char left_byte = 0;
    unsigned char right_byte = 0;

    n = write( serial_port, &request_flag, 1 );
    usleep(SENSOR_PROC_DELAY_US);
    n = read( serial_port, &buffer, sizeof(buffer) );

    left_byte = (unsigned char) buffer[0];
    right_byte = (unsigned char) buffer[1];
    value = value | left_byte;
    value = value << 8;
    value = value | right_byte;
    
    if ( n < 2 )
    {
        return -1;
    } else
    {
        return value;
    }
}

int poll_front_sensor( int serial_port )
{
    unsigned char request_flag = FRONT_SENSOR_REQUEST;
    char buffer[2] = "";
    int n = 0;

    unsigned short value = 0;

    unsigned char left_byte = 0;
    unsigned char right_byte = 0;

    n = write( serial_port, &request_flag, 1 );
    usleep(SENSOR_PROC_DELAY_US);
    n = read( serial_port, &buffer, sizeof(buffer) );

    left_byte = (unsigned char) buffer[0];
    right_byte = (unsigned char) buffer[1];
    value = value | left_byte;
    value = value << 8;
    value = value | right_byte;
    
    if ( n < 2 )
    {
        return -1;
    } else
    {
        return value;
    }
}

int poll_back_sensor( int serial_port )
{
    unsigned char request_flag = BACK_SENSOR_REQUEST;
    char buffer[2] = "";
    int n = 0;

    unsigned short value = 0;

    unsigned char left_byte = 0;
    unsigned char right_byte = 0;

    n = write( serial_port, &request_flag, 1 );
    usleep(SENSOR_PROC_DELAY_US);
    n = read( serial_port, &buffer, sizeof(buffer) );

    left_byte = (unsigned char) buffer[0];
    right_byte = (unsigned char) buffer[1];
    value = value | left_byte;
    value = value << 8;
    value = value | right_byte;
    
    if ( n < 2 )
    {
        return -1;
    } else
    {
        return value;
    }
}
