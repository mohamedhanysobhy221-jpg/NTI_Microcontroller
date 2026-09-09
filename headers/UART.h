#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#define UDR    (*((volatile u8*)0x2C))
#define UCSRA  (*((volatile u8*)0x2B))
#define UCSRB  (*((volatile u8*)0x2A))
#define UCSRC  (*((volatile u8*)0x40))
#define UBRRL  (*((volatile u8*)0x29))
#define UBRRH  (*((volatile u8*)0x40))

void UART_Init(void);
void UART_SendChar(u8 data);
u8 UART_GetChar(void);

#endif