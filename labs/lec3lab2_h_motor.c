#include "DIO.h"
#include <util/delay.h>

int main(void)
{
     DIO_voidSetPortDirection(DPORTC,OUTPUT);
    while (1) 
    {
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN3,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		DIO_voidSetPinValue(DPORTC,PIN2,LOW);
		_delay_ms(2000);
		
		DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		DIO_voidSetPinValue(DPORTC,PIN3,LOW);
		
		_delay_ms(2000);
    }
}

