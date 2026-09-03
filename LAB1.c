

#include <avr/io.h>

int DIO_u8GetPinValue(int PortId, int PinId)
{
	int Value = 0;
	switch(PortId) {
		case 0 :
		 Value = (PINA >> PinId) & 1;break;
		case 1 :
		Value = (PINB >> PinId) & 1;break;
		case 2 :
		Value = (PINC >> PinId) & 1;break;
		case 3 :
		Value = (PIND >> PinId) & 1;break;
	}
		
	return Value;
}
int main(void)
{
    DDRA = 0b00000010;
	PORTA = 0b00000001;
    while (1) 
    {
		if(DIO_u8GetPinValue(0,0)==0){
			PORTA = 0b00000010;
		}
		else{
			PORTA = 0b00000000;
		}
		
    }
}

