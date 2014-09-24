/*
 * joydick.c
 *
 * Created: 22.09.2014 15:43:14
 *  Author: Bengt
 */ 

#pragma once

#include "joydick.h"




uint8_t *joystickInitialize(uint8_t *joyPos)//DELETE
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



//calibration values (if global= use typedef struct to save memory)
/*Example:
typedef struct
{
	uint8_t joystick;
}t;
t global  //Declare a global structure

__C_task void main(void)
{
	t *joystick = &global;
}*/
uint8_t array[6];//TODO: make joystick structure

void joystickCalibrate()
{
	
	uint8_t byteOfData=0;
	
	
	printf("\n\rPut joystick in center position\n\r");
	if(byteOfData=usartReceiveByte()=='y');	
	array[0]=adcRead(ADC_CH1_JOY_Y_AXIS);
	array[1]=adcRead(ADC_CH2_JOY_X_AXIS);
	
	
	printf("\n\rGet X_min\n\r");
	if(byteOfData=usartReceiveByte()=='y');
	array[2]=adcRead(ADC_CH2_JOY_X_AXIS);//X_min

	printf("\n\rGet X_max\n\r");
	if(byteOfData=usartReceiveByte()=='y');
	array[3]=adcRead(ADC_CH2_JOY_X_AXIS);//X_MAX
	
	printf("\n\rGet Y_min\n\r");
	if(byteOfData=usartReceiveByte()=='y');
	array[4]=adcRead(ADC_CH1_JOY_Y_AXIS);//Y_min
	
	printf("\n\rGet Y_max\n\r");
	if(byteOfData=usartReceiveByte()=='y');
	array[5]=adcRead(ADC_CH1_JOY_Y_AXIS);//Y_MAX
	
	/*for(int j=0;j<=5;j++)
		{
			printf("\n\r%d\n\r",array[j]);	
		}
		
	
	if(byteOfData=usartReceiveByte()=='y');*/
	//Calbrate X-axis	
//	xParameters[0]=calcCalibrationPercentage(array[1]),array[2]);//min to mid
//	xParameters[1]=calcCalibrationPercentage(array[3]),array[1]);//mid to max
	
	
	//Calbrate Y-axis
//	yParameters[0]=calcCalibrationPercentage(array[0]),array[4]);//min to mid
//	yParameters[1]=calcCalibrationPercentage(array[5]),array[0]);//mid to max
	
}




int8_t calcCalibParam(uint8_t x1,uint8_t x2,uint8_t X)
{
	//skalering: Y->0-JOYSTICK_RESOLUTION_POST_CALIBRATION; X->X2-X1
	//uint8_t byteOfData=0;
	
	double slope=((double)JOYSTICK_RESOLUTION_POST_CALIBRATION/(double)(x2-x1));
	double f=(slope*((double)(X-x1)));
	
	//printf("\n\rSEEE!! %f : %f : %d : %d : %d\n\r",slope,f,x1,x2,X_variabel);	
	//if(byteOfData=usartReceiveByte()=='y');
	return (int8_t)f;
	
}

void getXPosition(uint8_t xUncalibratedPos,int8_t *xCalibratedPos)
{
	//uint8_t byteOfData=0;
	uint8_t XMid=array[1];	
	if(xUncalibratedPos>XMid)
	{
		*xCalibratedPos=calcCalibParam(array[1],array[3],xUncalibratedPos);
			
	}
	else
	{
		*xCalibratedPos=calcCalibParam(array[1],array[2],xUncalibratedPos)*(-1);
	}
	//printf("\n\r%d : %d : %d \n\r",XMid,xCalibratedPos,xUncalibratedPos);
	//if(byteOfData=usartReceiveByte()=='y');			
}

void getYPosition(uint8_t yUncalibratedPos, int8_t *yCalibratedPos)
{
		uint8_t YMid=array[0];
		if(yUncalibratedPos>YMid)
		{
			*yCalibratedPos=calcCalibParam(array[0],array[5],yUncalibratedPos);			
		}
		else
		{
			*yCalibratedPos=calcCalibParam(array[0],array[4],yUncalibratedPos)*(-1);		
		}
		
}

