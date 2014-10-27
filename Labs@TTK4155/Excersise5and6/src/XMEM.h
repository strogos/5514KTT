/*
 * XMEM.h
 *
 * Created: 03.09.2014 23:02:34
 *  Author: Bengt
 */ 


#ifndef XMEM_H_
#define XMEM_H_

#include <asf.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>


/*DEFINITIONS/CONFIG*/
#define BUFFER_SIZE 64// Define size of memory block


void xmemInit(void);
void xmemTest(void);
unsigned int xmemWriteAndReadTest(void);


void xmemExampleFunction(void);//to be rewritten
int freeRam(void);//to be rewritten
int xmemWriteTo(unsigned int address, unsigned int data);//to be rewritten
unsigned int xmemReadFrom(unsigned int address);//to be rewritten
void vXMEMTestTask(void);

#endif /* XMEM_H_ */