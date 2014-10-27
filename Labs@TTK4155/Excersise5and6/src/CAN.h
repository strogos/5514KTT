/*
 * CAN.h
 *
 * Created: 21.10.2014 14:05:55
 *  Author: sveigri
 */ 


#ifndef CAN_H_
#define CAN_H_

/*DEFINITIONS/CONFIG*/




/*header files*/
#include <asf.h>
//#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <EEPROM.h>



/*GLOBAL*/
//can message structure
typedef struct
{
	unsigned int id;
	uint8_t length;
	uint8_t data[8];
	
}can_message_t;
//Function Declarations
uint8_t can_init(uint8_t mode);
uint8_t can_message_send(can_message_t *message);
uint8_t can_message_receive(can_message_t *message);
uint8_t can_message_transmit_err_chk(void);
/*GLOBAL END*/

#endif /* CAN_H_ */