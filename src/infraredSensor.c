#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>

#define IR_SENSOR	15
#define PI 3.1415926535

int main(int argc, char const *argv[])
{   
    if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}


   

    //Number of pulses
    long n=0;

    //pulses per revolution
    int N=20;



    pinMode(IR_SENSOR,INPUT);
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

    
    
    t = clock() - t; 
    double time_taken = ((double)t)/((double)CLOCKS_PER_SEC); // in seconds 

    printf("The time taken for the function is %f\nThe PI value is %f\nThe value of n is %lu\nThe value of N is %d\n",time_taken,PI,n,N);

    


    double angularSpeed= (2* PI * n )/(N * time_taken);


    printf("The angular speed is %lu\n",angularSpeed);


    return 0;
}
