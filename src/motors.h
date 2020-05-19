//
// Created by AbeChaudry on 4/15/20.
//

#ifndef FIRMWARE_REBELS_ROBOT_MOTORS_H
#define FIRMWARE_REBELS_ROBOT_MOTORS_H

#define Motor1Pin1		2 //13
#define Motor1Pin2		3 //15
#define Motor1Enable	0 //11

#define Motor2Pin1		4 //18
#define Motor2Pin2		5 //16
#define Motor2Enable	6 //22

#define Motor3Pin1		14  //23
#define Motor3Pin2		13 //21
#define Motor3Enable	12 //19

#define Motor4Pin1		10 //26
#define Motor4Pin2		11 //24
#define Motor4Enable	26 //32

#define TopSpeed        50

#define MaxSpeed        100
#define MinSpeed        0


//Initialize PWM settings
void * initializePWM();

//Initialize Motor Pins
void * initializeMotors();

//To reset pins on program exit
void * resetMotorPins();

//Initialize individual motors to move forward
void * initializeMotor1F();
void * initializeMotor2F();
void * initializeMotor3F();
void * initializeMotor4F();

//Initialize individual motors to move backward
void * initializeMotor2B();
void * initializeMotor1B();
void * initializeMotor3B();
void * initializeMotor4B();

//Initialize all motors to move forward
void * initializeMotorsF();

//Initialize all motors to move backward
void * initializeMotorsB();


void * initializeRightB();

void * initializeRightF();

void * initializeLeftB();

void * initializeLeftF();

void * accelerate(int speed1, int speed2);
void * brake(int speed1, int speed2);
void * motorsStop();
void * moveForward(int speed1, int speed2);
void * moveBackward (int speed1, int speed2);
void * turnRight();
void * turnLeft();
void * allMotorsSpeed(int speed);
void * setMotors(int rightDirection,int leftDirection,int rightFront,int rightRear,int leftRear, int leftFront);
void * leftSpeed(int rearSpeed, int frontSpeed);
void * rightSpeed(int rearSpeed, int frontSpeed);

#endif //FIRMWARE_REBELS_ROBOT_MOTORS_H
