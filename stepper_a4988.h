#ifndef stepper_a4988
#define stepper_a4988
#include <avr/io.h>
#include <util/delay.h>

#define stepper_dir DDRD
#define stepper_port PORTD
#define dir_pin PIND3
#define step_pin PIND2
#define ms1 PIND4
#define ms2 PIND5
#define ms3 PIND6
#define FULLSTEP 1
#define HALFSTEP 2
#define QUARTERSTEP 3
#define EIGHTHSTEP 4
#define SIXTEENTHSTEP 5

void stepper_setup(int mode);
void stepper_set_angle(int data);

#endif