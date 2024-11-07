#include "main.h"

//lift state 0 - set in start up
// lift state 1 - release intake
// lift state 2 - raise to height of short stake
// lift state 3 - raise to height of tall stake
// if up button pressed -> up a level
// if down button pressed -> down a level

bool buttonUpRegistered = false;
bool buttonDownRegistered = false;
int liftState = 0;

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
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && !buttonUpRegistered) {
    if(liftState < 3) liftState ++;
    else liftState = 3;
    
    buttonUpRegistered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) buttonUpRegistered = false;

  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && !buttonDownRegistered) {
    if(liftState > 0) liftState --;
    else liftState = 0;

    buttonDownRegistered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) buttonUpRegistered = false;
  pros::lcd::print(0, "liftState: %d", liftState);

  setLift(liftState);
  pros::delay(50); // Delay
} 

