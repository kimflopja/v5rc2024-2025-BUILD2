#include "main.h"

// Out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;


/*
Both autons similar.
At least 3 rings scored of the alliance color on a minimum of two stakes.
A minimum of two stakes on the alliance’s side of the autonomous line with at least one ring.
At least one robot contacting the middle.
Has not broken any rules.
*/
void closeSide(){
    /*
    close side:
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

void farSide(){
    /*
    far side:
    1. out
    auton_drive(-100, 20);
    2. clamp, then go back
    auton_drive(-50, 20);
    clamp_piston1.retract();
    3. release intake
    setLift(3);
    4. spin
    setIntake(100);
    5. turn
    auton_turn(90, 20);
    6. drive fwd to get red ring
    auton_drive(100, 20);
    7. drop ?
    clamp_piston1.extend();
    8. touch side of middle
    auton_turn(90, 20);
    auton_drive(200, 20);
    */
}