#include "std_types.h"
#include "DIO.h"



int main(void)
{
    DIO_voidSetPortDirection (DPORTA,INPUT);
	DIO_voidSetPortDirection (DPORTC,OUTPUT);
	DIO_voidSetPortValue (DPORTA,HIGH);
   
   while (1)
   {
	    if(DIO_u8GetPinValue(DPORTA, PIN0) == 0){
		   DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
		   } 
		else {
			if(DIO_u8GetPinValue(DPORTA, PIN7) == 0){
		    DIO_voidSetPinValue(DPORTC, PIN0, HIGH);}
			
			else{
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);}
	    }

	   if(DIO_u8GetPinValue(DPORTA, PIN1) == 0){
		   DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
		   }
	  else {
		   
		   if(DIO_u8GetPinValue(DPORTA, PIN7) == 0){
		   DIO_voidSetPinValue(DPORTC, PIN1, HIGH);}
		   
		   else{
		   DIO_voidSetPinValue(DPORTC, PIN1, LOW);}
	   }

	   if(DIO_u8GetPinValue(DPORTA, PIN2) == 0){
		   DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
		   } 
	   else {
		   
		   if(DIO_u8GetPinValue(DPORTA, PIN7) == 0){
		   DIO_voidSetPinValue(DPORTC, PIN2, HIGH);}
		   
		   else{
		   DIO_voidSetPinValue(DPORTC, PIN2, LOW);}
	   }

	   
   }
}

