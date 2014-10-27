/*
 * OLED.c
 *
 * Created: 23.09.2014 14:45:33
 *  Author: sveigri
 */ 
#pragma once

#include "OLED.h"

volatile uint8_t *oledCmdAddress = 0x1000;
volatile uint8_t *oledDataAddress = 0x1200;

void oledInit()
{
	 *oledCmdAddress =0xae; // display off
	 *oledCmdAddress =0xa1; //segment re-map
	 *oledCmdAddress =0xda; //common pads hardware: alternative
	 *oledCmdAddress =0x12;
	 *oledCmdAddress =0xc8; //common output scan direction:com63~com0
	 *oledCmdAddress =0xa8; //multiplex ration mode:63
	 *oledCmdAddress =0x3f;
	 *oledCmdAddress =0xd5; //display divide ratio/osc. freq. mode
	 *oledCmdAddress =0x80;
	 *oledCmdAddress =0x81; //contrast control
	 *oledCmdAddress =0x10;
	 *oledCmdAddress =0xd9; //set pre-charge period
	 *oledCmdAddress =0x21;
	 *oledCmdAddress =0x20; //Set Memory Addressing Mode
	 *oledCmdAddress =0x02;
	 *oledCmdAddress =0xdb; //VCOM deselect level mode
	 *oledCmdAddress =0x30;
	 *oledCmdAddress =0xad; //master configuration
	 *oledCmdAddress =0x00;
	 *oledCmdAddress =0xa4; //out follows RAM content
	 *oledCmdAddress =0xa6; //set normal display
	 *oledCmdAddress =0xaf; // display on*/
}

void oledPrint(uint8_t line,uint8_t column)
{	
	setLine(line);
	setColumn(column);
	
	//exclamation mark!
	*oledDataAddress=0b00000110;
	*oledDataAddress=0b01011111;
	*oledDataAddress=0b01011111;
	*oledDataAddress=0b00000110;
	*oledDataAddress=0b00000000;
	*oledDataAddress=0b00000000;
	*oledDataAddress=0b00000000;	
}

void clearLine(uint8_t line)
{	
	//go to needed line(page)
	setLine(line);
	for(int k=0; k<128; k++)
	{
		*oledDataAddress=0x00;							
	}
}

void clearScreen()
{
	//increment through all lines(pages)
	for(int line=0; line<=7; line++)
	{
		clearLine(line);
	}
}

void setLine(uint8_t line)
{	
	//Set page start address
	*oledCmdAddress=0xB0|line;
	//Set LOWER Column Start address (Page addr. mode)
	*oledCmdAddress=0x00;
	//Set HIGHER Column Start address (Page addr. mode)
	*oledCmdAddress=0x10;
}

void setColumn(uint8_t column)
{
	//Set LOWER Column Start address (Page addr. mode)
	*oledCmdAddress=0x00;
	//Set HIGHER Column Start address (Page addr. mode)
	*oledCmdAddress=0x10|(column);
}