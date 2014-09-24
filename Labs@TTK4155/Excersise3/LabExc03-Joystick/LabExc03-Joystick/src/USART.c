/*
 * USART.c
 *
 * Created: 26.08.2014 23:42:02
 *  Author: Bengt
 */ 
#pragma once

#include "USART.h"

///<summary>
///Configure USART HVORFOR I HELVETE FUNKER IKKE SUMMARY I SHELLET????
///</summary>
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
		
		
		//Enable the interrupts globally. //--------*****-////TO DO: Interrupt-based USART
		//SREG |= _BV(SREG_I);	
}

///<summary>
/////Receive a byte using USART
///</summary>
uint8_t usartReceiveByte(void)
{
	while((UCSR0A&(1<<RXC0))==0);//---------------------------//wait until data is received
	
	return UDR0;//-------------------------------------------//return received data
}

///<summary>
///Send a byte using USART
///</summary>
void usartSendByte(uint8_t byteToSend)
{
		while((UCSR0A&(1<<UDRE0))==0);//---------------//Only transmit data if data bus is available (not already transmitting)
		UDR0=byteToSend;//---------------------------//transmit byte
}

///<summary>
///Send a string of data using USART
///</summary>
void usartSendDataString(const char *dataString)
{
	while(*dataString)
	{
		usartSendByte(*dataString);
		dataString++;
	}
}