/*
 * USART.c
 *
 * Created: 26.08.2014 23:42:02
 *  Author: Bengt
 */ 
#pragma once

#include "USART.h"


void usartInitialize()
{
		/*UBRR (USART Baud Register) variable to hold calculated serial port config values (16 bits)
				-	Default Operating Mode: Asynchronous Normal Mode (U2X=0):
					* set USART_OPERATING_MODE_U2X=0;
				-	Secondary Operating Mode: Asynchronous Double Speed Mode (U2X=1):
					* set USART_OPERATING_MODE_U2X=1;		
		*/
		#if USART_OPERATING_MODE_U2X
			unsigned int UBRR=(F_CPU / (8UL * USART_BAUDRATE)) - 1; //if integer trunctuation is noticed (...not getting the expected baudrate) due to integer devision, USE: ((F_CPU + USART_BAUD_RATE * 8L) / (USART_BAUD_RATE * 16L) - 1) instead. When doing integer division it is usually better to round to the nearest integer, rather than to the lowest. 
			UCSR0A |= (1<<U2X0);//---------------------------//U2x=1
		#else
			unsigned int UBRR=(F_CPU / (16UL * USART_BAUDRATE)) - 1;
			UCSR0A &= ~(1<<U2X0);//---------------------------//U2X=0
		#endif

		//Set up the baud rate for USART0
		UBRR0L=UBRR;//---------------------------// load lower 8 bits of baud rate value
		UBRR0H=(UBRR>>8);//---------------------------// load upper 8 bits of baud rate value	
		
		//Enable Tx & Rx
		UCSR0B=(1<<TXEN0)|(1<<RXEN0);
				
		/*Configure Data Format: 
			-	Data Bits = 8;
			-	Stop Bits = 2;
			-	Parity = EVEN;		
		*/
		UCSR0C = (1<<URSEL0)|(1<<USBS0)|(3<<UCSZ00)|(1<<UPM01);
		
		/*
		* If "USART_ENABLE_printf" is set we can bind printf to "usartSendByte(..)" function by calling fdevopen(..).
		* About fdevopen():
		*	- First parameter: address to a function which outputs a single character.
		*	- Second parameter: optional; used for get functions, ie. receiving a character from the USART.
		*	- BEAWARE that this function uses malloc()
		*/
		if(USART_ENABLE_printf)
		{
			fdevopen(&usartSendByte,NULL);
			
			// Create printf Stream structure
			//FILE printf_stream = FDEV_SETUP_STREAM(usartSendByte, NULL, _FDEV_SETUP_WRITE); !!!TODO; FOR implementing automatic CR (/r) send for endl(/n)
		}
		
		
		if(USART_INTERRUPT_RX)
		{
			UCSR0B |= (1<<RXCIE0); // Enable the USART Receive Complete interrupt (USART_RXCIE0)
			//Enable the interrupts globally. 
			sei();
		}
}




/*USART.c "GLOBAL" VARIABLES*/
//define a structure to hold usart.c "global" variables to save some memory space
typedef struct 
{
		volatile uint8_t RXdata;
		uint8_t RXdataBuffer;		
		
}UsartGlobalStruct;
//assign the global structure defined above
UsartGlobalStruct globalVariables;

//volatile uint8_t byteOfData; //to hold data on RX interrupt
//interrupt if receiving data
ISR (USART0_RXC_vect,ISR_BLOCK)
{
	if (USART_INTERRUPT_RX)
	{
		UsartGlobalStruct *ptr=&globalVariables;	
		ptr->RXdata=UDR0;//grab RX byte 
	}
}
uint8_t usartReadByte(void)
{
	if(USART_INTERRUPT_RX)
	{
		UsartGlobalStruct *ptr=&globalVariables;
		ptr->RXdataBuffer=ptr->RXdata;//--------//dataBuffer to hold previously received data
		ptr->RXdata=NULL;//-------------------//make sure that read data is not latched in memory until next interrupt occurs
		return ptr->RXdataBuffer;
		
	}
	else
	{
		while((UCSR0A&(1<<RXC0))==0);//---------------------------//wait until data is received
		return UDR0;//-------------------------------------------//return received data
	}
}





//Send a byte using USART
void usartSendByte(uint8_t byteToSend)
{
		while((UCSR0A&(1<<UDRE0))==0);//---------------//Only transmit data if data bus is available (not already transmitting)
		UDR0=byteToSend;//---------------------------//transmit byte
}

//Send a string of data using USART
void usartSendDataString(const char *dataString)
{
	while(*dataString)
	{
		usartSendByte(*dataString);
		dataString++;
	}
}

