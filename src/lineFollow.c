#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"

void * rightCorrectiveMechanism(){
    printf("Entered %s function\n",__FUNCTION__);

    delay(100);

    //Init motors for right turn
    initializeRightB();
    initializeLeftF();

    //Loop until whiteLineRight
    while(!sData->whiteLineRight && !haltLineDetection){
        //Turn with slight delays
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();

        //This catches sharp right turns
        if(!sData->whiteLineFarRight){
            printf("Make 90 degree right turn\n");
            initializeRightF();

            //Go forward until all sensor off the black line
            while(!sData->whiteLineFarLeft || !sData->whiteLineFarRight || !sData->whiteLineMiddle || !sData->whiteLineRight || !sData->whiteLineMiddle){
                //creep forward until above becomes false
                allMotorsSpeed(CREEPSPEED);
                delay(CREEPDELAY);
                motorsStop();
                delay(PULSEDELAY);
                
            }
            //Call sharp turn function
            rightSharpTurn();
            break;
        }

        delay(200);
    }
  
    delay(50);

    if(!haltLineDetection){
        initializeRightF();
        delay(50);
    }
    else{
        motorsStop();
    }
}


void * leftCorrectiveMechanism(){
    printf("Entered %s function\n",__FUNCTION__);
    delay(100);

    //Init motors for left turn
    initializeRightF();
    initializeLeftB();

    //Loop until whiteLineLeft
    while(!sData->whiteLineLeft && !haltLineDetection){
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();

        //This means left 90 degree turn
        if(!sData->whiteLineFarLeft){
            printf("Make right degree left turn\n");
            initializeLeftF();
            while(!sData->whiteLineFarLeft || !sData->whiteLineFarRight || !sData->whiteLineMiddle || !sData->whiteLineRight || !sData->whiteLineMiddle){
                //creep forward until above becomes false
                allMotorsSpeed(CREEPSPEED);
                delay(CREEPDELAY);
                motorsStop();
                delay(PULSEDELAY);
            }
            leftSharpTurn();
            break;
        }
        delay(200);
    }
    
    if(!haltLineDetection){
        initializeLeftF();
        delay(50);
    }
    else{
        motorsStop();
    }
}

void * rightSharpTurn(){
    printf("Entered %s function\n",__FUNCTION__);
    motorsStop();

    delay(ONESEC);

    //Init motors for right turn
    initializeRightB();
    initializeLeftF();

    //Turn right until !whiteLineRight 
    while(sData->whiteLineRight){
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(CREEPDELAY);
    }

    delay(PULSEDELAY);

    printf("Right sensor on Black tape\n");

    //Turn right until whiteLineRight
    while(!sData->whiteLineRight){
        //Init motors for right turn
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(CREEPDELAY);
    }

    printf("Right sensor on white tape\n");

    //At this point the car is centered itself on the black tape

    delay(PULSEDELAY);    
}


void * leftSharpTurn(){
    printf("Entered %s function\n",__FUNCTION__);
    motorsStop();

    delay(ONESEC);

    //Init motors for left turn
    initializeRightF();
    initializeLeftB();

    //Turn left until !whiteLineLeft
    while(sData->whiteLineLeft){
        //Init motors for right turn
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(CREEPDELAY);
    }

    delay(PULSEDELAY);

    printf("Left sensor on black tape\n");

    //Turn left until whiteLineLeft
    while(!sData->whiteLineLeft){
        //Init motors for right turn
        allMotorsSpeed(TURNINGCURVESPEED);
        delay(CREEPTURNDELAY);
        motorsStop();
        delay(CREEPDELAY);
    }

    printf("Right sensor on white tape\n");

    //At this point the car is centered itself on the black tape

    delay(PULSEDELAY);

}