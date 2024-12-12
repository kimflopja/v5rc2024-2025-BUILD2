#include "main.h"

/**
* The LATCH.
*/
void hook_piston_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      hook_piston1.extend(); // RETRACTS
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      hook_piston1.retract(); // EXTENDS
    }
}