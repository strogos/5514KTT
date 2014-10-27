/*
 * helpHeader.h
 *
 * Created: 26.08.2014 15:11:32
 *  
 */


#ifndef HELPHEADER_H_
	#define HELPHEADER_H_
	#define set_bit(reg,bit) (reg |=(1<<bit))
	#define clear_bit(reg,bit) (reg &=~(1<<bit))
	#define test_bit(reg, bit) (reg & (1<<bit))
	//Define CPU frequency
	
	#define F_CPU 4915200
	
#endif /* HELPHEADER_H_ */