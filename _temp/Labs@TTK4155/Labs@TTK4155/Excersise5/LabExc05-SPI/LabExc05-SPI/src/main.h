/*
 * main.h
 *
 * Created: 27.08.2014 00:07:46
 *  Author: Bengt
 */ 

/*
If you want to allocate SRAM for heap memory!
Linker options: 
Project properties AVR/GNU C Linker-> Miscellaneous enter linker option:
-Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x8030ff
-Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x8090ff
*/

#ifndef MAIN_H_
#define MAIN_H_


/*DEFINITIONS/CONFIG*/
#define F_CPU 4915200//---------------//Define CPU frequency 

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
#include "macros.h"
#include "USART.h"
#include "XMEM.h"
#include "ADC.h"
#include "joydick.h"
#include "OLED.h"
#include "SPI.h"
#include "MCP2515.h"
/*Function Declarations*/
int main(void);
ISR(USART0_RXC_vect,ISR_BLOCK);

#endif /* MAIN_H_ */