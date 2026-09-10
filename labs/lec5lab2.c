

#include <avr/io.h>
#include "LCD.h"
#include "ADC.h"
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
    LCD_init();
	ADC_Init();
	u32 voltage;
    while (1) 
    {
		u16 reading = ADC_Read(0);
		voltage = ((u32)reading*5000UL)/1024UL;
		LCD_SendCommand(0x80);
		LCD_SendNumber(voltage);
		
    }
}

