#include "BITMATH.h"
#include "TIMER1.h"
#include "std_types.h"



void PWM1_voidInit(void)
{
	CLR_BIT(TCCR1A_REG, 0); 
	SET_BIT(TCCR1A_REG, 1); 
	SET_BIT(TCCR1B_REG, 3);
	SET_BIT(TCCR1B_REG, 4); 

	
	CLR_BIT(TCCR1A_REG, 6); 
	SET_BIT(TCCR1A_REG, 7); 

	CLR_BIT(TCCR1B_REG, 0); 
	SET_BIT(TCCR1B_REG, 1);
	CLR_BIT(TCCR1B_REG, 2);

	ICR1_REG = 2500;
}
void Servo_voidSetAngle(u8 Angle)
{
	
	OCR1A_REG = 125 + (((u32)Angle * 125UL) / 180UL);
}