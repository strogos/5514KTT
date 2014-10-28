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

/*JOYSTICK MACROS*/
#define JOY_X_AXIS_MID 1//-----//
#define JOY_X_AXIS_MIN 2//-----//
#define JOY_X_AXIS_MAX 3//-----//
#define JOY_Y_AXIS_MID 0//-----//
#define JOY_Y_AXIS_MIN 4//-----//
#define JOY_Y_AXIS_MAX 5//-----//
#define JOY_YX_AXIS_SCALING_PARAM 100//define maximum joystick-axis value (e.g. 100 gives -100<x<100 and -100<y<100)

/*Function Declarations*/
uint8_t *joyGetUnscaledXY(uint8_t *);
void joyCalibrateXY();
int8_t joyScaleXY(uint8_t x1,uint8_t x2,uint8_t X);
void joyGetPosX(uint8_t xUncalibratedPos,int8_t *xCalibratedPos);//Get calibrated position as -x < x_mid < +x
void joyGetPosY(uint8_t yUncalibratedPos,int8_t *yCalibratedPos);//Get calibrated position as -y < y_mid < +y

#endif /* JOYDICK_H_ */