//
// Created by AbeChaudry on 4/15/20.
//

#ifndef FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR_H
#define FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR_H


#define IR_SENSOR	15
// #define PI 3.1415926535

/**
 * Struct for passing in arguments to threads
 */
typedef struct {
    //Start point of file chunk to read
    double N;

    //End point of file chunk to read
    //double n;
} threadArgs;



void initializeIR();
void * getSpeed(void * arguments);

#endif //FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR_H
