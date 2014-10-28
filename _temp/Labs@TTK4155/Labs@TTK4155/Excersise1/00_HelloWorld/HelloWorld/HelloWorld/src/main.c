/* This file blinks a LED when a button is pressed
The button is connected to PINB1 and the switch to PORTB2
The button draws PINB high when pressed, and a 10 k pulldown resistor grounds the switch when not pressed */




//Main Libraries
#include <asf.h>
#include <avr/io.h>

//Headers
#include "helpHeader.h"

//util libraries
#include <util/delay.h>





int main (void){
	//DDRB = (1<<DDB2);
	
	 // Configure pin as output
	//set_bit(DDRB, DDB0);
	DDRB=0x01;
	PORTB=0x00;
	
	
	while(true){
		
		PORTB=0x01;
		_delay_ms(1000);
		PORTB=0x00;
		_delay_ms(1000);
		
	
	
	
	
	
	
		
		
		//PORTB = PINB<<1; // Not a good solution. Reads many inputs which are unterminated and writes to the entire port.
		/*
		if(test_bit(PINB, PINB1)){
			set_bit(PORTB, PORTB2);
			
		}
		else{
			clear_bit(PORTB, PORTB2);
			
		}
		*/
		//test_bit(PINB,PINB1) ? set_bit(PORTB, PORTB2) : clear_bit(PORTB, PORTB2); // Identical in function to the one above, but more compact.
	}
}