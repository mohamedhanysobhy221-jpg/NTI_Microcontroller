#include "std_types.h"
#define F_CPU 1000000UL
#include <util/delay.h>

#include "DIO.h"
#include "UART.h"

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTD, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DPORTD, PIN0, INPUT);

	UART_Init();

	while (1)
	{
		UART_SendChar('5');
		_delay_ms(1000);
	}
}

