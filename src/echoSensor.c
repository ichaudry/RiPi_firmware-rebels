//
// Created by ibraheem on 5/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "sensors.h"
#include <ctype.h>
#include <time.h>


void * echoSensorData(void * argument)
    {
        printf("Entered the %s function\n",__FUNCTION__);
        
        //Set pin mode
        pinMode(TRIGGER,OUTPUT);
        pinMode(ECHO,INPUT);

        double * distance= (double *) argument;

        while(1)
        {
		double startTime=0;
		double endTime=0;
		double pulseDuration=0;
		double tempDistance;
		
		//Set trigger to low initially
		digitalWrite(TRIGGER,LOW);
		// printf("Waiting for the sensor to settle\n");
		delay(300);
		
		//Set trigger to high and then low to send signal 
		digitalWrite(TRIGGER,HIGH);
		delay(0.05);
		digitalWrite(TRIGGER,LOW);
		
        while(digitalRead(ECHO)==LOW){
			startTime=clock();
		}
		
		while(digitalRead(ECHO)==HIGH){
			endTime=clock();
		}
		
		pulseDuration=((double)(endTime-startTime))/CLOCKS_PER_SEC;
		
		tempDistance= pulseDuration*17000;
		
        //Discard out of range values
		if(tempDistance > 2 && tempDistance < 350){
			//printf("The distance is: %f\n",tempDistance);
            *distance=tempDistance;
        }
    }
}

