#include "std_types.h"
#include "DIO.h"
#include <avr/io.h>

void DIO_voidSetPortDirection (u8 PortId,u8 Direction){
    if(Direction == OUTPUT){
        switch(PortId){
            case DPORTA: DDRA = 0b11111111;break;
            case DPORTB: DDRB = 0b11111111;break;
            case DPORTC: DDRC = 0b11111111;break;
            case DPORTD: DDRD = 0b11111111;break;
        }
    }
    if(Direction == INPUT){
        switch(PortId){
            case DPORTA: DDRA = 0b00000000;break;
            case DPORTB: DDRB = 0b00000000;break;
            case DPORTC: DDRC = 0b00000000;break;
            case DPORTD: DDRD = 0b00000000;break;
        }
    }
}

void DIO_voidSetPinDirection (u8 PortId,u8 PinId,u8 Direction){
    if(Direction == OUTPUT){
        switch(PortId){
            
            case DPORTA: set_bit(DDRA,PinId);break;
            case DPORTB: set_bit(DDRB,PinId);break;
            case DPORTC: set_bit(DDRC,PinId);break;
            case DPORTD: set_bit(DDRD,PinId);break;
        }
    }
    if(Direction == INPUT){
        switch(PortId){
            
            case DPORTA: clr_bit(DDRA,PinId);break;
            case DPORTB: clr_bit(DDRB,PinId);break;
            case DPORTC: clr_bit(DDRC,PinId);break;
            case DPORTD: clr_bit(DDRD,PinId);break;
        }
    }
    
}
void DIO_voidSetPinValue (u8 PortId,u8 PinId,u8 Value){
    if(Value == HIGH){
        switch(PortId){
            
            case DPORTA: set_bit(PORTA,PinId);break;
            case DPORTB: set_bit(PORTB,PinId);break;
            case DPORTC: set_bit(PORTC,PinId);break;
            case DPORTD: set_bit(PORTD,PinId);break;
        }
    }
    if(Value == LOW){
        switch(PortId){
            
            case DPORTA: clr_bit(PORTA,PinId);break;
            case DPORTB: clr_bit(PORTB,PinId);break;
            case DPORTC: clr_bit(PORTC,PinId);break;
            case DPORTD: clr_bit(PORTD,PinId);break;
        }
    }
    
}
void DIO_voidSetPortValue (u8 PortId,u8 Value){
    if(Value == HIGH){
        switch(PortId){
            
            case DPORTA: PORTA = 0b11111111;break;
            case DPORTB: PORTB = 0b11111111;break;
            case DPORTC: PORTC = 0b11111111;break;
            case DPORTD: PORTD = 0b11111111;break;
        }
    }
    if(Value == LOW){
        switch(PortId){
            
            case DPORTA: PORTA = 0b00000000;break;
            case DPORTB: PORTB = 0b00000000;break;
            case DPORTC: PORTC = 0b00000000;break;
            case DPORTD: PORTD = 0b00000000;break;
        }
    }
    
}
u8 DIO_u8GetPinValue(u8 PortId, u8 PinId)
{
    u8 Local_u8Value = 0;

    switch (PortId)
    {
        case DPORTA:
            Local_u8Value = (PINA >> PinId) & 1;
            break;


        case DPORTB:
            Local_u8Value = (PINB >> PinId) & 1;
            break;


        case DPORTC:
            Local_u8Value = (PINC >> PinId) & 1;
            break;


        case DPORTD:
            Local_u8Value = (PIND >> PinId) & 1;
            break;
    }

    return Local_u8Value;
}
