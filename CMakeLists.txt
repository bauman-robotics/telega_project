cmake_minimum_required(VERSION 3.17)
project(joystick)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(joystick
        360_controller_map.h
        cobs.c
        cobs.h
        easy_serial.h
        joystick.h
        odroid_test_analog.c
        robot_defines.h
        sensors.h)
