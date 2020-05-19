#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "motors.h"

/**
 * Setting the range for PWM to control and set car speed
 */
void * initializePWM() {
    softPwmCreate(Motor1Enable, MinSpeed, MaxSpeed);
    softPwmCreate(Motor2Enable, MinSpeed, MaxSpeed);
    softPwmCreate(Motor3Enable, MinSpeed, MaxSpeed);
    softPwmCreate(Motor4Enable, MinSpeed, MaxSpeed);
}

/**
 *Initialize all motor pins to output
 */
void * initializeMotors(){
    //Initializing all motor to output  
	pinMode(Motor1Pin1, OUTPUT);
	pinMode(Motor1Pin2, OUTPUT);
	pinMode(Motor1Enable, OUTPUT);

	pinMode(Motor2Pin1, OUTPUT);
	pinMode(Motor2Pin2, OUTPUT);
	pinMode(Motor2Enable, OUTPUT);
	
	pinMode(Motor3Pin1, OUTPUT);
	pinMode(Motor3Pin2, OUTPUT);
	pinMode(Motor3Enable, OUTPUT);
	
	pinMode(Motor4Pin1, OUTPUT);
	pinMode(Motor4Pin2, OUTPUT);
	pinMode(Motor4Enable, OUTPUT);
}


/**
 *Reset all motor pins to input
 */
void * resetMotorPins(){
    //Reset pins to input 
	pinMode(Motor1Pin1, INPUT);
	pinMode(Motor1Pin2, INPUT);
	pinMode(Motor1Enable, INPUT);

	pinMode(Motor2Pin1, INPUT);
	pinMode(Motor2Pin2, INPUT);
	pinMode(Motor2Enable, INPUT);
	
	pinMode(Motor3Pin1, INPUT);
	pinMode(Motor3Pin2, INPUT);
	pinMode(Motor3Enable, INPUT);
	
	pinMode(Motor4Pin1, INPUT);
	pinMode(Motor4Pin2, INPUT);
	pinMode(Motor4Enable, INPUT);
}

/**
 *Initialize motor pins to set DC motors to move car forwards 
 */
void * initializeMotorsB(){
   initializeMotor1B();
   initializeMotor2B();
   initializeMotor3B();
   initializeMotor4B();
}

/**
 *Initialize motor pins to set DC motors to move car backwards 
 */
void * initializeMotorsF(){
    initializeMotor1F();
    initializeMotor2F();
    initializeMotor3F();
    initializeMotor4F();
}

/**
 * Accelerate gradually to maximum speed
 */
void * accelerate(int speed1, int speed2){
    //Intensity of motors for accelerating 
    //This is done using pulse width modulation 
	int i;

    //Slowly accelerate the motors
    for (i = speed1; i < speed2; i++)
		{
		  softPwmWrite (Motor1Enable, i);
		  softPwmWrite (Motor2Enable, i);
		  softPwmWrite (Motor3Enable, i);
		  softPwmWrite (Motor4Enable, i);
		  delay (200) ;
		}
}

/**
 * Deccelerate gradually to minimum speed
 */
void * brake(int speed1, int speed2){
    //Intensity of motors from which to start braking from
    //This is done using pulse width modulation
    int i;

    //Slow the motors down to a stop
    for (i = speed1; i >= speed2; i--)
		{
		  softPwmWrite (Motor1Enable, i);
		  softPwmWrite (Motor2Enable, i);
		  softPwmWrite (Motor3Enable, i);
		  softPwmWrite (Motor4Enable, i);
		  delay (50) ;
		}

    }


void * motorsStop(){
    softPwmWrite (Motor1Enable, 0);
    softPwmWrite (Motor2Enable, 0);
    softPwmWrite (Motor3Enable, 0);
    softPwmWrite (Motor4Enable, 0);
}

void * moveBackward(int speed1, int speed2){
    printf("Anti- Clockwise\n");
   
    //Initiliaze motors to move forwards
    initializeMotorsB();

    //Accelerate
    accelerate(speed1,speed2);
}

