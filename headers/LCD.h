#include "std_types.h"
#include "DIO.h"
#define LCD_ctrl PORTC
#define LCD_DATA PORTD
#define LCD_ctrlid DPORTC
#define LCD_DATAid DPORTD
//init

void LCD_init(void);

//char

void LCD_SendData(u8 Data);

//send command

void LCD_SendCommand(u8 command);

//Send String

void LCD_SendString (u8 *str);
