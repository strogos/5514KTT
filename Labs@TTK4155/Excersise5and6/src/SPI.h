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



/*Function Declarations*/
void spiInit();
uint8_t spiSendReceiveData(uint8_t data);//puts a byte (data argument) on the transmission buffer. Returns received data.
void spiSlaveSelect(void);
void spiSlaveDeselect(void);


#endif /* SPI_H_ */