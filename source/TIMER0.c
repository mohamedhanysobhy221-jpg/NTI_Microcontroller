#include "BITMATH.h"
#include "TIMER0.h"
#define Normal_mode 0
#define CTC_mode 1
void TIMER0_voidInit(void)
{
if(Normal_mode){	
	
	CLR_BIT(TCCR0, 6); 
	CLR_BIT(TCCR0, 3); 

	
	CLR_BIT(TCCR0, 2); 
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 0);
	}
else if(CTC_mode){
	CLR_BIT(TCCR0, 6);
	SET_BIT(TCCR0, 3);
	
	SET_BIT(TIMSK, 1);
	CLR_BIT(TCCR0, 2);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 0); 
}
}

void TIMER0_voidSetTimerValue(u8 Value)
{
	TCNT0 = Value;
}
void TIMER0_voidSetCompare(u8 Val)
{
	OCR0 = Val;
}
