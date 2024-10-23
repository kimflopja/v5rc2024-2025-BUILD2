#include "main.h"

//lift state 0 - up button
//lift state 1 - down button
void lift_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      lift.move_absolute(150, 50);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      lift.move_absolute(0, 50);
    }
}