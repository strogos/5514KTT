/**
 * --------------------------TTK-4155 - Lab Exercise 3-------------------------------
 *  ------------------------****64Kx8 ADC & Joypad ****----------------------------
 *	  ----------------------------------------------------------------------------
 *
 *	|Group participants: Bengt E. Hope; Svein Grindheim; Magnus Sogn;
 *		
 *		
 *	|Source revision: 0.8a
 *  |Last modification by: Bengt
		 *	|____________________________________________________Revision notes:_________________________________________________|
		 *	|[x]Implemented a simple joystick driver which gives user configurable axis values: LEFT=-x,RIGHT=+x,DOWN=-y and UP=+y
		 *	|[x]Joystick resolution is selectable in joystick.h using the JOYSTICK_RESOLUTION_POST_CALIBRATION definition
		 *	|[x]TODO: Create "joystick-structure" which would make possible easy config/connection of additional joysticks
		 *	|[x]TODO: Clean up joydick.h and try to avoid storing calibration parameters in a global (joydick.c scope) array
 *
 *
 **/

#pragma once

#include "main.h"

//Define some global dummy variables for testing the USART
bool interruptOn=false;
uint8_t byteOfData=0;

//main function
int main (void)
{
	// Initialize external memory interface // NB: "xmemInit()" must be called before any function that uses heap memory!!
	xmemInit(); //enable external memory addressing bits to be moved from this function!
	
	
	// dummy for testing USART
	//char *dataString="\r......Booting up.\r";
		
	//init. USART
	usartInitialize();//--------*****-////TO DO: implement light diode blink if(usartInitialize()); else ERROR BLINK CODE.. also write reference for blinking code...
	
	//test external SRAM
	xmemTest();
	xmemExampleFunction();
	printf("\n\r0x%02x",xmemReadFrom(5));
	//vXMEMTestTask();
	
	
	
//	uint8_t *test= malloc(4*sizeof(uint8_t));
	//uint8_t array[4];
	
	
	//uint8_t buffer1=adcRead(ADC_CH1_JOY_Y_AXIS);
	//uint8_t buffer2=adcRead(ADC_CH2_JOY_X_AXIS);
	
	
	
//	oledInit();
	//clearScreen();
	//uint8_t column=0,line=0;
	
	
	//SPI stuff
	spiInit();
	mcpReset();
	mcpLoopBack();
	mcpWrite(0x00, 0xdd);
	
	
	printf("\n\r%d", mcpRead(0x00));
	
	
}