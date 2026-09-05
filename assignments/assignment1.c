#include "std_types.h"
#include "DIO.h"
#include "keypad.h"
#include "LCD.h"
#include <util/delay.h>

#define KEY_NONE 0xFF


void numberToString(s32 num, u8 *arr) {
	u8 temp[12];
	u8 i = 0;
	u8 j = 0;
	u8 isNeg = 0;
	u32 n;

	if (num < 0) {
		isNeg = 1;
		n = (u32)(-num);
	} else {
		n = (u32)num;
	}

	if (n == 0) {
		temp[i++] = '0';
	}
	while (n > 0) {
		temp[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (isNeg) {
		temp[i++] = '-';
	}

	while (i > 0) {
		arr[j++] = temp[--i];
	}
	arr[j] = '\0';
}


u8 readKey(void) {
	u8 key = KEYPAD_value();

	if (key == KEY_NONE) {
		return KEY_NONE;
	}

	_delay_ms(20);
	while (KEYPAD_value() != KEY_NONE);
	_delay_ms(20);

	return key;
}

int main(void) {
	s32 firstNumber = 0;
	s32 currentNumber = 0;
	u8 op = 0;          
	u8 arr[12];
	u8 key;

	LCD_init();
	KEYPAD_init();

	while(1) {
		key = readKey();

		if (key == KEY_NONE) {
			continue;
		}

		
		if (key == 'C') {
			firstNumber = 0;
			currentNumber = 0;
			op = 0;
			LCD_SendCommand(0x01);
			_delay_ms(2);
			continue;
		}

		
		if (key <= 9) {
			currentNumber = currentNumber * 10 + key;

			numberToString(currentNumber, arr);
			LCD_SendCommand(0x01);
			_delay_ms(2);
			LCD_SendString(arr);
			continue;
		}

	
		if (key == '+' || key == '-' || key == '*' || key == '/') {
			firstNumber = currentNumber;
			currentNumber = 0;
			op = key;
			continue;
		}

		
		if (key == '=') {
			s32 result = 0;

			if (op == '+') {
				result = firstNumber + currentNumber;
			} else if (op == '-') {
				result = firstNumber - currentNumber;
			} else if (op == '*') {
				result = firstNumber * currentNumber;
			} else if (op == '/') {
				if (currentNumber == 0) {
					LCD_SendCommand(0x01);
					_delay_ms(2);
					LCD_SendString((u8*)"Error");
					firstNumber = 0;
					currentNumber = 0;
					op = 0;
					continue;
				}
				result = firstNumber / currentNumber;
			}

			numberToString(result, arr);
			LCD_SendCommand(0x01);
			_delay_ms(2);
			LCD_SendString(arr);

			
			firstNumber = 0;
			currentNumber = 0;
			op = 0;
			continue;
		}
	}

	return 0;
}

