#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#define KEYPAD_PORT DPORTA
//first 4 pins OUTPUT , last 4 pins INPUT



void KEYPAD_init(void);
u8   KEYPAD_value(void);

#endif
