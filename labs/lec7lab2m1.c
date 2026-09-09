#include "std_types.h"
#define F_CPU 1000000UL
#include <util/delay.h>

#include "DIO.h"
#include "SPI.h"

int main(void)
{
	DIO_voidSetPinDirection(DPORTB, PIN4, OUTPUT);
	DIO_voidSetPinDirection(DPORTB, PIN5, OUTPUT); 
	DIO_voidSetPinDirection(DPORTB, PIN6, INPUT);  
	DIO_voidSetPinDirection(DPORTB, PIN7, OUTPUT); 

	
	DIO_voidSetPinValue(DPORTB, PIN4, HIGH);

	SPI_InitMaster();

	while (1)
	{
		
		DIO_voidSetPinValue(DPORTB, PIN4, LOW);

		SPI_SendChar('1');
		
		DIO_voidSetPinValue(DPORTB, PIN4, HIGH);

		
	}
}
