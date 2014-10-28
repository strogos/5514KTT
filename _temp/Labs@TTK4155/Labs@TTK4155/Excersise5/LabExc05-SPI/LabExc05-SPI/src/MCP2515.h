/*
 * MCP2515.h
 *
 * Created: 07.10.2014 13:55:09
 *  Author: sveigri
 */ 


#ifndef MCP2515_H_
#define MCP2515_H_

/*DEFINITIONS/CONFIG*/
//---------------//Define CPU frequency

/*Global constants*/
//extern const var variable

/*header files*/
#include <asf.h>
//#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <EEPROM.h>

/*header files*/
#include "SPI.h"

/*Function Declarations*/
void mcpReset(void);
void mcpLoopBack(void);
uint8_t mcpRead(uint8_t address);
void mcpWrite(uint8_t address, uint8_t data);
void mcpBitModify(uint8_t address, uint8_t mask, uint8_t data);
uint8_t mcpReadStatus(void);
void mcpRequestToSend(uint8_t command);

#endif /* MCP2515_H_ */