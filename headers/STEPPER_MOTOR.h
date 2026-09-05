#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "std_types.h"
#define MOTOR_PORT DPORTC
void MOTOR_init(void);
void fullstep(u8 direction);
void halfstep(u8 direction);

#endif