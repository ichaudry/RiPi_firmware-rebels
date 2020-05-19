//
// Created by AbeChaudry on 5/18/20.
//

#ifndef DUMMY_FOR_PI_DRIVER_H
#define DUMMY_FOR_PI_DRIVER_H

#define STARTINGSPEED               20
#define NORMALSPEED                 20
#define TURNINGDELTASPEED           30
#define ZERO                        0
#define JERKSPEED                   15
#define OBSTACLEDISTANCE            40
#define CREEPSPEED                  25
#define REARDELTA                   10

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

void * rightCorrectiveMechanism();
void * leftCorrectiveMechanism();
void * rightSharpTurn();

void * sensorDataCheck();
void * motorCheck();

//Obstacle avoidance function
void * obstacleAvoidance();

//interrupt handler
void  interruptHandler();



#endif //DUMMY_FOR_PI_DRIVER_H
