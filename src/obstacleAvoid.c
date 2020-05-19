#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"

void * obstacleAvoidance(){
    //obstacle front stop   
            
        printf("Entered the %s function\n",__FUNCTION__);

        //Stop car
        motorsStop();

        delay(3000);

        printf("Making right turn\n");
        // Turn right until left obstacle true

        initializeRightB();
        initializeLeftF();
        rightSpeed(TURNINGSPEED+REARDELTA,TURNINGSPEED);
        leftSpeed(TURNINGSPEED+REARDELTA,TURNINGSPEED);

        // delay(1000);

        while(!sData->obstacleLeftF){
            
        }
            
        motorsStop();

        delay(3000);

        printf("Go to next step\n");
        printf("Left Obstacle=%d\n",sData->obstacleLeftF);

        delay(3000);

        initializeRightF();
        rightSpeed(CREEPSPEED+REARDELTA,CREEPSPEED);
        leftSpeed(CREEPSPEED+REARDELTA,CREEPSPEED);
        
        while(sData->obstacleLeftF){
            
        }
        printf("Time to turn left\n");

        //Stop after no obstacle on the left
        motorsStop();

        delay(3000);

        printf("Make a left until obstacle detected on the left\n");

        initializeRightF();
        initializeLeftB();
        rightSpeed(TURNINGSPEED+REARDELTA,TURNINGSPEED);
        leftSpeed(TURNINGSPEED+REARDELTA-5,TURNINGSPEED-5);


        while (!sData->obstacleLeftM)
        {
            
        }

        // delay(500);

        motorsStop();

        printf("Time to go forward alongside the object\n");

        while(1){
            printf("Left Obstacle=%d\n",sData->obstacleLeftM);
            delay(3000);
        }
}
