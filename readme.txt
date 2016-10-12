author-Payal Mittal
stepper motor-
this is the library of stepper motor in which we have done microstepping in bipolar phase
first to get clear idea about stepper motor,how to do connections,what is the current that we have to set,etc... go to link https://www.pololu.com/product/1182
now how to use library-
void stepper_setup()-this function is used for setting different microstepping modes whether u want to run on full step mode,half step mode,
quarter step mode ,etc...
void stepper_set_rel_angle()-this function is used for running the motor at desired angle
void stepper_set_abs_angle()-this function is used for getting desired angle
void stepper_stepset()-for setting steppin to either high  or low
void stepper_check()-for checking whether stepper is working well or not
while writing in main-
first initialize using function stepper_setup();
then set the angle using function  stepper_set_rel_angle();
...and if u want to check ur stepper motor whether it is working or not then use function stepper_check();