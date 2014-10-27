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
	// Initialise external memory interface // NB: "xmemInit()" must be called before any function that uses heap memory!!
	xmemInit();
	
	
	// dummy for testing USART
	//char *dataString="\r......Booting up.\r";
		
	//init. USART
	usartInitialize();//--------*****-////TO DO: implement light diode blink if(usartInitialize()); else ERROR BLINK CODE.. also write reference for blinking code...
	
	//test external SRAM
	xmemTest();
	xmemExampleFunction();
	printf("\n\r0x%02x",xmemReadFrom(5));
	//vXMEMTestTask();
	
	
	
	uint8_t *test= malloc(4*sizeof(uint8_t));
	//uint8_t ptr->joyData[JOY_Y_AXIS_MIN];
	
	
	uint8_t buffer1=adcRead(ADC_CH1_JOY_Y_AXIS);
	uint8_t buffer2=adcRead(ADC_CH2_JOY_X_AXIS);
	

	usartSendDataString("\r\n\n@ECHO ON\r\n");
	
	joyCalibrateXY();


	int8_t x,y=0;
	while(true)
	{	
		test=joyGetUnscaledXY(test);
		//buffer1=(test[0]/2);
		//test= joystickInitialize();
		//printf("\n\r%d",test[0]);
		//printf("\n\r%d",buffer1);
		
		buffer1=adcRead(ADC_CH1_JOY_Y_AXIS);
		buffer2=adcRead(ADC_CH2_JOY_X_AXIS);
		//printf("\n\rX POS: %d\n\r",buffer2);
		joyGetPosX(buffer2,&x);
		//printf("x POS: %d",x);
		joyGetPosY(buffer1,&y);
		printf("\n\ry = %d, x = %d, Unscaled_Y = %d, Uncaled_X = %d",y,x,test[2],test[3]);
		//printf("\n\rY = %d, X = %d, Mid_Y = %d, Mid_X = %d",test[0],test[1],test[2],test[3]);
		_delay_ms(150);
		
	}

	//free(test); //equivalent of "delete [] test"
	
	//Send a string of data
	//usartSendDataString(dataString);
	
	//if(USART_ENABLE_printf)
		//printf("NOTEFICATION: printf() is LINKED to Tx on USART!\r\n");
	
	//Make some conversation...
	//usartSendDataString("Do you want to echo Rx UART data using interrupts?\r\n*Enter 'y' to accept");
	/*if(byteOfData=usartReceiveByte()=='y')
	{
		interruptOn=true;
		UCSR0B |= (1<<RXCIE0); // Enable the USART Receive Complete interrupt (USART_RXCIE0)
		sei(); //macro for enabling interrupts globally (<avr/interrupt.h> must be included)
		usartSendDataString("->interrupt on Rx is ENABLED\r\n");
	}
	else
		usartSendDataString("->interrupt on Rx DISABLED\r\n");
	*/
	
	//printf("\r\n[memCheck]: ");
	//int freeRAM;
	//freeRam();
	
	//printf("%d",freeRam());
	

	
	//Program loop
	/*while(true)
	{		
			//echo received data
			byteOfData=usartReceiveByte();
			usartSendByte(byteOfData);		
	}*/
	
}