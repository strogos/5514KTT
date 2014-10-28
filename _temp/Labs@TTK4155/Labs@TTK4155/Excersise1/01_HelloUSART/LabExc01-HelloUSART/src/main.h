/*
 * main.h
 *
 * Created: 27.08.2014 00:07:46
 *  Author: Bengt
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
//#include <util/delay.h>

/*header files*/
#include "macros.h"
#include "USART.h"

/*Function Declarations*/
int main(void);
ISR(USART0_RXC_vect,ISR_BLOCK);

#endif /* MAIN_H_ */