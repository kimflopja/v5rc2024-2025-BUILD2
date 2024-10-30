#include "main.h"

//lift state 0 - set in start up
// lift state 1 - release intake
// lift state 2 - raise to height of short stake
// lift state 3 - raise to height of tall stake
// if up button pressed -> up a level
// if down button pressed -> down a level

void setLift(int liftState){
  switch (liftState)
  {
    case 0:
      lift.move_absolute(0, 50); // Placeholder values
    case 1:
      lift.move_absolute(150, 50); // Placeholder values
    case 2:
      lift.move_absolute(150, 50); // Placeholder values
    case 3:
      lift.move_absolute(150, 50); // Placeholder values
  }
}

void lift_func(){
  int liftState = 0;
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && liftState < 3) {
    liftState++;
  }
  if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && liftState > 0) {
    liftState--;
  }
  setLift(liftState);
} 