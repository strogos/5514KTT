/**
 * --------------------------TTK-4155 - Lab Exercise 1-------------------------------
 *  ------------------------****RS-232 Communication****----------------------------
 *	  ----------------------------------------------------------------------------
 *
 *	|Group participants: Bengt E. Hope; Svein Grindheim; Magnus Sogn;
 *		
 *		
 *	|Source revision: 1.0
 *  |Last modification by: Bengt
		 *	|________________________Revision notes:_____________________________|
		 *	|[x]Implemented functionality for basic RS-232 communication
		 *	|[x]Possible to send single byte or a string of bytes over USART
		 *	|[x]Linked printf() to USART output (left input as NULL)
		 *	|[x]Enabled USART to function with interrupts(echo Rx data)
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
	
	// dummy for testing USART
	char *dataString="\r......Booting up.\r";
		
	//init. USART
	usartInitialize();//--------*****-////TO DO: implement light diode blink if(usartInitialize()); else ERROR BLINK CODE.. also write reference for blinking code...
	
	//Send a string of data
	usartSendDataString(dataString);
	
	if(USART_ENABLE_printf)
		printf("NOTEFICATION: printf() is LINKED to Tx on USART!\r\n");
	
	//Make some conversation...
	usartSendDataString("Do you want to echo Rx UART data using interrupts?\r\n*Enter 'y' to accept");
	if(1)//byteOfData=usartReceiveByte()=='y')
	{
		interruptOn=true;
		UCSR0B |= (1<<RXCIE0); // Enable the USART Receive Complete interrupt (USART_RXCIE0)
		sei(); //macro for enabling interrupts globally (<avr/interrupt.h> must be included)
		usartSendDataString("->interrupt on Rx is ENABLED\r\n");
	}
	else
		usartSendDataString("->interrupt on Rx DISABLED\r\n");
	
	usartSendDataString("@ECHO ON\r\n");
	
	//Program loop
	while(true)
	{
		if(!interruptOn)
		{
			//echo received data
			byteOfData=usartReceiveByte();
			usartSendByte(byteOfData);
		}
	}
}

//interrupt function
ISR (USART0_RXC_vect,ISR_BLOCK)
{
	if (interruptOn)
	{
		byteOfData=UDR0;//grab byte
		UDR0=byteOfData;//echo grabbed byte
	}
}
