/*
 * OLED.h
 *
 * Created: 23.09.2014 14:45:48
 *  Author: sveigri
 */ 


#ifndef OLED_H_
#define OLED_H_


/*DEFINITIONS/CONFIG*/
//---------------//Define CPU frequency

/*Global constants*/
//extern const var variable

/*header files*/
#include <asf.h>
//#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include <EEPROM.h>

/*header files*/


/*Function Declarations*/

void oledInit();
void oledPrint(uint8_t,uint8_t);
void clearLine(uint8_t);
void clearScreen();
void setLine(uint8_t line);
void setColumn(uint8_t column);
#endif /* OLED_H_ */