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
    // 1. Start rotated
    // 2. Drive back
    auton_drive(-100, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // Release intake
    lift.move_absolute(700, 50);
    pros::delay(AUTON_DELAY_TIME);
    // 3. Clamp
    clamp_piston1.extend();
    pros::delay(AUTON_DELAY_TIME);
    // 4. Rotate 180
    auton_turn(-150, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    setIntake(110); // Turn on intake
    pros::delay(AUTON_DELAY_TIME);
    // 5. Drive fwd to intake
    auton_drive(300, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 6. Rotate 90 degrees to the right
    auton_turn(90, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 7. Drive fwd to intake
    auton_drive(300, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 8. Rotate to face corner
    auton_turn(90, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 9. Drive fwd to intake the rings there
    auton_drive(250, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    auton_drive(100, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    auton_drive(-100, DRIVE_SPEED); // Go bkwd
    pros::delay(AUTON_DELAY_TIME);
    auton_turn(-90, TURN_SPEED); // Turn to get other rings
    pros::delay(AUTON_DELAY_TIME);
    auton_drive(150, DRIVE_SPEED); // Drive fwd to get it
    pros::delay(AUTON_DELAY_TIME);
    auton_drive(-150, DRIVE_SPEED); // Drive backward
    pros::delay(AUTON_DELAY_TIME);
    // 10. Turn
    auton_turn(230, TURN_SPEED); // Turn to be bkwd
    pros::delay(AUTON_DELAY_TIME);
    // Drive bkwd
    auton_drive(-200, DRIVE_SPEED); // Drive backward
    pros::delay(AUTON_DELAY_TIME);
    // 11. Unclamp
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
    // 12. Drive fwd
    auton_drive(350, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 13. Turn
    auton_turn(90, TURN_SPEED); // Turn to be bkwd
    pros::delay(AUTON_DELAY_TIME);
    // 14. Drive bkwd to clamp
    auton_drive(-800, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 15. Turn to intake
    auton_turn(90, TURN_SPEED); 
    pros::delay(AUTON_DELAY_TIME);
    // 16. Drive fwd
    auton_drive(200, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 17. Turn
    auton_turn(90, TURN_SPEED); 
    pros::delay(AUTON_DELAY_TIME);
    // 18. Drive fwd to intake
    auton_drive(300, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    // 19. Turn 
    // 20. Drive fwd to get ring
    // 21. Turn to get ring on right
    // 22. Drive fwd
    // 23. Turn to get other ring
    // 24. Drive fwd
    // 25. Turn to drop off clamp in corner
    // 26. Drop off clamp
    // 27. Turn towards middle ladder
    // 28. Drive fwd
    // 29. Bring arm down to hang
    // 30. Bring hook down (lock it)
}