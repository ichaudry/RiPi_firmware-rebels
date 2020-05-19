#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"

void * rightCorrectiveMechanism(){
    // Veer right
    leftSpeed(NORMALSPEED+TURNINGDELTASPEED,NORMALSPEED+TURNINGDELTASPEED);
    rightSpeed(ZERO,ZERO);

    // printf("Right Speed when veering right: %f\n",sData->rightSpeed);
    printf("Left Speed increased to make a right\n");

    //Loop until whiteLineRight
    while(!sData->whiteLineRight){}
    
    //Slight jerk to the left
    rightSpeed(NORMALSPEED+JERKSPEED,NORMALSPEED+JERKSPEED);
    leftSpeed(ZERO,ZERO);

    delay(300);

    allMotorsSpeed(NORMALSPEED);
}


void * leftCorrectiveMechanism(){
    //Veer left  
    rightSpeed(NORMALSPEED+TURNINGDELTASPEED,NORMALSPEED+TURNINGDELTASPEED);
    leftSpeed(ZERO,ZERO);

    printf("Right Speed increased to make a left\n");

    //Loop until whiteLineLeft
    while(!sData->whiteLineLeft){}

    //Slight jerk to the right
    leftSpeed(NORMALSPEED+JERKSPEED,NORMALSPEED+JERKSPEED);
    rightSpeed(ZERO,ZERO);
    delay(300);

    allMotorsSpeed(NORMALSPEED);
}

void * rightSharpTurn(){
    printf("Entered %s function\n",__FUNCTION__);
    motorsStop();

    while(1){

    }
    //Sensor on extreme right activated i.e. on black line
        //Sharp right/90 degree turn
        // if(!sData->l2 ){
        //     printf("Making Hard right turn\n");
            
        //     leftSpeed(NORMALSPEED,NORMALSPEED);
        //     initializeRightB();
        //     rightSpeed(NORMALSPEED,NORMALSPEED);
            
        //     while(!sData->l2){
        //         //Waiting for sensor to get back on white line
        //     }
        //     initializeRightF();
        //     rightSpeed(NORMALSPEED+JERKSPEED,NORMALSPEED+JERKSPEED);
        //     // leftSpeed(NORMALSPEED-TURNINGSUBDELTASPEED,NORMALSPEED-TURNINGSUBDELTASPEED);
        //     leftSpeed(ZERO,ZERO);

        //     delay(300);

        //     allMotorsSpeed(NORMALSPEED);
        //     // printf("Right Speed after veering right: %f\n",sData->rightSpeed);
            
        //     printf("***Exited sharp right mechanism.\n");
        
        // }
}