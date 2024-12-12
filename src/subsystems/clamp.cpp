#include "main.h"

/**
* The CLAMP.
*/

// Uses ARROWS
void clamp_piston(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) { //Unclamp
      clamp_piston1.retract();
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { //Clamp
      clamp_piston1.extend();
    }
}

// Uses L1/L2
void clamp_pistonL1(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { //Unclamp
      clamp_piston1.retract();
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //Clamp
      clamp_piston1.extend();
    }
}