
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "TIMER1.h"

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTD, PIN5, OUTPUT);


	PWM1_voidInit();

	while (1)
	{
		
		Servo_voidSetAngle(0);
		_delay_ms(1500);

		
		Servo_voidSetAngle(90);
		_delay_ms(1500);

		
		Servo_voidSetAngle(180);
		_delay_ms(1500);
	}
}

