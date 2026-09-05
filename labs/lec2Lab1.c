#include "DIO.h"
#include "LCD.h"



int main(void)
{	
    LCD_init();
	LCD_SendString("Mohamed Hany");
    while (1) 
    {
		//LCD_SendData('C');
		
    }
}

