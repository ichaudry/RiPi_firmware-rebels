#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"

void * motorCheck(){
    printf("Checking all motors.\n");
    //Motor Check code  
    setMotors(1,1,NORMALSPEED,0,0,0);
    delay(5000);
    setMotors(1,1,NORMALSPEED,NORMALSPEED,0,0);
    delay(5000);
    setMotors(1,1,NORMALSPEED,NORMALSPEED,NORMALSPEED,0);
    delay(5000);
    setMotors(1,1,NORMALSPEED,NORMALSPEED,NORMALSPEED,NORMALSPEED);
    delay(5000);
    printf("Motor Check complete\n");
    motorsStop();
}

void * sensorDataCheck(){
    printf("Entered %s function\n",__FUNCTION__);

    while(1){

        printf("The distance from obstacle is: %f\n",sData->distance);

        if(sData->whiteLineFarRight){
            printf("There is a white line on lineSensor1\n");
        }
        if(sData->whiteLineRight){
            printf("There is a white line on lineSensor2\n");
        }
        if(sData->whiteLineMiddle){
            printf("There is a white line on lineSensor3\n");
        }
        if(sData->whiteLineLeft){
            printf("There is a white line on lineSensor4\n");
        }
        if(sData->whiteLineFarLeft){
            printf("There is a white line on lineSensor5\n");
        }
                
        if(sData->obstacleLeftF){
            printf("There is an obstacle on side 1\n");
        }

        if(sData->obstacleLeftM){
            printf("There is an obstacle on side 2\n");
        }

        if(sData->obstacleLeftB){
            printf("There is an obstacle on side 3\n");
        }
        
        delay(2000);

    }
}