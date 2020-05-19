//
// Created by ibraheem on 5/12/20.
//

#ifndef DUMMY_FOR_PI_SENSORS_H
#define DUMMY_FOR_PI_SENSORS_H

#define TRIGGER             21       
#define ECHO                22       
#define TRACKSENSOR1        27  //Extreme Right 
#define TRACKSENSOR2        29  //Right
#define TRACKSENSOR3        23  //Middle
#define TRACKSENSOR4	    24  //Left     
#define TRACKSENSOR5        28  //Extreme Left 
#define PIR1                7       
#define PIR2                1       
#define PIR3                25      


void * echoSensorData(void * argument);
void * lineSensor1Data(void * argument);
void * lineSensor2Data(void * argument);
void * lineSensor3Data(void * argument);
void * lineSensor4Data(void * argument);
void * lineSensor5Data(void * argument);
void * getSideSensor1Data(void * argument);
void * getSideSensor2Data(void * argument);
void * getSideSensor3Data(void * argument);

#endif //DUMMY_FOR_PI_SENSORS_H
