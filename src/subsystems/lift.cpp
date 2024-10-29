#include "main.h"

//lift state 0 - set in start up
// lift state 1 - release intake
// lift state 2 - raise to height of short stake
// lift state 3 - raise to height of tall stake

// if up button pressed -> up a level
// if down button pressed -> down a level
void lift_func(){

  // Keep in mind: FWD is DOWN! 
  // Placeholder 
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      lift.move_absolute(150, 50);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      lift.move_absolute(0, 50);
    }
} 