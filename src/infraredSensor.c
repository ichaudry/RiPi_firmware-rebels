#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "infraredSensor.h"


   void initializeIR() {
       pinMode(IR_SENSOR,INPUT);
   }

   void * getSpeed() {
       //Number of pulses
       double n=0;

       //The number of pulses in one revolution
       double N=20;

       int count=0;

       clock_t t;
       t = clock();

       while(count<5000){
           // printf("This is the input from the IR Sensor %d\n",digitalRead(IR_SENSOR));
           if(digitalRead(IR_SENSOR)==1){
               n++;
           }
           count++;
       }

       printf("This is the time before subtraction %f\n",(double) t);

       t = clock() - t;


       printf("This is the time after subtraction %f\n",(double) t);

       double time_taken = ((double)t)/((double)CLOCKS_PER_SEC); // in seconds

       printf("The time taken for the function is %f\nThe PI value is %f\nThe value of n is %lu\nThe value of N is %d\n",time_taken,PI,n,N);

       double angularSpeed= (2* PI * n )/(N * time_taken);

       printf("The angular speed is %lu\n",angularSpeed);

   }

