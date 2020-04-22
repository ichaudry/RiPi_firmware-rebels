#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "infraredSensor1.h"

    //The number of pulses in one revolution
    //double N=20.0;

    void initializeIR1() {
       pinMode(IR_SENSOR,INPUT);
    }

    void * getSpeedIR1() {
        //Number of pulses
        double n=0;
        double PI=3.14159265;

        //Number of pulses per revolution
        double N= 20;

        int count=0;

        clock_t t;
        t = clock();

        while(count<50000000){
            // printf("This is the input from the IR Sensor %d\n",digitalRead(IR_SENSOR));
            if(digitalRead(IR_SENSOR)==1){
                n++;

                while(digitalRead(IR_SENSOR)==1){
                    //Wait for it to transition beofre get the next count
                }
            }
            
            count++;
        }

        printf("This is the time before subtraction %f\n",(double) t);

        t = clock() - t;


        printf("This is the time after subtraction %f\n",(double) t);

        double time_taken = ((double)t)/((double)CLOCKS_PER_SEC); // in seconds

        printf("The time taken for the function is %f\nThe PI value is %f\nThe value of n is %f\nThe value of N is %f\n",time_taken,PI,n,N);

        double angularSpeed= (2* PI * n )/(N * time_taken);

        printf("The angular speed of motor 1 is %f\n",angularSpeed);

    }

