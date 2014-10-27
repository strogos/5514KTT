/*
 * ADC.c
 *
 * Created: 09.09.2014 16:28:28
 *  Author: Bengt
 */ 

#include "ADC.h"
void adcInit()
{
	
}
uint8_t adcRead(uint8_t adcChannel)
{
	//check if the channel on the ADC exceeds number of used channels
	if(!(adcChannel<=3)&&(adcChannel>0))
		return 0;
	/*
		4 channels on ADC:
			- adcChannel 0 = Joypad y-axis
			- adcChannel 1 = Joypad x-axis
			- adcChannel 2 = Joypad left slider
			- adcChannel 3 = Joypad right slider
	*/	
	
	//set start position for ADC addressing
	volatile uint8_t *adcAddressing = 0x1400;
					
	//Choose address to work with in the ADC based on channel set in adcChannel
	*adcAddressing = (0x04|adcChannel);
	
	_delay_us(40);//add delay between reads - AT LEAST 40uS if using interrupt for ADC0844CNN (if no delay; adc will read from the prevously selected channel )
		
	//wait for data to be read (..implement interrupt!!!)
	while(PINE & (1<<PINE0));//test PINE0 for changes (pin is cleared)
		
	return *adcAddressing;
}