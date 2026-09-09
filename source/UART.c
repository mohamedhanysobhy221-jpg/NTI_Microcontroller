#include "UART.h"
#include "std_types.h"
#include "BITMATH.h"
void UART_Init(void)
{
	
	UBRRL = 6;
	UBRRH = 0;

	
	SET_BIT(UCSRB, 4); 
	SET_BIT(UCSRB, 3); 

	
	//UCSRC = (1 << 7) | (1 << 2) | (1 << 1);
	SET_BIT(UCSRC,7);
	CLR_BIT(UCSRC,6);
	CLR_BIT(UCSRC,4);
	CLR_BIT(UCSRC,5);
	CLR_BIT(UCSRC,3);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRB,2);
}

void UART_SendChar(u8 data)
{
	while (GET_BIT(UCSRA, 5) == 0);
	
	
	UDR = data;
}

u8 UART_GetChar(void)
{

	while (GET_BIT(UCSRA, 7) == 0);
	
	return UDR;
}