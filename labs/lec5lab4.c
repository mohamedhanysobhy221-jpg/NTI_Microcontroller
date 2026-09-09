#include "std_types.h"
#define F_CPU 1000000UL

#include "DIO.h"
#include "ADC.h"

#define LDR_THRESHOLD   400

int main(void) {
	
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	
	DIO_voidSetPinDirection(DPORTA, PIN0, INPUT);
	
	ADC_Init();
	
	u16 adc_value ;
	f32 voltage;
	f32 ldr;
	while (1) {
		
		adc_value = ADC_Read(0);
		voltage = (adc_value*5000.0)/1024.0;
		 ldr = (1000.0*5000.0-1000.0*voltage)/voltage;
		
		if (adc_value < LDR_THRESHOLD) {
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
		}
		 
		else {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
		}
	}
}

