//
// Created by ibraheem on 5/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "sensors.h"
#include <ctype.h>



void * lineSensor1Data(void * argument)
    {
        printf("Entered the %s function\n",__FUNCTION__);
        
        pinMode(TRACKSENSOR1,INPUT);

        unsigned int * lineDetect;
        lineDetect= (unsigned int *) argument;

        while(1){
        if(digitalRead(TRACKSENSOR1) == LOW){  
                *lineDetect=1;
            }	
            else{
                delay(100);
                *lineDetect= 0;
        }
    }
}


void * lineSensor2Data(void * argument)
    {
    printf("Entered the %s function\n",__FUNCTION__);
    
    pinMode(TRACKSENSOR2,INPUT);

    unsigned int * lineDetect;
    lineDetect= (unsigned int *) argument;

    while(1)
    {
        if(digitalRead(TRACKSENSOR2) == LOW){ 
            *lineDetect=1;
        }	
        else{
            delay(100);
            *lineDetect= 0;
        }
    }
}


void * lineSensor3Data(void * argument)
    {   
    printf("Entered the %s function\n",__FUNCTION__);

    pinMode(TRACKSENSOR3,INPUT);

    unsigned int * lineDetect;
    lineDetect= (unsigned int *) argument;

    while(1){
    if(digitalRead(TRACKSENSOR3) == LOW){
            *lineDetect=1;
        }	
        else{
            delay(100);
            *lineDetect= 0;
        }
    }
}


void * lineSensor4Data(void * argument)
    {   
    printf("Entered the %s function\n",__FUNCTION__);

    pinMode(TRACKSENSOR4,INPUT);

    unsigned int * lineDetect;
    lineDetect= (unsigned int *) argument;

    while(1){
    if(digitalRead(TRACKSENSOR4) == LOW){
            delay(100);
            *lineDetect=1;
        }	
        else{
            delay(100);
            *lineDetect= 0;
        }
    }
}


void * lineSensor5Data(void * argument)
    {   
    printf("Entered the %s function\n",__FUNCTION__);

    pinMode(TRACKSENSOR5,INPUT);

    unsigned int * lineDetect;
    lineDetect= (unsigned int *) argument;

    while(1){
    if(digitalRead(TRACKSENSOR5) == LOW){
            delay(100);
            *lineDetect=1;
        }	
        else{
            delay(100);
            *lineDetect= 0;
        }
    }
}
