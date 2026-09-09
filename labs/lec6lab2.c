#include "std_types.h"
#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "BITMATH.h"
#include "DIO.h"
#include "ADC.h"
#include "TIMER0.h"
#include <avr/io.h>
#include "ISR.h"

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN2, OUTPUT);

	
	DIO_voidSetPinDirection(DPORTA, PIN0, INPUT);

	
	ADC_Init();
	TIMER0_voidInit();
	initExternalInterupts();
	
	
	

	u16 adc_val = 0;

	while (1)
	{
		
		adc_val = ADC_Read(0);
		
		
		u8 ocr_val = (u8)(adc_val);
		if (ocr_val == 0) {
			ocr_val = 1;
		}

		TIMER0_voidSetCompare(ocr_val);
	}
}


ISR(TIMER0_COMP_vect)
{
	TOG_BIT(PORTC, PIN0);
	TOG_BIT(PORTC, PIN1);
	TOG_BIT(PORTC, PIN2);
	
}

