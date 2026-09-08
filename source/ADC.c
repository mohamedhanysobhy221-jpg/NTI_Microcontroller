#include "DIO.h"
#include "ADC.h"

void ADC_Init(void)
{
	
	set_bit(ADMUX_Reg, 6);
	clr_bit(ADMUX_Reg, 7);

	clr_bit(ADMUX_Reg, 5);


	set_bit(ADCSRA_Reg, 0);
	set_bit(ADCSRA_Reg, 1);
	clr_bit(ADCSRA_Reg, 2);

	
	set_bit(ADCSRA_Reg, 7);
}

u16 ADC_Read(u8 Copy_u8Channel)
{
	u16 Local_u16AdcResult = 0;

	
	Copy_u8Channel &= 0x07;

	
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= Copy_u8Channel;

	
	set_bit(ADCSRA_Reg, 6);

	while ((ADCSRA_Reg & (1 << 4)) == 0);

	set_bit(ADCSRA_Reg, 4);

	
	Local_u16AdcResult = ADCL_Reg;
	Local_u16AdcResult |= (ADCH_Reg << 8);

	return Local_u16AdcResult;
}