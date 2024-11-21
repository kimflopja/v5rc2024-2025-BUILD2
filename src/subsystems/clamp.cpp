#include "main.h"


void clamp_piston(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      clamp_piston1.retract();
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      clamp_piston1.extend();
    }
}
