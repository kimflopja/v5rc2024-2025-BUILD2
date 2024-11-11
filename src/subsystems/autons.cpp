#include "main.h"

// Out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int AUTON_DELAY_TIME = 50;

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
    auton_drive(-DRIVE_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    2. clamp, then go back
    auton_drive(-DRIVE_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    3. release intake
    setLift(3);
    pros::delay(AUTON_DELAY_TIME);
    4. spin
    setIntake(100);
    pros::delay(AUTON_DELAY_TIME);
    5. turn
    auton_turn(TURN_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    6. drive fwd to get red ring
    auton_drive(DRIVE_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    7. drop 
    clamp_piston1.extend();
    pros::delay(AUTON_DELAY_TIME);
    8. turn
    auton_turn(TURN_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    9. drive fwd to side of middle
    auton_drive(DRIVE_SPEED, 20);
    pros::delay(AUTON_DELAY_TIME);
    */
}

void autonSkills(){


}