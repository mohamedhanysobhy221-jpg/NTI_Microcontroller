#include "avr/io.h"
#include "DIO.h"
#include "std_types.h"
#include <util/delay.h>

#define RS  0
#define RW  1
#define EN  2



void LCD_init(void) {
	_delay_ms(500);
	
	DIO_voidSetPortDirection(DPORTC, OUTPUT);
	DIO_voidSetPortDirection(DPORTD, OUTPUT);
	
	_delay_ms(50);
	
	LCD_SendCommand(0x38);
	_delay_us(50);
	
	LCD_SendCommand(0x0C);
	_delay_us(50);
	
	LCD_SendCommand(0x01);
	_delay_ms(2);
	
	LCD_SendCommand(0x06);
	_delay_us(50);
}

void LCD_SendCommand(u8 command) {
	clr_bit(PORTC, RS);
	clr_bit(PORTC, RW);
	
	PORTD = command;
	
	set_bit(PORTC, EN);
	_delay_us(1);
	clr_bit(PORTC, EN);
	
	_delay_us(100);
}

void LCD_SendData(u8 data) {
	set_bit(PORTC, RS);
	clr_bit(PORTC, RW);
	
	PORTD = data;
	
	set_bit(PORTC, EN);
	_delay_us(1);
	clr_bit(PORTC, EN);
	
	_delay_us(100);
}

void LCD_SendString(u8 *str) {
	while (*str != '\0') {
		LCD_SendData((u8)*str);
		str++;
	}
}