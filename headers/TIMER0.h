#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"

// Register Definitions
#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)

void TIMER0_voidInit(void);
void TIMER0_voidSetCompare(u8 Val);
void TIMER0_voidSetTimerValue(u8 Value);

#endif