#include "main.h"

// Out of 127
const int DRIVE_SPEED = 50;
const int TURN_SPEED = 60;
const int AUTON_DELAY_TIME = 500;

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

// Far Side Auton
void farSide(){
    // 1. Go out
    auton_drive(-600, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 2. Clamp
    clamp_piston1.extend();
    pros::delay(AUTON_DELAY_TIME);
    // 3. Release intake
    setLift(3);
    pros::delay(AUTON_DELAY_TIME);
    // 4. Spin
    setIntake(110);
    // 5. Turn
    auton_turn(-60, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 6. Drive fwd to get red ring
    auton_drive(275, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(-160, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
}

void autonSkills(){


}