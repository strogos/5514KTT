/*
 * joydick.h
 *
 * Created: 22.09.2014 15:43:25
 *  Author: Bengt
 */ 


#ifndef JOYDICK_H_
#define JOYDICK_H_

/*HEADER FILES*/
#include <stdio.h>
#include <stdbool.h> //...takes up a bit too much memory to use boolean type actively(one byte)....
//#include <string.h>
#include "main.h"
//#include <math.h>



/*DEFINITIONS/CONFIG*/
#define JOYSTICK_RESOLUTION_POST_CALIBRATION (100)//----

/*Function Declarations*/
uint8_t *joystickInitialize(uint8_t *);
void joystickCalibrate();
int8_t calcCalibParam(uint8_t x1,uint8_t x2,uint8_t X);
void getXPosition(uint8_t xUncalibratedPos,int8_t *xCalibratedPos);//Get calibrated position as -x < x_mid < +x
void getYPosition(uint8_t yUncalibratedPos,int8_t *yCalibratedPos);//Get calibrated position as -y < y_mid < +y

#endif /* JOYDICK_H_ */