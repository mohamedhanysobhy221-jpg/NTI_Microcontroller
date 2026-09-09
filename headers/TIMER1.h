#include "std_types.h"

#define TCCR1A_REG   (*((volatile u8*)0x4F))
#define TCCR1B_REG   (*((volatile u8*)0x4E))
#define ICR1_REG     (*((volatile u16*)0x46))
#define OCR1A_REG    (*((volatile u16*)0x4A))
void PWM1_voidInit(void);
void Servo_voidSetAngle(u8 Angle);