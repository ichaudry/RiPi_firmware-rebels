//
// Created by AbeChaudry on 4/15/20.
//

#ifndef FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR2_H
#define FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR2_H

#define MOSI    12
#define MISO    13
#define SCLK    14
#define CE0     10

void initializeIR2();
void * getSpeedIR2();

#endif //FIRMWARE_REBELS_ROBOT_INFRAREDSENSOR2_H
