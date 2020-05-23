//
// Created by AbeChaudry on 5/18/20.
//

#ifndef DUMMY_FOR_PI_DRIVER_H
#define DUMMY_FOR_PI_DRIVER_H

#define NORMALSPEED                         20
#define TURNINGDELTASPEED                   28
#define TURNINGSPEED                        30
#define OBSTACLESTOPPINGDISTANCE            30
#define OBSTACLECREEPINGDISTANCE            4
#define CREEPSPEED                          25
#define TURNINGCREEPSPEED                   70
#define TURNINGCURVESPEED                   60
#define ZERO                                0
#define CREEPTURNDELAY                      70
#define CREEPDELAY                          100
#define PULSEDELAY                          500
#define ONESEC                              1000

/*
*Structure to store data from sensors
*/
typedef struct{
    double distance;
    unsigned int whiteLineFarRight;
    unsigned int whiteLineRight;
    unsigned int whiteLineMiddle; 
    unsigned int whiteLineLeft;
    unsigned int whiteLineFarLeft;
    unsigned int obstacleLeftF;
    unsigned int obstacleLeftM;
    unsigned int obstacleLeftB;
}sensorData;

sensorData * sData;
unsigned int haltLineDetection;

void * rightCorrectiveMechanism();
void * leftCorrectiveMechanism();
void * rightSharpTurn();
void * leftSharpTurn();

//Function to check sensors and motor
void * sensorDataCheck();
void * motorCheck();

//Obstacle avoidance function
void * obstacleDetector();
void * obstacleAvoidance();

//interrupt handler
void  interruptHandler();



#endif //DUMMY_FOR_PI_DRIVER_H
