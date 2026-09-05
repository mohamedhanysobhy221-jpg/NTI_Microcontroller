#include "std_types.h"
#include "DIO.h"

void KEYPAD_init(void){
	
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN3,OUTPUT);
	
	DIO_voidSetPinDirection(DPORTC,PIN4,INPUT);
	DIO_voidSetPinDirection(DPORTC,PIN5,INPUT);
	DIO_voidSetPinDirection(DPORTC,PIN6,INPUT);
	DIO_voidSetPinDirection(DPORTC,PIN7,INPUT);

	DIO_voidSetPinValue(DPORTC,PIN4,HIGH);
	DIO_voidSetPinValue(DPORTC,PIN5,HIGH);
	DIO_voidSetPinValue(DPORTC,PIN6,HIGH);
	DIO_voidSetPinValue(DPORTC,PIN7,HIGH);
}
u8 arr[4][4] = {{7,8,9,'÷'},{4,5,6,'×'},{1,2,3,'-'},{'o',0,'=','+'}};
u8 KEYPAD_value(void){
	u8 Value = 0b11111111;
	
	for(int i = 0;i<4;i++){
		DIO_voidSetPinValue(DPORTC,i,LOW);
		for(int j = 0;j<4;j++){
			if(DIO_u8GetPinValue(DPORTC,j+4)==0){
				Value = arr[i][j];
			}
			
			
		}
		DIO_voidSetPinValue(DPORTC,i,HIGH);
	}
	return Value;
}