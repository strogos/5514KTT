/*
 * macro.h
 *
 * Created: 26.08.2014 23:51:17
 *  Author: Bengt
 */ 


#ifndef MACRO_H_
#define MACRO_H_

//define some macros
//#define TRUE 1
//#define FALSE 0
//#define set_bit( reg, bit ) (reg |= (1 << bit))
//#define clear_bit( reg, bit ) (reg &= ~(1 << bit))
//#define test_bit( reg, bit ) (reg & (1 << bit))
//#define loop_until_bit_is_set( reg, bit ) while( !test_bit( reg, bit ) )
//#define loop_until_bit_is_clear( reg, bit ) while( test_bit( reg, bit ) )


#define bit_get(p,m) ((p) & (m))
#define bit_set(p,m) ((p) |= (m))
#define bit_clear(p,m) ((p) &= ~(m))
#define bit_flip(p,m) ((p) ^= (m))
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))
#define BIT(x) (0x01 << (x))
#define LONGBIT(x) ((unsigned long)0x00000001 << (x))

#endif /* MACRO_H_ */