//
// Created by AbeChaudry on 4/15/20.
//
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "motors.h"



//interrupt handler
void interruptHandler(){
    printf("The interrupt handler was called. Its time to cleanup.\n");
    printf("Slowing down the motors...\n");
    brake();

    printf("Resetting the pins to input\n");
    resetPins();

    printf("Pins cleaned..Making a clean exit!\n");
    exit(0);
}



int main(void){
    signal(SIGINT,interruptHandler);

    int i;
    if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
        printf("setup wiringPi failed !");
        return 1;
    }

    initializeMotors();

    initializePWM();
    
    //Go forward
    initializeMotorsF();

    accelerate();

    delay(5000);

    brake();

    delay(3000);

    //Go backward
    initializeMotorsB();

    accelerate();

    delay(5000);

    brake();


    return 0;
}