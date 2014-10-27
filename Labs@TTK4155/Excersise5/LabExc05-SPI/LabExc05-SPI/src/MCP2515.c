/*
 * MCP2515.c
 *
 * Created: 21.10.2014 13:11:31
 *  Author: sveigri
 */ 

#pragma once

#include "MCP2515.h"

void mcp2515_write(uint8_t address, uint8_t data)
{
	spiSlaveSelect();
	
	spiSendReceiveData(MCP_WRITE); //write
	spiSendReceiveData(address);
	spiSendReceiveData(data);
	
	spiSlaveDeselect();
}

uint8_t mcp2515_read(uint8_t address)
{
	uint8_t data_in;
	spiSlaveSelect();
	
	spiSendReceiveData(MCP_READ); //read
	spiSendReceiveData(address);
	
	data_in = spiSendReceiveData(0xff); // send junk
	
	spiSlaveDeselect();
}

void mcp2515_reset(void)
{
	spiSlaveSelect();
	
	spiSendReceiveData(MCP_RESET); // reset
	
	spiSlaveDeselect();
}

void mcp2515_bit_modify(uint8_t address, uint8_t mask, uint8_t data)
{
	spiSlaveSelect();
	
	spiSendReceiveData(MCP_BITMOD); // bit modify
	spiSendReceiveData(address);
	spiSendReceiveData(mask);
	spiSendReceiveData(data);
	
	spiSlaveDeselect();
}

uint8_t mcp2515_read_status(void)
{
	uint8_t data_in;
	
	spiSlaveSelect();
	
	spiSendReceiveData(MCP_READ_STATUS); // read status
	data_in = spiSendReceiveData(0xff); // send junk
	
	
	spiSlaveDeselect();
	
	return data_in;
}


void mcp2515_rts(uint8_t nnn)
{
	uint8_t rts = MCP_RTS;
	
	if(nnn < 8)
	{
		rts |= nnn;
	}
	//else: ignore command (nnn)
	
	spiSlaveSelect();
	spiSendReceiveData(rts);
	spiSlaveDeselect();
	
}