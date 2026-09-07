#include <avr/io.h>
#include <avr/interrupt.h>
#include "ISR.h"
#include "DIO.h"

void initExternalInterupts(void)
{
    
   set_bit(MCUCR, ISC00);
    clr_bit(MCUCR, ISC01);
    set_bit(MCUCR, ISC10);
    clr_bit(MCUCR, ISC11);
 
    set_bit(GICR, INT0);
    set_bit(GICR, INT1);
    

    set_bit(SREG, 7);
}
