#include "std_types.h"
#define F_CPU 1000000UL

#include "BITMATH.h"
#include "DIO.h"
#include "SPI.h"

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTA, PIN0, OUTPUT);

	
	DIO_voidSetPinDirection(DPORTB, PIN4, INPUT);  
	DIO_voidSetPinDirection(DPORTB, PIN5, INPUT);  
	DIO_voidSetPinDirection(DPORTB, PIN6, OUTPUT); 
	DIO_voidSetPinDirection(DPORTB, PIN7, INPUT);  

	SPI_InitSlave();

	u8 received_data;

	while (1)
	{
		
		received_data = SPI_GetChar();

		if (received_data == '1')
		{
			DIO_voidSetPinValue(DPORTA,PIN0,OUTPUT);
		}
	}
}
