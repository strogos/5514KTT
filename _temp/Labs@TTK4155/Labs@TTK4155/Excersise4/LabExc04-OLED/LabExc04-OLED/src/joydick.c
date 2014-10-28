/*
 * joydick.c
 *
 * Created: 22.09.2014 15:43:14
 *  Author: Bengt
 */ 

#pragma once

#include "joydick.h"




uint8_t *joyGetUnscaledXY(uint8_t *joyPos)
{
	
	uint8_t buffer1=adcRead(ADC_CH1_JOY_Y_AXIS);
	uint8_t buffer2=adcRead(ADC_CH2_JOY_X_AXIS);
	uint8_t buffer3=buffer1;
	uint8_t buffer4=buffer2;
	//printf("\n\r%d",buffer3);
	joyPos[0]=buffer1;
	joyPos[1]=buffer2;
	joyPos[2]=buffer3;
	joyPos[3]=buffer4;
	
	return joyPos;
	
}


/*USART.c "GLOBAL" VARIABLES*/
//define a structure to hold joydick.c "global" variables to save some memory space
typedef struct
{
	
	uint8_t joyData[6];//-------//Store calibration parameters in memory
	
	
}globalStruct;
globalStruct globalVar;

uint8_t array[6];
void joyCalibrateXY()
{
	//some buffer variables/ptrs
	uint8_t byteOfData=0;
	globalStruct *ptr=&globalVar;
	
	printf("\n\rPut joystick in center position\n\r");
	while(((byteOfData=usartReadByte())!='y'));
	ptr->joyData[JOY_Y_AXIS_MID]=adcRead(ADC_CH1_JOY_Y_AXIS);
	ptr->joyData[JOY_X_AXIS_MID]=adcRead(ADC_CH2_JOY_X_AXIS);
	
	printf("\n\rGet X_min\n\r");
	while(((byteOfData=usartReadByte())!='y'));
	ptr->joyData[JOY_X_AXIS_MIN]=adcRead(ADC_CH2_JOY_X_AXIS);
	
	printf("\n\rGet X_max\n\r");
	while(((byteOfData=usartReadByte())!='y'));
	ptr->joyData[JOY_X_AXIS_MAX]=adcRead(ADC_CH2_JOY_X_AXIS);
	
	printf("\n\rGet Y_min\n\r");
	while(((byteOfData=usartReadByte())!='y'));
	ptr->joyData[JOY_Y_AXIS_MIN]=adcRead(ADC_CH1_JOY_Y_AXIS);
	
	printf("\n\rGet Y_max\n\r");
	while(((byteOfData=usartReadByte())!='y'));
	ptr->joyData[JOY_Y_AXIS_MAX]=adcRead(ADC_CH1_JOY_Y_AXIS);
}


int8_t calcCalibParam(uint8_t x1,uint8_t x2,uint8_t x)
{
	/*scale incoming values as a linear eq. with limits: 0<y<100; x2<x<x1;*/	
	//uint8_t byteOfData=0;
	
	double slope=((double)JOY_YX_AXIS_SCALING_PARAM/(double)(x2-x1));
	double f=(slope*((double)(x-x1)));
	
	return (int8_t)f;	
}


void joyGetPosX(uint8_t xUncalibratedPos,int8_t *xCalibratedPos)
{
	globalStruct *ptr=&globalVar;
		
	if(xUncalibratedPos>ptr->joyData[JOY_X_AXIS_MID])
	{
		*xCalibratedPos=calcCalibParam(ptr->joyData[JOY_X_AXIS_MID],ptr->joyData[JOY_X_AXIS_MAX],xUncalibratedPos);			
	}
	else
	{
		*xCalibratedPos=calcCalibParam(ptr->joyData[JOY_X_AXIS_MID],ptr->joyData[JOY_X_AXIS_MIN],xUncalibratedPos)*(-1);
	}
			
}

void joyGetPosY(uint8_t yUncalibratedPos, int8_t *yCalibratedPos)
{
		globalStruct *ptr=&globalVar;
		
		if(yUncalibratedPos>ptr->joyData[JOY_Y_AXIS_MID])
		{
			*yCalibratedPos=calcCalibParam(ptr->joyData[JOY_Y_AXIS_MID],ptr->joyData[JOY_Y_AXIS_MAX],yUncalibratedPos);			
		}
		else
		{
			*yCalibratedPos=calcCalibParam(ptr->joyData[JOY_Y_AXIS_MID],ptr->joyData[JOY_Y_AXIS_MIN],yUncalibratedPos)*(-1);			
		}
		
}

