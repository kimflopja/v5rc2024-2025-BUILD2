#include "main.h"

// Out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

bool buttonAPressed = false;
bool toggleEnabled = false;

void drive_test(int rotate, int drive){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && !buttonAPressed) {
      buttonAPressed = true;
      toggleEnabled = !toggleEnabled;
    } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) buttonAPressed = false;

    if(toggleEnabled) setArcadeDrive(30,30);
}

/*
At least 3 rings scored of the alliance color on a minimum of two stakes.
A minimum of two stakes on the alliance’s side of the autonomous line with at least one ring.
At least one robot contacting the middle.
Has not broken any rules.
*/
void closeSide(){
    /*
    close side
    */
}

void farSide(){
    /*
    1. out
    2. clamp
    3. release intake
    4. spin
    5. turn
    6. drive fwd to get red ring
    7. drop ?
    8. touch side of middle
    */
}