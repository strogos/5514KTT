/*
 * XMEM.c
 *
 * Created: 03.09.2014 23:02:23
 *  Author: Bengt
 */ 
#pragma once

#include "XMEM.h"


 // Notice: "xmemInit()" must be called before any function that uses heap memory IF you want to use SRAM as heap memory
void xmemInit(void)
{
	/* External memory interface enable */ //no wait state during read/write strobe (not nec. with current clock)
	MCUCR = (1<<SRE)|(0<<SRW10);   

	
	
	
	EMCUCR = (0<<SRL2)|(0<<SRL1)|(0<<SRL0)|(0<<SRW01)|(0<<SRW00)|(0<<SRW11);
	/*
	    * Lower sector = N/A
		* Upper sector = 0x1100 - 0xFFFF
		* No wait cycles for upper sector
	*/
	
	//SFIOR=(1<<XMM1)|(1<<XMM0);
	SFIOR = (0<<XMBK)|(1<<XMM2)|(0<<XMM1)|(0<<XMM0);
	/*
	    * External Memory Bus-keeper Disabled;
		* External Memory High Mask - 4 bits released
	*/
	
}
void xmemTest()
{
	volatile uint8_t *ext_ram = 0x1800;  // Start address for the XMEM   
	unsigned int i, werrors, rerrors; 
	werrors = 0;  rerrors = 0;
	uint8_t testvalue;
	
	printf("Starting XMEM test...\r\n");   
	
	for (i = 0; i < 0x800; i++) 
	{
		testvalue = ~(i % 256);   
		ext_ram[i] = testvalue;   
		if (ext_ram[i] != testvalue) 
		{
			printf("XMEM error (write phase): ext_ram[%d] = %02X (should be %02X)\r\n", i, ext_ram[i], testvalue);
			werrors++;   
		}  
	}
	for (i = 0; i < 0x800; i++) 
	{
		testvalue = ~(i % 256);
		if (ext_ram[i] != testvalue) 
		{
			printf("XMEM error (read phase): ext_ram[%d] = %02X (should be %02X)\r\n", i, ext_ram[i], testvalue);
			rerrors++;
		}
	}   
	
	printf("XMEM test completed with %d errors in write phase and %d errors in read phase\r\n", werrors, rerrors); 
}

void xmemExampleFunction()
{
		uint8_t *mem;
		uint8_t index;
		printf("\r\nExternal Memory Example\r\n");
	
	    // Allocate external memory
	    mem = malloc(BUFFER_SIZE);
	
	    printf("%d Byte buffer (starting at 0x%04X) filled with 0's:\r\n",BUFFER_SIZE,mem);
	
	     // Fill memory with 0's
	    for(index = 0; index < BUFFER_SIZE; index++)
	   {
		        mem[index] = 0x00;
	   }
	     // Display memory block
	     for(index = 0; index < BUFFER_SIZE; index++)
	     {
		        printf("%02X ",mem[index]);
		         if((index&0x0F) == 0x0F)
		         {
		             printf("\r\n");
		         }
	     }
	
	     printf("\r\n%d Byte buffer (starting at 0x%04X) filled with incrementing numbers:\r\n",BUFFER_SIZE,mem);
	
	     // Fill memory with incrementing numbers
	     for(index = 0; index < BUFFER_SIZE; index++)
	     {
	         mem[index] = index;
	     }
	     // Display memory block
	     for(index = 0; index < BUFFER_SIZE; index++)
	     {
	         printf("%02X ", mem[index]);
	         if((index&0x0F) == 0x0F)
	         {
	             printf("\r\n");
	         }
	     }
		 
}

int freeRam ()
{
	extern int __heap_start;
	extern int *__brkval;
	int v;
	int returnVar;
			
	returnVar=(int) (&v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval));
}

void vXMEMTestTask()
{
	static const uint8_t xmemok[] PROGMEM="XMEM OK\r\n";
	static const uint8_t xmemfail[] PROGMEM="XMEM FAIL!\r\n";
	static const uint8_t heapfull[] PROGMEM="Heap Full\r\n";
	static const uint8_t heaprdfail[] PROGMEM="Heap Test Fail\r\n";
	static const uint8_t heaprdok[] PROGMEM="Heap Test OK\r\n";
	unsigned int *xmem;
	unsigned int xdata;
	unsigned int index, testflag=0;

	xmem = malloc(BUFFER_SIZE);

	if (xmem!=NULL)
	{
		printf("%s",xmemok);
	}
	else
	{
		printf("%s",xmemfail);
	}

	for (;;)
	{
		xdata=1;
		for(index = 0; index < BUFFER_SIZE; index++)
		{
			xmem[index] = xdata++;
		}
		printf("%s",heapfull);//read heap and test
		xdata=1;
		for(index = 0; index < BUFFER_SIZE; index++)
		{
			if (xmem[index] != xdata++)
			{
				testflag=1;break;
			}
		}
		if (!testflag)
		{
			printf("%s",heaprdok);
		}
		else
		{
			//reset flag
			testflag=0;
			printf("%s",heaprdfail);
		}
		
	}
}

int xmemWriteTo(unsigned int address, unsigned int data)
{
	
	//Start address for the SRAM
	uint8_t *memoryPosition = 0x1800;

	//Write address on SRAM
	memoryPosition[address] = data;
	
	return 0;
}

unsigned int xmemReadFrom(unsigned int address)
{
	//Start address for the xmem
	uint8_t *memoryPosition = 0x1800;
	
	//Read address from SRAM
	return memoryPosition[address];
}