void * moveForward(int speed1, int speed2){
    printf("Clockwise\n");

    //Initiliaze motors to move backwards
    initializeMotorsF();

    //Accelerate
    accelerate(speed1, speed2);
}

void * allMotorsSpeed(int speed){
    softPwmWrite (Motor1Enable, speed);
    softPwmWrite (Motor2Enable, speed);
    softPwmWrite (Motor3Enable, speed);
    softPwmWrite (Motor4Enable, speed);
}

void * setMotors(int rightDirection,int leftDirection,int rightFront,int rightRear,int leftRear, int leftFront){
    if(rightDirection){
        initializeRightF();
    }
    else{
        initializeRightB();
    }

    if(leftDirection){
        initializeLeftF();
    }
    else{
        initializeLeftB();
    }
   
    softPwmWrite (Motor3Enable, rightFront);
    softPwmWrite (Motor2Enable, rightRear);
    softPwmWrite (Motor1Enable, leftRear);
    softPwmWrite (Motor4Enable, leftFront);
}



void * leftSpeed(int rearSpeed, int frontSpeed){
    //Rear Speed
    softPwmWrite (Motor1Enable, rearSpeed);

    //Front Speed
    softPwmWrite (Motor4Enable, frontSpeed);
}

void * rightSpeed(int rearSpeed, int frontSpeed){
    //Rear Speed
    softPwmWrite (Motor2Enable, rearSpeed);

    //Front Speed
    softPwmWrite (Motor3Enable, frontSpeed);
}


/**
 *
 */
void * turnRight(){
    int intensity;

    initializeMotor1F();
    initializeMotor4F();
     for (intensity = MinSpeed; intensity < TopSpeed; intensity++)
		{
		  softPwmWrite (Motor1Enable, intensity);
		  softPwmWrite (Motor4Enable, intensity);
		  delay (50) ;
		}
}


/**
 *
 */
void * turnLeft(){
    int intensity;
    initializeMotor2F();
    initializeMotor3F();
    for (intensity = MinSpeed; intensity < TopSpeed; intensity++)
		{
		  softPwmWrite (Motor2Enable, intensity);
		  softPwmWrite (Motor3Enable, intensity);
		  delay (50) ;
		}
    }   


void * initializeRightB(){
    initializeMotor2B();
    initializeMotor3B();
}

void * initializeRightF(){
    initializeMotor2F();
    initializeMotor3F();
}

void * initializeLeftB(){
    initializeMotor1B();
    initializeMotor4B();
}

void * initializeLeftF(){
    initializeMotor1F();
    initializeMotor4F();
}


/**
 * Functions to initialize each separate motor to run in the forward direction
 */
void * initializeMotor1B(){
    digitalWrite(Motor1Pin1, HIGH);
    digitalWrite(Motor1Pin2, LOW);  
}


void * initializeMotor2B(){
    digitalWrite(Motor2Pin1, HIGH);
    digitalWrite(Motor2Pin2, LOW);
}
void * initializeMotor3B(){
    digitalWrite(Motor3Pin1, HIGH);
    digitalWrite(Motor3Pin2, LOW);
}

void * initializeMotor4B(){
    digitalWrite(Motor4Pin1, HIGH);
    digitalWrite(Motor4Pin2, LOW);
}


/**
 * Functions to initialize each separate motor to run in the backwards direction
 */
void * initializeMotor1F(){
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, HIGH);    
}

void * initializeMotor2F(){
    digitalWrite(Motor2Pin1, LOW);
    digitalWrite(Motor2Pin2, HIGH);
}

void * initializeMotor3F(){
    digitalWrite(Motor3Pin1, LOW);
    digitalWrite(Motor3Pin2, HIGH);
}

void * initializeMotor4F(){
    digitalWrite(Motor4Pin1, LOW);
    digitalWrite(Motor4Pin2, HIGH);
}

