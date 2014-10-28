/*
 * USART.h
 *
 * Created: 26.08.2014 23:39:43
 *  Author: Bengt
 */ 


/* Some comments:

Remember that the USART/USART doesn't use an external clock.
However; the clock is derived from the system clock, and it is used to 
sample the Rx line and set the Tx line at precise intervals
in order to maintain the communications.

System clocks for perfect USART/USART communications can for example be multiples of
1.8432MHz - which will give a 0.00% error.
Other frequencies for the main AVR clock can be used, but as the frequency drifts from the
“perfect” multiples of 1.8432MHz, the greater the percentage error will be (and thus the less
reliable the serial communication will be). It is generally accepted that error percentages of less
than ±2% are acceptable.

An XTAL @ 4.9152 MHz (and multiples of it) will also give a "perfect" error %...

	UBRR (USART Baud Register) :
			-	Default Operating Mode: Asynchronous Normal Mode (U2X=0):
				* set USART_OPERATING_MODE_U2X=0;
			-	Secondary Operating Mode: Asynchronous Double Speed Mode (U2X=1):
				* set USART_OPERATING_MODE_U2X=1;
		
When U2x=0 we have:
	- UBRR = (((F_cpu /(USART_BAUDRATE * 16))) - 1)

HOWEVER; IF integer trunctuation is noticed (...not getting the expected baudrate) due to integer devision,
USE: 
	- UBRR = ((F_CPU + USART_BAUD_RATE * 8L) / (USART_BAUD_RATE * 16L) - 1)

When doing integer division it is usually better to round to the nearest integer, rather than to the lowest. 

*/


#ifndef USART_H_
#define USART_H_



/*HEADER FILES*/
#include <stdio.h>
#include <stdbool.h> //...takes up a bit too much memory to use boolean type actively(one byte)....
//#include <string.h>
#include "main.h"


/*DEFINITIONS/CONFIG*/
#define USART_OPERATING_MODE_U2X false//----//Define USART operating mode
#define USART_BAUDRATE 9600//---------------//Define USART baud rate
#define USART_ENABLE_printf true//----------//Link Printf() to usart (very resource demanding)

/*Function Declarations*/
void usartInitialize(void);
uint8_t usartReceiveByte(void);
void usartSendByte(uint8_t byteToSend);
void usartSendDataString(const char *dataString);

#endif /* USART_H_ */