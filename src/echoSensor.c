#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "echoSensor.h"
#include <time.h>





	void * initEchoSensor(){
	//Set pin mode
	pinMode(TRIGGER,OUTPUT);
	pinMode(ECHO,INPUT);
    }
	

    void * echoSensorData(){
		double startTime=0;
		double endTime=0;
		double pulseDuration=0;
		double * distance= malloc(sizeof(double));
		
		
		
		//Set trigger to low initially
		digitalWrite(TRIGGER,LOW);
		printf("Waiting for the sensor to settle\n");
		delay(500);
		
		
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
		
		*distance= pulseDuration*17000;
		
        
        //Discard out of range values
		if(*distance > 2 && *distance < 350){
			printf("The distance is: %f\n",*distance);
            return (void *) distance;
        }
        else{
            free(distance);
            return NULL;
        }
	}
	