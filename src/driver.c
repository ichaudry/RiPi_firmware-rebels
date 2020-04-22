//
// Created by AbeChaudry on 4/15/20.
//
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include "motors.h"
#include "infraredSensor1.h"
#include "infraredSensor2.h"
#include "echoSensor.h"

//interrupt handler
void interruptHandler(){
    printf("The interrupt handler was called. Its time to cleanup.\n");
    printf("Slowing down the motors...\n");
    brake(40,0);

    printf("Resetting the pins to input\n");
    resetPins();

    printf("Pins cleaned..Making a clean exit!\n");
    exit(0);
}

int main(void){
    signal(SIGINT,interruptHandler);

    //Thread to run infraredSensor that gets speed
    // pthread_t infraredSensor1TID;
    // pthread_t infraredSensor2TID;
    pthread_t echoSensorTID;

    void * obstacleDistance;

    int i;

    unsigned int carMoving=1;

    if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen
        printf("setup wiringPi failed !");
        return 1;
    }


    initializeMotors();
    // initializeIR1();
    // initializeIR2();
    initEchoSensor();

    initializePWM();


    //Go forward
    moveForward(0,25);

    while(1){
    

        printf("Starting thread \n");
     
        // pthread_create(&infraredSensor1TID,NULL, &getSpeedIR1,NULL);
        // pthread_create(&infraredSensor2TID,NULL, &getSpeedIR2,NULL);
        pthread_create(&echoSensorTID,NULL,&echoSensorData,NULL );


        printf("Waiting for the created thread to terminate\n");
        // pthread_join(infraredSensor1TID, NULL);
        // pthread_join(infraredSensor2TID, NULL);
        pthread_join(echoSensorTID,&obstacleDistance);

        
        
        if(obstacleDistance){
        if(*(double *)obstacleDistance <70 && carMoving==1){
            printf("Car is braking because obstacle detected\n");
            brake(25,0);
            carMoving=0;
            free(obstacleDistance);
        }
        else{
            free(obstacleDistance);
        }
        }

    
        // printf("Sleeping for 3 second\n");
        // delay(3000);

    }

    return 0;
}