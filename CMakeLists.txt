cmake_minimum_required(VERSION 3.10)
project(full_featured_RC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(full_featured_RC
        360_controller_map.h
        cobs.c
        cobs.h
        easy_serial.h
        joystick.h
        odroid_test_analog.c
        robot_defines.h
        sensors.h)
