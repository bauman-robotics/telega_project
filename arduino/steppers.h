#ifndef __STEPPERS_H
#define __STEPPERS_H

#include <TimerOne.h>
#include <TimerThree.h>

#define STEPPING 4
#define STEPS_REV 200*STEPPING
#define MAX_SPEED 25 //rpms  
#define UPDATE_TIME 5000  //micros
#define DUTY_CYCLE 512 //out of 1024

//    Stepper Motor Pins
//    Remember to tie SLEEP to 5v

#define STEPPER_LEFT_DIR    23
#define STEPPER_LEFT_MS1    25
#define STEPPER_LEFT_MS2    27
#define STEPPER_LEFT_ENABLE 29

 
#define STEPPER_RIGHT_DIR    47
#define STEPPER_RIGHT_MS1    49
#define STEPPER_RIGHT_MS2    51
#define STEPPER_RIGHT_ENABLE 53

#define STEPPER_LEFT_STEP   13
#define STEPPER_RIGHT_STEP   2 

volatile unsigned long leftSpeed = 0; //global vars for speed control, checked by the interrupt every 1 mS. in uS/step
volatile unsigned long rightSpeed = 0;
volatile char rightDir = 0; // 1 = forward
volatile char leftDir = 0;

volatile unsigned int stepDelay = 0;

void updateLeftMotor()
{
  if(leftSpeed == 0)
    Timer1.pwm(STEPPER_LEFT_STEP, 0, leftSpeed);
    //Timer1.disablePwm(STEPPER_LEFT_STEP);
  else
    Timer1.pwm(STEPPER_LEFT_STEP, DUTY_CYCLE, leftSpeed);
}

void updateRightMotor()
{
  if(rightSpeed == 0)
    Timer3.pwm(STEPPER_RIGHT_STEP, 0, rightSpeed);
    //Timer3.disablePwm(STEPPER_RIGHT_STEP);
  else
    Timer3.pwm(STEPPER_RIGHT_STEP, DUTY_CYCLE, rightSpeed);
}

void initializeSteppers()
{
  Timer1.initialize(UPDATE_TIME); //set it up!
  Timer3.initialize(UPDATE_TIME); //set it up!
  Timer1.attachInterrupt(updateLeftMotor); //attach the update function
  Timer3.attachInterrupt(updateRightMotor); //attach the update function
  Timer1.pwm(STEPPER_LEFT_STEP, 0, 1000000); //set up pwm on 9 and 10
  Timer3.pwm(STEPPER_RIGHT_STEP, 0, 1000000);

  // Left Stepper Pins
  pinMode(STEPPER_LEFT_DIR, OUTPUT);
  pinMode(STEPPER_LEFT_STEP, OUTPUT);
  pinMode(STEPPER_LEFT_MS1, OUTPUT);
  pinMode(STEPPER_LEFT_MS2, OUTPUT);
  pinMode(STEPPER_LEFT_ENABLE, OUTPUT); //should be hardwired to ground
  
  digitalWrite(STEPPER_LEFT_MS1, LOW); //enable 1/4 microstepping
  digitalWrite(STEPPER_LEFT_MS2, HIGH);
  digitalWrite(STEPPER_LEFT_ENABLE, LOW); //should be unnecessary

  // Right Stepper Pins
  pinMode(STEPPER_RIGHT_DIR, OUTPUT);
  pinMode(STEPPER_RIGHT_STEP, OUTPUT);
  pinMode(STEPPER_RIGHT_MS1, OUTPUT);
  pinMode(STEPPER_RIGHT_MS2, OUTPUT);
  pinMode(STEPPER_RIGHT_ENABLE, OUTPUT); //should be hardwired to ground

  digitalWrite(STEPPER_RIGHT_MS1, LOW); //enable 1/4 microstepping
  digitalWrite(STEPPER_RIGHT_MS2, HIGH);
  digitalWrite(STEPPER_RIGHT_ENABLE, LOW); //should be unnecessary
  
}

void setLeftStepperRPM(int rpm)
{
  Serial.print("rpm in = ");
  Serial.println(rpm);
   if(rpm > 0)
    digitalWrite(STEPPER_LEFT_DIR, LOW);
  else if(rpm < 0)
    digitalWrite(STEPPER_LEFT_DIR, HIGH);
  else
  {
    noInterrupts();
    leftSpeed = 0;
    interrupts();
    return;
  }
    
  unsigned long stepsSec = (abs(rpm) * STEPS_REV) / 60;
  Serial.print("stepsSec = ");
  Serial.println(stepsSec);

  noInterrupts();
  leftSpeed = 1000000 / stepsSec;
  interrupts();
  
  Serial.print("leftSpeed = ");
  Serial.println(leftSpeed);
}

void setRightStepperRPM(int rpm)
{
  Serial.print("rpm in = ");
  Serial.println(rpm);
  if(rpm > 0)
    digitalWrite(STEPPER_RIGHT_DIR, HIGH);
  else if(rpm < 0)
    digitalWrite(STEPPER_RIGHT_DIR, LOW);
  else
  {
    noInterrupts();
    rightSpeed = 0;
    interrupts();
    return;
  }

  unsigned long stepsSec = (abs(rpm) * STEPS_REV) / 60;
  Serial.print("stepsSec = ");
  Serial.println(stepsSec);
  
  noInterrupts();
  rightSpeed = 1000000 / stepsSec;
  interrupts();
  
  Serial.print("rightSpeed = ");
  Serial.println(rightSpeed);
}

#endif
