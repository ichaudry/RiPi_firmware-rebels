#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"


void * obstacleDetector(){
    while(1){
    
     if(sData->distance<OBSTACLESTOPPINGDISTANCE ){
            // printf("Distance after first if: %f\n",sData->distance);
            //Stop the car
            motorsStop();

            //Halt line detection 
            haltLineDetection=1;
            printf("Dramatic Pause\n");

            //Dramatic Pause
            delay(5000);
            
            //Check if obstacle has cleared
            if(sData->distance>OBSTACLESTOPPINGDISTANCE){
                allMotorsSpeed(NORMALSPEED);
                haltLineDetection=0;
                break;
            }

            //Call mechanism to go around obstacle
            obstacleAvoidance();

            //Unlock main functioning loop to stay centered on line
            haltLineDetection=0;
        }
    }
}



void * obstacleAvoidance(){       
    printf("Entered the %s function\n",__FUNCTION__);

    //Get close to the obstacle to allow side sensors to function properly
    if(sData->distance>OBSTACLECREEPINGDISTANCE)
    {
        initializeMotorsF();
        while(sData->distance>OBSTACLECREEPINGDISTANCE)
        {
            allMotorsSpeed(CREEPSPEED);
            delay(CREEPDELAY);
            motorsStop();
            delay(PULSEDELAY);
            printf("The distance now is %f\n",sData->distance);
        }
    }
    //If too close back up a little bit
    else
    {
        initializeMotorsB();
        while(sData->distance<OBSTACLECREEPINGDISTANCE)
        {
            allMotorsSpeed(CREEPSPEED);
            delay(CREEPDELAY);
            motorsStop();
            delay(PULSEDELAY);
            printf("The distance now is %f\n",sData->distance);
        }
    }
    
    //Get slightly closer to more accuracy
    initializeMotorsF();
    allMotorsSpeed(CREEPSPEED);
    delay(50);
    motorsStop();

    delay(PULSEDELAY);

    //Init motors for right turn
    initializeRightB();
    initializeLeftF();

    //Swing right until the rear left IR sensor detects obstacle
    //At that point the RiPi would be parrallel to the obstacle
    while(!sData->obstacleLeftB){
        allMotorsSpeed(TURNINGCREEPSPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    //Init motors to go forward
    initializeRightF();
    delay(PULSEDELAY);

    //Creep forward parallell to obstacle until no more obstacle is detected by the rear left IR sensor
    while (sData->obstacleLeftB){
        allMotorsSpeed(CREEPSPEED);
        delay(CREEPDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    delay(PULSEDELAY);

    //Init motors for left turn
    initializeRightF();
    initializeLeftB();

    //Turn left until front left IR sensor detects obstacle at which point the car will be parralel to the obstacle
    while(!sData->obstacleLeftF){
        rightSpeed(TURNINGCREEPSPEED,TURNINGCREEPSPEED);
        // allMotorsSpeed(TURNINGCREEPSPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    delay(PULSEDELAY);
    initializeLeftF();

    //Creep forward until the object is detected by the left rear IR sensor
    while(!sData->obstacleLeftB){
        allMotorsSpeed(CREEPSPEED);
        delay(CREEPDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    // printf("Obstacle now being sensed on the left rear. Keep going forward until clear the object from the rear.\n");
    delay(PULSEDELAY);

    //Creep forward until the left rear sensor no longer detects an obstacle meaning the bot has cleared the obstacle
    while(sData->obstacleLeftB){
        allMotorsSpeed(CREEPSPEED);
        delay(CREEPDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    // printf("Obstacle cleared. Turn left to merge back onto line\n");

    delay(PULSEDELAY);

    //Init motors for left turn
    initializeRightF();
    initializeLeftB();

    //Turn left until front left IR sensor detects obstacle at which point the car will be parralel to the obstacle
    while(!sData->obstacleLeftF){
        allMotorsSpeed(TURNINGCREEPSPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(PULSEDELAY);
    }

    // printf("Going forward until line reached\n");

    delay(PULSEDELAY);
    initializeLeftF();

    //Creep forward until all line sensors detect black line
    while(1){
        allMotorsSpeed(CREEPSPEED);
        delay(CREEPDELAY);
        motorsStop();
        delay(PULSEDELAY);
        if(!sData->whiteLineFarLeft && !sData->whiteLineLeft && !sData->whiteLineMiddle && !sData->whiteLineRight && !sData->whiteLineFarRight){
            printf("Black line reached!\n");
            break;
        }
    }

    ///Go forward until all sensor off the black line
    while(!sData->whiteLineFarLeft || !sData->whiteLineFarRight || !sData->whiteLineMiddle || !sData->whiteLineRight || !sData->whiteLineMiddle){
        //creep forward until above becomes false
        allMotorsSpeed(CREEPSPEED);
        delay(CREEPDELAY);
        motorsStop();
        delay(PULSEDELAY);
        
    }
  
    //Turn right to get entered on black line
    rightSharpTurn();
}
