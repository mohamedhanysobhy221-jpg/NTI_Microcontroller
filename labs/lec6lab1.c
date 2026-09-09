#include "std_types.h"
#define F_CPU 1000000UL
#include <avr/io.h>
#include "BITMATH.h"
#include "DIO.h"
#include "TIMER0.h"

int main(void)
{
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	
	TIMER0_voidInit();

	u16 overflow_counter = 0;

	while (1)
	{
		if (GET_BIT(TIFR, 0) == 1)
		{
			
			SET_BIT(TIFR, 0);

			overflow_counter++;

			if (overflow_counter >= 488)
			{
				overflow_counter = 0;
				
				TOG_BIT(PORTC, PIN0);
			}
		}
	}
}

