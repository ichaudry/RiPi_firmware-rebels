//
// Created by AbeChaudry on 4/15/20.
//
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include "driver.h"
#include "motors.h"
#include "sensors.h"

int main(void){
    signal(SIGINT,interruptHandler);

    //Thread ids for all sensors
    pthread_t echoSensorTID;
    pthread_t lineSensor1TID;
    pthread_t lineSensor2TID;
    pthread_t lineSensor3TID;
    pthread_t lineSensor4TID;
    pthread_t lineSensor5TID;
    pthread_t sideSensor1TID;
    pthread_t sideSensor2TID;
    pthread_t sideSensor3TID;

    //Initialize wiringPi
    if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen
        printf("setup wiringPi failed !");
        return 1;
    }

    //Allocate structure to store sensor data
    sData= malloc(sizeof(sensorData));

    printf("Starting threads \n");
     
    pthread_create(&echoSensorTID,NULL,&echoSensorData,(void *)&sData->distance);
    pthread_create(&lineSensor1TID,NULL,&lineSensor1Data,(void *)&sData->whiteLineFarRight);
    pthread_create(&lineSensor2TID,NULL,&lineSensor2Data,(void *)&sData->whiteLineRight);
    pthread_create(&lineSensor3TID,NULL,&lineSensor3Data,(void *)&sData->whiteLineMiddle);
    pthread_create(&lineSensor4TID,NULL,&lineSensor4Data,(void *)&sData->whiteLineLeft);
    pthread_create(&lineSensor5TID,NULL,&lineSensor5Data,(void *)&sData->whiteLineFarLeft);
    pthread_create(&sideSensor1TID,NULL,&getSideSensor1Data,(void *)&sData->obstacleLeftF);
    pthread_create(&sideSensor2TID,NULL,&getSideSensor2Data,(void *)&sData->obstacleLeftM);
    pthread_create(&sideSensor3TID,NULL,&getSideSensor3Data,(void *)&sData->obstacleLeftB);

    printf("Threads started\n");

    //Ensure all threads start before loop is entered
    delay(2000);

    //Initialize Motors and pulse width modulation
    initializeMotors();
    initializePWM();

    //Set motors to run in forward direction with NORMALSPEED
    setMotors(1,1,NORMALSPEED,NORMALSPEED,NORMALSPEED,NORMALSPEED);

    while(1){

        //Drifting left off the line
        if(sData->whiteLineRight){
            rightCorrectiveMechanism();
            printf("***Exited right mechanism.\n");
            continue;
        }

        //drifting right off the line
        if(sData->whiteLineLeft){
            leftCorrectiveMechanism();
            printf("***Exited left mechanism.\n");
            continue;
        }

        //Sensor on far right activated i.e. on black line
        //Sharp right/90 degree turn
        if(!sData->whiteLineFarRight ){
            rightSharpTurn();
            printf("***Exited sharp right mechanism.\n");
            continue;
        }

    }
    
    printf("Waiting for the created thread to terminate\n");
    pthread_join(echoSensorTID,NULL);
    pthread_join(lineSensor1TID,NULL);
    pthread_join(lineSensor2TID,NULL);
    pthread_join(lineSensor3TID,NULL);
    pthread_join(lineSensor4TID,NULL);
    pthread_join(lineSensor5TID,NULL);
    pthread_join(sideSensor1TID,NULL);
    pthread_join(sideSensor2TID,NULL);
    pthread_join(sideSensor3TID,NULL);

    free(sData);

    return 0;
}


//interrupt handler
void  interruptHandler(){
    printf("The interrupt handler was called. Its time to cleanup.\n");
    printf("Slowing down the motors...\n");
    motorsStop();
    

    printf("Resetting the pins to input\n");
    resetMotorPins();

    printf("Pins cleaned..Making a clean exit!\n");
    exit(0);
}
