/**
 * --------------------------TTK-4155 - Lab Exercise 5 and 6-------------------------------
 *  ------------------------****SPI & CAN communication ****----------------------------
 *	  ----------------------------------------------------------------------------
 *
 *	|Group participants: Bengt E. Hope; Svein Grindheim; Magnus Sogn;
 *		
 *		
 *	|Source revision: 0.9
 *  |Last modification by: Bengt
		 *	|____________________________________________________Revision notes:_________________________________________________|
		 *	|[x]
		 *	|[x]
		 *	|[x]
		 *	|[x]
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
	
	// testing spi driver write read
	/*spiSlaveSelect();
	spi_putc(0x02);
	spi_putc(0xda);
	spi_putc(0xab);
	spiSlaveDeselect();
	
	spiSlaveSelect();
	spi_putc(0x03);
	spi_putc(0xda);
	printf("\n\r0x%02x",spi_putc(0xff));
	spiSlaveDeselect();*/
	
	//testing mcp2515 driver write, read, 
	/*mcp2515_write(0xda, 0xf3);
	printf("\n\r0x%02x", mcp2515_read(0xda));*/
	
	can_init(MODE_LOOPBACK);
	
	can_message_t message;
	
	message.id = 3;
	message.length = 8;
	for (uint8_t i=0; i<=7; i++)
	{
		message.data[i]=i;
	}
	message.data[0] = 0x1b;
	message.data[5] = 0xbb;
	
	can_message_send(&message);
	
	message.length = 4;
	for (uint8_t i=0; i<=7; i++)
	{
		
		message.data[i]=2*i;
	}
	
	
	can_message_send(&message);
	printf("\n\r0x%02x", mcp2515_read(MCP_RXB0D0));
		for (uint8_t i=0;i<=7;i++)
		{
			printf("\n\r0x%02x", mcp2515_read(MCP_RXB0D0+i));	
		}
		
	
}