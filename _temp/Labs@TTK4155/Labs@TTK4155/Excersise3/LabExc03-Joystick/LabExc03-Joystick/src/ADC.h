/*
 * ADC.h
 *
 * Created: 09.09.2014 16:28:39
 *  Author: Bengt
 */ 


#ifndef ADC_H_
#define ADC_H_


/*HEADER FILES*/
#include <stdio.h>
#include <stdbool.h> //...takes up a bit too much memory to use boolean type actively(one byte)....
//#include <string.h>
#include "main.h"



/*DEFINITIONS/CONFIG*/
#define ADC_CH1_JOY_Y_AXIS 0//----//Y-axis Channel on ADC
#define ADC_CH2_JOY_X_AXIS 1//----//X-axis Channel on ADC
#define ADC_CH3_LEFT_SLIDER 2
#define ADC_CH4_RIGHT_SLIDER 3

/*Function Declarations*/
void adcInit(void);
uint8_t adcRead(uint8_t);




#endif /* ADC_H_ */