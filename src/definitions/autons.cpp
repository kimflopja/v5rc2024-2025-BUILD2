#include "main.h"

/**
* Where all the AUTONOMOUS RUNS are.
* DONT touch drivePID or these variables below.
*/

int output = 0; // PID Output
int error = 0; // Error, Or rather PROPORTIONAL :3
int prev_error = 0; // Previous Error
int integral = 0; // Integral term
int derivative = 0; // Derivative Term

// Turn
int turnOutput = 0;
int turnDifference = 0;
int turnError = 0; // Error, Or rather PROPORTIONAL :3
int turnPrevError = 0; // Previous Error
int turnIntegral = 0; // Integral term
int turnDerivative = 0; // Derivative Term

int helpful_range = 1000;

int kP = 1;
int kI = 1;
int kD = 1;
/*
* PID drive algorithm
*/
void drivePID(int units, int degrees){

    // Sensor value
    int averagePosition = avgDriveEncoderValue();

    // Error
    error = averagePosition - units;

    // Integral
    integral += error;
    if (error > helpful_range){
            integral = 0;
        } else if (error = 0){
            integral = 0;
        }


    // Derivative
    derivative = error - prev_error;

    prev_error = error; // Update prev_error

    // TURN DIFFERENCE
    //turnDifference = getLeftPosition() - getRightPosition();
    turnDifference = fabs(inertial.get_rotation());
    // Turn error
    turnError = turnDifference - degrees;

    // Turn integral
    turnIntegral += turnError;

    // Turn Derivative
    turnDerivative = turnError - turnPrevError;
    if (turnError > helpful_range){
            integral = 0;
        } else if (error = 0){
            integral = 0;
        }

    // Update prev error
    turnPrevError = error;

    // PID output
    // Using voltage because velocity has its own internal calculations
    int lateralMotion = (error * kP + integral * kI + derivative * kD); 

    // Turn PID output
    int rotationalMotion = (turnError * kP + turnIntegral * kI + turnDerivative * kD);

    // Drive
    setDriveVoltage(lateralMotion + rotationalMotion, lateralMotion - rotationalMotion); 
    
    // Delay
    pros::delay(util::DELAY_TIME);
}

/**
* Constant values.
* Can change if needed.
* If the turn is too slow the robot won't turn.
*/
const int DRIVE_SPEED = 80;
const int TURN_SPEED = 60;
const int AUTON_DELAY_TIME = 200;

/**
* Below starts AUTON RUNS.
* You can adjust these, but make sure the same changes are made to the MIRRORED version.
* Make sure to add a DELAY between each movement.
*/

// Distance = diameter * gearRatio * rotations
// Diameter =
// Gear ratio = 5:3
// Rotations
void driveTest(){
    resetDriveEncoders();
    inertial.tare();
    // drivePID(units, degrees)
    // Swing is drive + turn at the same time
    drivePID(300, 0);
}

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
    setClamp(clamp);
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
    auton_drive(240, DRIVE_SPEED); // Changed drive fwd
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(170, TURN_SPEED-15);
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
    setClamp(clamp);
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
    auton_drive(240, DRIVE_SPEED); // Changed drive fwd
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(-170, TURN_SPEED-15);
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
    setClamp(clamp);
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
    auton_drive(240, DRIVE_SPEED); // Changed drive fwd
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(-150, TURN_SPEED);
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
    setClamp(clamp);
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
    auton_drive(240, DRIVE_SPEED); // Changed drive fwd
    pros::delay(AUTON_DELAY_TIME);
    // 7. Turn all the way
    auton_turn(150, TURN_SPEED);
    pros::delay(AUTON_DELAY_TIME);
    /*
    // 8. Drop the stake
    clamp_piston1.retract();
    pros::delay(AUTON_DELAY_TIME);
     */
    // 9. Drive FWD to side of middle, ride up
    auton_drive(700, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
}


// Auton Skills #2
// THE ONE WE ARE USING
void autonSkills2(){
    setUpStart();
    // Drive bkwd
    auton_drive(-10, DRIVE_SPEED);
    pros::delay(AUTON_DELAY_TIME);
   // 1. Rotate
   auton_turn(90, TURN_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 2. Drive bkwd
   auton_drive(-180, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 3. Grab stake
   setClamp(clamp);
   pros::delay(AUTON_DELAY_TIME);
   // Drive fwd slightly
   auton_drive(30, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 4. Turn intake on
   setIntake(100);
   pros::delay(300);
   // 5. Turn towards ring
   auton_turn(147, TURN_SPEED); // Changed angle to make it larger
   pros::delay(AUTON_DELAY_TIME);
   // 6. Drive fwd
   auton_drive(450, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 7. Turn again
   auton_turn(-21, TURN_SPEED); //used to be -15, not good angle
   pros::delay(AUTON_DELAY_TIME);
   // 8. Drive fwd
   auton_drive(300, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // Drive bkwd slightly
   auton_drive(-30, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 9. Turn all the way (total turn is 150)
   auton_turn(80, TURN_SPEED);
   pros::delay(600);
   auton_drive(80, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   auton_turn(70, TURN_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 9. Drive fwd
   auton_drive(600, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 10. Turn 
   auton_turn(140, TURN_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 11. Drive bkwd 
   auton_drive(-130, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 12. Drop stake
   setClamp(unclamp);
   pros::delay(AUTON_DELAY_TIME);
   // hang
   setLift(3);
   pros::delay(AUTON_DELAY_TIME);
   setIntake(0);
   pros::delay(AUTON_DELAY_TIME);
   auton_drive(1500, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   setLift(0);
   pros::delay(5000);
   setLatch(retracted);
   /* 
   // 13. Drive fwd
   auton_drive(100, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 14. Turn
   auton_turn(130, TURN_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 15. Drive bkwd
   auton_drive(-1200, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 16. Drive bkwd again
   auton_drive(-200, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 17. Clamp
   clamp_piston1.extend();
   pros::delay(AUTON_DELAY_TIME);
   // 21. Turn to be fwd
   auton_turn(180, TURN_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 22. Drive fwd to get ring
   auton_drive(300, DRIVE_SPEED);
   pros::delay(AUTON_DELAY_TIME);
   // 23. Turn
   pros::delay(AUTON_DELAY_TIME);
   // 24. Drive fwd to get ring
   pros::delay(AUTON_DELAY_TIME);
   // 25. Drive bkwd to get ring
   pros::delay(AUTON_DELAY_TIME);
   // 26. Turn
   pros::delay(AUTON_DELAY_TIME);
   // 27. Drive fwd to get ring
   pros::delay(AUTON_DELAY_TIME);
   // 28. Turn to face bkwd
   pros::delay(AUTON_DELAY_TIME);
   // 29. Drive bkwd
   pros::delay(AUTON_DELAY_TIME);
   // 30. Drop stake
   pros::delay(AUTON_DELAY_TIME);
   // 31. Drive fwd
   pros::delay(AUTON_DELAY_TIME);
   // 32. Turn towards middle
   pros::delay(AUTON_DELAY_TIME);
   // 33. Hang
   pros::delay(AUTON_DELAY_TIME);
   // Latch
   pros::delay(AUTON_DELAY_TIME);
   // Done!
   */
}