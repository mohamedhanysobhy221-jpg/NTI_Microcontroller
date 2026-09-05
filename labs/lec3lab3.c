
#include "STEPPER_MOTOR.h"
#include <util/delay.h>


int main(void) {
	
	MOTOR_init();
	while (1) {
		
		halfstep(0);
		
	}
}

