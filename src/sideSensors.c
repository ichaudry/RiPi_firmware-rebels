//
// Created by ibraheem on 5/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "sensors.h"
#include <ctype.h>


//Right Side Sensor
void * getSideSensor1Data(void * argument){

    printf("Entered the %s function\n",__FUNCTION__);
    
    unsigned int * obstacle;
    obstacle= (unsigned int *) argument;

    //Initialize Pins
    pinMode(PIR1,INPUT);

    while (1)
    {
        if(!(digitalRead(PIR1))){
            *obstacle= 1;
        }
        else{
            *obstacle= 0;
        }
    }

}


//Left Side Sensor
void * getSideSensor2Data(void * argument){

    printf("Entered the %s function\n",__FUNCTION__);

    unsigned int * obstacle;
    obstacle= (unsigned int *) argument;

    //Initialize Pins
    pinMode(PIR2,INPUT);

    while (1)
    {
        if(!(digitalRead(PIR2))){
            *obstacle=1;
        }
        else{
            *obstacle=0;
        }
    }

}


//Left Side Sensor
void * getSideSensor3Data(void * argument){

    printf("Entered the %s function\n",__FUNCTION__);

    unsigned int * obstacle;
    obstacle= (unsigned int *) argument;

    //Initialize Pins
    pinMode(PIR3,INPUT);

    while (1)
    {
        if(!(digitalRead(PIR3))){
            *obstacle=1;
        }
        else{
            *obstacle=0;
        }
    }

}
