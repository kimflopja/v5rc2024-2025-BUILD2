#include "main.h"

//lift state 0 - set in start up
// lift state 1 - release intake
// lift state 2 - raise to height of short stake
// lift state 3 - raise to height of tall stake
// if up button pressed -> up a level
// if down button pressed -> down a level

int liftState = 0;
bool upPressed = false;
bool downPressed = false;

void setLift(int liftState){
  switch (liftState)
  {
    case 0: // Set in startup
      lift.move_absolute(0, 50); 
      break;
    case 1: // Release intake
      lift.move_absolute(150, 50); 
      break;
    case 2: // Height of short stake
      lift.move_absolute(250, 50); 
      break;
    case 3: // Height of tallest stake
      lift.move_absolute(350, 50); 
      break;
  }
}

void lift_func(){                                                    
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        upPressed = true;
  }
  else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) upPressed = false;

  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && liftState>-1){
        downPressed = true;
  }
  else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) downPressed = false;

  if(upPressed && liftState<3) liftState++;
  if(downPressed && liftState>-1) liftState--;

  pros::lcd::print(0, "liftState: %d", liftState);
  setLift(liftState);
} 