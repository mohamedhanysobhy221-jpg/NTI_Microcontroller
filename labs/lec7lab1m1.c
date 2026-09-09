#include "std_types.h"
#define F_CPU 1000000UL
#include <util/delay.h>

#include "DIO.h"
#include "UART.h"

int main(void)
{
	// Configure TX pin (PD1) as OUTPUT and RX pin (PD0) as INPUT
	DIO_voidSetPinDirection(DPORTD, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DPORTD, PIN0, INPUT);

	UART_Init();

	while (1)
	{
		// Send '1' to toggle LED 1 on receiver
		UART_SendChar('5');
		_delay_ms(1000);
	}
}

