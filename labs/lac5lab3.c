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
	f32 temp;
	while (1) {
		adc_value = ADC_Read(0);
		
		
		voltage = (adc_value * 5000.0) / 1024.0;
		
		temp = voltage /10.0;
		if (temp<20) {
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
		else if (temp >= 20 && temp < 40) {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
		else if (temp >= 40) {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
		}
	}
}

