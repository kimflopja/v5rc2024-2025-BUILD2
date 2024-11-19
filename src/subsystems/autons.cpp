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

// Close Side Auton
void closeSide(){
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
    auton_turn(65, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 6. Drive fwd to get red ring
    auton_drive(275, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(170, TURN_SPEED-15);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
}

// Close Side Auton (Mirrored)
void closeSideMirrored(){
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
    auton_turn(-65, TURN_SPEED); // Mirrored
    pros::delay(AUTON_DELAY_TIME);
    // 6. Drive fwd to get red ring
    auton_drive(275, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(-170, TURN_SPEED-15);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
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
    auton_turn(-150, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
}

// Far Side Auton (Mirrored)
void farSideMirrored(){
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
    auton_turn(60, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 6. Drive fwd to get red ring
    auton_drive(275, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(150, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
}



// Auton Skills
void autonSkills(){
    // 1.
    // 2.
}