/*
 * SPI.h
 *
 * Created: 30.09.2014 17:26:21
 *  Author: Bengt
 */ 


#ifndef SPI_H_
#define SPI_H_

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


/*Function Declarations*/

void spiInit();
uint8_t spiSendData(uint8_t);
void spiRecieveData(uint8_t* data);
void spiSlaveSelect(void);
void spiSlaveDeselect(void);


#endif /* SPI_H_ */