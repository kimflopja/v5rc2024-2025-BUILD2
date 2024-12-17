#include "main.h"

/**
* The CLAMP.
*/



// Set clamp
void setClamp(Clamp clampState){
  switch(clampState){
    case unclamp:
      clamp_piston.retract(); // Unclamp
      break;
    case clamp:
      clamp_piston.extend() ; // Clamp
      break;
  }
}

// Uses ARROWS
void clamp_pistonArrows(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) { //Unclamp
      setClamp(unclamp);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { //Clamp
      setClamp(clamp);
    }
}

// Uses L1/L2
void clamp_pistonL1(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { //Unclamp
      setClamp(unclamp);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //Clamp
      setClamp(clamp);
    }
}