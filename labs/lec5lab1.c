#include "std_types.h"
#define F_CPU 1000000UL

#include "DIO.h"
#include "ADC.h"

int main(void) {
	
	DIO_voidSetPortDirection(DPORTC, OUTPUT);
	DIO_voidSetPinDirection(DPORTA, PIN0, INPUT);
	
	ADC_Init();
	
	u16 adc_value;
	f32 voltage;
	
	while (1) {
		adc_value = ADC_Read(0);
		
		
		voltage = (adc_value * 5.0) / 1024.0;
		
		
		if (voltage >= 0.0 && voltage < 1.5) {
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
		else if (voltage >= 1.5 && voltage < 3.0) {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
		else if (voltage >= 3.0) {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
		}
	}
}
