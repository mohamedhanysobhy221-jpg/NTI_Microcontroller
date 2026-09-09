#include "std_types.h"
#define F_CPU 1000000UL

#include "BITMATH.h"
#include "DIO.h"
#include "UART.h"

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTA, PIN0, OUTPUT);

	
	DIO_voidSetPinDirection(DPORTD, PIN0, INPUT);
	DIO_voidSetPinDirection(DPORTD, PIN1, OUTPUT);

	UART_Init();

	u8 received_data;

	while (1)
	{
		
		received_data = UART_GetChar();

		
		if (received_data == '5')
		{
			TOG_BIT(PORTA_REG, PIN0);
		}
	}
}
