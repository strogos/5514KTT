/*
 * SPI.c
 *
 * Created: 30.09.2014 17:26:05
 *  Author: Bengt
 */ 
#pragma once

#include "SPI.h"

void spiInit()
{
		//MOSI-SCK-SS -> output
		DDRB|= (1<<PB5)|(1<<PB7)|(1<<PB4);
		
		//MISO -->input
		DDRB&= ~(1<<PB6);
		
		//Atmegega SPI in master mode, clock rate f_crystal/16
		SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

uint8_t spiSendData(uint8_t data)
{
	//Start data transmission (SCK? start)
	SPDR=data;
	
	//wait until data is sent
	while(!(SPSR&(1<<SPIF)));
	
	return SPDR;
}

void spiRecieveData(uint8_t *data)
{
	//send dummy data (ring buffer)
	spiSendData(8);	
	
	//Wait for data to be received
	
	while(!(SPSR&(1<<SPIF)));
	*data=SPDR;	
}

void spiSlaveSelect(void)
{
	//~SS=0 (select slave)
	PORTB &= ~(1<<PB4);
}

void spiSlaveDeselect(void)
{
	//~SS=1 (deselect slave)
	PORTB |= (1<<PB4);
}