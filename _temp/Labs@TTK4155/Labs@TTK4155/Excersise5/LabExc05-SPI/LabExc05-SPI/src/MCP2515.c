/*
 * MCP2515.c
 *
 * Created: 07.10.2014 13:54:53
 *  Author: sveigri
 */ 

#pragma once

#include "MCP2515.h"

void mcpReset()
{
	spiSlaveSelect();
	
	spiSendData(0xC0);
	
	spiSlaveDeselect();
}

void mcpLoopBack()
{
	spiSlaveSelect();
	
	spiSendData(0x40);
	
	spiSlaveDeselect();
}

uint8_t mcpRead(uint8_t address)
{
	uint8_t data;
	
	spiSlaveSelect();
	
	spiSendData(0x03);
	spiSendData(address);
	
	data = spiSendData(0xff);
	
	spiSlaveDeselect();
	
	return data;
}

void mcpWrite(uint8_t address, uint8_t data)
{
	spiSlaveSelect();
	
	spiSendData(0x02);
	spiSendData(address);
	spiSendData(data);
	
	spiSlaveDeselect(); 
}

void mcpBitModify(uint8_t address, uint8_t mask, uint8_t data)
{
	spiSlaveSelect();
	
	spiSendData(0x05);
	spiSendData(address);
	spiSendData(mask);
	spiSendData(data);
	
	spiSlaveDeselect();
}

uint8_t mcpReadStatus(void)
{
	uint8_t data;
	
	spiSlaveSelect();
	
	spiSendData(0xa0);
	data = spiSendData(0xff);
	
	spiSlaveDeselect();
	
	return data;
	
}

void mcpRequestToSend(uint8_t T2T1T0)
{
	uint8_t command = 0x80;
	
	if(T2T1T0<8)
	{
		command |= T2T1T0;	
	}
	
	spiSlaveSelect();
	
	spiSendData(command);
	
	spiSlaveDeselect();
}