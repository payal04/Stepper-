#include "stepper_a4988.h"

//stepper can be set up in various modes-
//full step mode,half step mode,quarter step mode,eighth step mode,sixteenth step mode
//stepper motor direction  pin can be set up in clockwise as well as in anticlockwise
void stepper_stepset();
void delay_micro(int x);
void full_step();
void half_step();
void quarter_step();
void eighth_step();
void sixteenth_step();
int step_factor;//global variable

void stepper_setup(int mode){
	stepper_dir |= (1 << dir_pin) | (1 << step_pin) | (1 << ms1) | (1 << ms2) | (1 << ms3);
	int num;
	num = mode;
	switch(num){
		case 1:
		full_step();
		step_factor=1;
		break;
		case 2:
		half_step();
		step_factor=2;
		break;
		case 3:
		quarter_step();
		step_factor=3;
		break;
		case 4:
		eighth_step();
		step_factor=4;
		break;
		case 5:
		sixteenth_step();
		step_factor=5;
		break;
	}
}
void stepper_set_angle(int data){
	int angle;
	int i,steps;
	angle = data;
	steps = (int)((angle / (1.8)) * step_factor);
	if(angle>0){
		stepper_port |= (1 << dir_pin);//for let clockwise +360
		for(i = 0;i < steps;i++){
			stepper_stepset();
		}
	}
	else{
		stepper_port &=~ (1 << dir_pin);//for let clockwise -360
		for(i = 0;i < steps;i++){
			stepper_stepset();
		}
	}
}
void stepper_stepset(){
	stepper_port |= (1<<step_pin);
	delay_micro(500);
	stepper_port &=~ (1<<step_pin);
	delay_micro(500);
}
void delay_micro(int x){
	while(x--){
		_delay_us(1);
	}
}
void full_step(){
	stepper_port &=~ ((1<<ms1)|(1<<ms2)|(1<<ms3));
}
void half_step(){
	stepper_port |= (1<<ms1)|(1<<ms2);
	stepper_port &=~ (1<<ms3);
}
void quarter_step(){
	stepper_port &=~ (1<<ms1)|(1<<ms3);
	stepper_port |= (1<<ms2);
}
void eighth_step(){
	stepper_port |= (1<<ms1)|(1<<ms2);
	stepper_port &=~ (1<<ms3);
}
void sixteenth_step(){
	stepper_port |= (1<<ms1)|(1<<ms2)|(1<<ms3);
}