#include "main.h"

//lift state 0 - set in start up
// lift state 1 - release intake
// lift state 2 - raise to height of short stake
// lift state 3 - raise to height of tall stake
// if up button pressed -> up a level
// if down button pressed -> down a level

/**
* preferably don't touch these
*/
bool buttonL2Registered = false;
bool buttonL1Registered = false;
int liftState = 0;

/**
* Set the lift state with this function.
* If the HANG is not high enough, change CASE 3's LIFT.MOVE_ABSOLUTE's FIRST value. The SECOND value is the SPEED of the lift.
*/

void setLift(int liftState){
  switch (liftState)
  {
    case 0: // Set in startup
      lift.move_absolute(0, 50); 
      break;
    case 1: // Release intake
      lift.move_absolute(150, 50); 
      break;
    case 2: // Hang level
      lift.move_absolute(300, 50); 
      break;
    case 3: // Top for hang
      lift.move_absolute(700, 50); 
      break;
  }
}

/**
* preferably don't touch these
*/
void lift_funcL1(){
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !buttonL2Registered) { // Up
    if(liftState < 3) liftState ++;
    else liftState = 3;
    buttonL2Registered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) buttonL2Registered = false;

  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !buttonL1Registered) { // Down
    if(liftState > 0) liftState --;
    else liftState = 0;
    buttonL1Registered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) buttonL1Registered = false;

  setLift(liftState);
  pros::delay(50); // Delay
} 


void lift_funcArrows(){
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && !buttonL2Registered) { // Up
    if(liftState < 3) liftState ++;
    else liftState = 3;
    buttonL2Registered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) buttonL2Registered = false;

  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && !buttonL1Registered) { // Down
    if(liftState > 0) liftState --;
    else liftState = 0;
    buttonL1Registered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) buttonL1Registered = false;

  setLift(liftState);
  pros::delay(50); // Delay
} 

