#include "DIO.h"
#include <avr/interrupt.h>
#include "ISR.h"
#include <avr/io.h>


int main(void)
{	
	initExternalInterupts();
    DIO_voidSetPortDirection(DPORTA,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
	DIO_voidSetPinValue(DPORTD,PIN2,OUTPUT);
	DIO_voidSetPortBinaryValue(DPORTA,0b10101010);
	
    while (1) 
    {
		
    }
}
ISR(INT0_vect)
{	
if(DIO_u8GetPinValue(DPORTD,PIN2) == 0){
	DIO_voidSetPortBinaryValue(DPORTA,0b01010101);}
else
DIO_voidSetPortBinaryValue(DPORTA,0b10101010);
	
}



