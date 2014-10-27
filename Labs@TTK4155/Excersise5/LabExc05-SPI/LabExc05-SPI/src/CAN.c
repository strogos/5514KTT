/*
 * CAN.c
 *
 * Created: 21.10.2014 14:05:43
 *  Author: sveigri
 */ 

#pragma once

#include "CAN.h"
#include "MCP2515.h"

/*.c "GLOBAL"(file-scope) VARIABLES*/
typedef struct
{
	//interrupt flags (..trying to keep ISR functions short)
	uint8_t intFlagRX0;
	//uint8_t intFlagTX0;
	
}globalStruct;
globalStruct globalVar;

uint8_t can_init(uint8_t mode)
{

	
	mcp2515_reset();//device enters configuration mode on reset
	
	if (mode!=MODE_CONFIG)
	{
		printf("\r\nERROR: CAN controller failed to reset on request");
		printf("\n\rCurrent CAN controller mode: 0x%02x", mcp2515_read(MCP_CANSTAT));		
		printf("\r\CAN controller NOT initialized!");		
		return -1;
	}
		  	
	//Set CNF1
	//mcp2515_write(MCP_CNF1,someBaudRateConfig);
	
	//enable interrupt on RX0
	mcp2515_bit_modify(MCP_CANINTE,0x01,0xFF);
	
	//clear all existing masks on RX0 msgs
	mcp2515_bit_modify(MCP_RXM0SIDH,0xFF,0x00);
	mcp2515_bit_modify(MCP_RXM0SIDL,0xE3,0x00);
	mcp2515_bit_modify(MCP_RXF0SIDL,0x08,0x00);
	//allow any RX0 message format (ignore any masks - ONLY FOR DEBUGGING); enable rollover from RXB0->RXB1 if RXB0 is full 
	mcp2515_bit_modify(MCP_RXB0CTRL,0x64,0xFF);
	
	//Set operating mode of controller
	mcp2515_write(MCP_CANCTRL, mode);
	//mcp2515_bit_modify(MCP_CANCTRL,MODE_MASK,mode);
	
	if ((mcp2515_read(MCP_CANSTAT)&MODE_MASK)!=mode) 
	{		
		printf("\r\nERROR: CAN controller not configured correctly");
		printf("\n\rCurrent CAN controller mode: 0x%02x", mcp2515_read(MCP_CANSTAT));
		return -2;
	}
	
		
	return 1;//init. successful
}

uint8_t can_message_send(can_message_t *message)
{
	uint8_t length = message->length;
	uint8_t txreqFlag=(mcp2515_read_status()&(1<<2));//check txreq bit state using read status instruction
	
	if (txreqFlag)
	{
		//for simplicity: we won't try to send a new message if a transmission is already being sent
		return can_message_transmit_err_chk();
	}
	
	// setting id; using 11 id bits;
	mcp2515_write(MCP_TXB0SIDH, (uint8_t)(message->id>>3));
	mcp2515_write(MCP_TXB0SIDL, (uint8_t)(message->id<<5));
	
	// setting data length code
	mcp2515_write(MCP_TXB0DLC, length);
	
	// setting data
	for (uint8_t i=0;i<length;i++) 
	{
		mcp2515_write(MCP_TXB0D0+i, message->data[i]);
	}
	
	// Request To Send message using tx0
	mcp2515_rts(0x01);
	return 1;	
}

uint8_t can_message_receive(can_message_t *message)
{
	globalStruct *ptr=&globalVar;
	
	if (!ptr->intFlagRX0)	
		return -1;//no message to fetch from RX0 buffer
		
	/*fetch message from RX0 buffer*/
	message->id=(mcp2515_read(MCP_RXB0SIDH)<<3)|(mcp2515_read(MCP_RXB0SIDL)>>5);//"bitshift back" and rebuild the the complete id 
	message->length=mcp2515_read(MCP_RXB0DLC)&MCP_CANCTRL;
	//fetch data
	for(int i=0; i<message->length; i++)
	{
		message->data[i]=mcp2515_read(MCP_RXB0D0+i);
	}
	
	ptr->intFlagRX0=0; //reset flag after msg fetch
	return 1; //message fetched from RX0 buffer
}

uint8_t can_message_transmit_err_chk(void)
{
	uint8_t err=mcp2515_read(MCP_TXB0CTRL);
	
	//TO BE REVIEWED;
	if (err&(1<<4))
		return -1;//transmission error detected
	if (err&(1<<5))
		return -2;//Message lost arbitration while being sent. (msg with higher priority is being sent instead)
	
	return 0;//no error detected
}

//interrupt vector for CAN RX0 (CONNECT TO INT0 on atmega to INT pin on mcp2515)
ISR (INT0_vect)
{		
	if(mcp2515_read(MCP_EFLG)&(1<<6))//accept message if no overflow detected on RX0 (checking EFLG[6])
	{
		globalStruct *ptr=&globalVar;
		ptr->intFlagRX0=1;//flag the interrupt
	}
	
	//clear RX0 interrupt flag (TODO:move to transmit func.??)
	mcp2515_bit_modify(MCP_CANINTF,0x01,0x00);
	//clear RX0OVR overflow flag
	mcp2515_bit_modify(MCP_EFLG,0x06,0x00);
}