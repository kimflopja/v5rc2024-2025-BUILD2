#include "main.h"

/**
* Where all the AUTONOMOUS RUNS are.
* DONT touch drivePID or these variables below.
*/

bool enablePID = true;
bool resetDrive = true;

double output = 0.0; // PID Output
double error = 0.0; // Error, Or rather PROPORTIONAL :3
double prev_error = 0.0; // Previous Error
double integral = 0.0; // Integral term
double derivative = 0.0; // Derivative Term

// Turn
double turnOutput = 0.0;
double turnDifference = 0.0;
double turnError = 0.0; // Error, Or rather PROPORTIONAL :3
double turnPrevError = 0.0; // Previous Error
double turnIntegral = 0.0; // Integral term
double turnDerivative = 0.0; // Derivative Term

double lateralMotion = 0.0;
double rotationalMotion = 0.0;

double targetPosition = 0.0;
double targetDegrees = 0.0;

// Constants
const double helpful_range = 500;

const double kP = 2.0;
const double kI = 0.0;
const double kD = 0.0;

const double MAX_VOLTAGE = 12000.0;

/*
* PID drive algorithm
*/
void drivePID(){

    while(enablePID){

        if(resetDrive){
            resetPID();
            resetDriveEncoders();
            inertial.tare();
            resetDrive = false;
        }
        
        // Sensor value
        int averagePosition = avgDriveEncoderValue();

        // Error
        error = targetPosition - averagePosition;


        
        // Integral
        integral += error;
        if (error > helpful_range){
                integral = 0;
            } else if (error = 0){
                integral = 0;
            }
        
        // Derivative
        derivative = error - prev_error;

        // TURN DIFFERENCE
        //turnDifference = getLeftPosition() - getRightPosition();
        turnDifference = fabs(inertial.get_rotation());
        // Turn error
        turnError = targetDegrees - turnDifference;

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
        prev_error = error; // Update prev_error

        // PID output
        // Using voltage because velocity has its own internal calculations
        double lateralMotion = (error * kP + integral * kI + derivative * kD); 

        // Turn PID output
        double rotationalMotion = (turnError * kP + turnIntegral * kI + turnDerivative * kD);

        // Drive
        setDriveVoltage(lateralMotion + rotationalMotion, lateralMotion - rotationalMotion); 
        
        // Delay
        pros::delay(20);

    }
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
*/


void driveTest(){
    pros::Task mizumafu(drivePID);

    targetPosition = 200;
    mizumafu.delay(1000);
    targetDegrees = 90;
    

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

// Auton Skills 
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