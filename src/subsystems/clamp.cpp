#include "main.h"


void clamp_piston(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      clamp_piston1.extend();
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      clamp_piston1.retract();
    }
}
