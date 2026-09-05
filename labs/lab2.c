#include "keypad.h"
#include "DIO.h"
#include <avr/io.h>


int main(void)
{
    KEYPAD_init();
	DIO_voidSetPortDirection(DPORTD,OUTPUT);
    while (1) 
    {	
		 
		u8 x = KEYPAD_value();
		if(x>=0 && x<=9){
			u8 arr[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
			PORTD = arr[x];}
				
		}
}

