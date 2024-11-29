#include "main.h"

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

double helpful_range = 1000;

double kP = 1.0;
double kI = 1.0;
double kD = 1.0;

/*
*
* ///////////////// Movement Functions :3 ///////////////// 
* 
*/

/*
* Set the motors to a value
*/
void setDrive(int leftMove, int rightMove){
    left_motor1.move(leftMove);
    left_motor2.move(leftMove);
    left_motor3.move(leftMove);

    right_motor1.move(rightMove);
    right_motor2.move(rightMove);
    right_motor3.move(rightMove);
}

void setDriveVoltage(int leftMoveVoltage, int rightMoveVoltage){
    left_motor1.move_voltage(leftMoveVoltage);
    left_motor2.move_voltage(leftMoveVoltage);
    left_motor3.move_voltage(leftMoveVoltage);

    right_motor1.move_voltage(rightMoveVoltage);
    right_motor2.move_voltage(rightMoveVoltage);
    right_motor3.move_voltage(rightMoveVoltage);
}


/*
* Set the motors to a value for ARCADE
*/
void setArcadeDrive(int rotate, int drive){
    //Determine quadrants
    int maximum = std::max(abs(rotate), abs(drive));
    int total = rotate + drive;
    int difference = drive-rotate;

    if(drive >= 0){
        if(rotate >= 0){ // I Quadrant
            left_motor1.move(maximum);
            left_motor2.move(maximum);
            left_motor3.move(maximum);                 
            right_motor1.move(difference);
            right_motor2.move(difference);
            right_motor3.move(difference);
        }
        else{ // II Quadrant
            left_motor1.move(total);
            left_motor2.move(total);
            left_motor3.move(total); 
            right_motor1.move(maximum);
            right_motor2.move(maximum);
            right_motor3.move(maximum);
        }
    }
    else{
        if(rotate >= 0){ //IV Quadrant
            left_motor1.move(total);
            left_motor2.move(total);
            left_motor3.move(total);
            right_motor1.move(-maximum);
            right_motor2.move(-maximum);
            right_motor3.move(-maximum);
        }
        else{ //III Quadrant
            left_motor1.move(-maximum);
            left_motor2.move(-maximum);
            left_motor3.move(-maximum);
            right_motor1.move(difference);
            right_motor2.move(difference);
            right_motor3.move(difference);
        }
    }
}




/*
* Tank drive
*/
void opcontrol_tankdrive(){
    int left = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    //Extra precision
    setDrive((left*abs(left))/100, (right*abs(right))/100);
}


/*
* Arcade drive
*/
void opcontrol_arcadedrive(){
    // *** LEFT joystick ***
    int x = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int y = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    //Extra precision
    setArcadeDrive((x*abs(x))/100, (y*abs(y))/100);
}



/*
*
* ///////////////// Autonomous Movement Functions ///////////////// 
* 
*/



/*
*
* ///////////////// Telemetry Functions :3 ///////////////// 
* 
*/



/*
* Sets the "absolute" zero point of the motors to the current position
*/
void resetDriveEncoders(){
    left_motor1.tare_position();
    left_motor2.tare_position();
    left_motor3.tare_position();

    right_motor1.tare_position();
    right_motor2.tare_position();
    right_motor3.tare_position();
}



/*
* Get the avg drive encoder value
*/
double avgDriveEncoderValue(){
    return((left_motor1.get_position() + left_motor2.get_position() + left_motor3.get_position() +
    right_motor1.get_position() + right_motor2.get_position() + right_motor3.get_position())/6);
}



/*
* Get left
*/
double getLeftPosition(){
    return((left_motor1.get_position() + left_motor2.get_position() + left_motor3.get_position())/3);
}



/*
* Get right
*/
double getRightPosition(){
    return((right_motor1.get_position() + right_motor2.get_position() + right_motor3.get_position())/3);
}



/*
* Reset PID values
*/
void resetPID(){
    // chassis.reset_PID();
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
}



/*
*
* ///////////////// Auton Drive Functions :3 ///////////////// 
* 
*/



/*
* Drive
*/
void auton_drive(int goal, int speed){
    // Get direction
    int direction = abs(goal)/goal;
    // Reset
    resetDriveEncoders();
    // Drive until goal is reached
    while(fabs(avgDriveEncoderValue()) < abs(goal)){
        setDrive(speed*direction - inertial.get_rotation(), speed*direction + inertial.get_rotation()); // Self correcting driving ?
        pros::delay(10);
    }
    // Let it settle
    pros::delay(50); 
    // Short brake
    setDrive(-10*direction, -10*direction);
    // Wait
    pros::delay(50); 
    // Stop
    setDrive(0,0);
}



/*
* Turn
*/
void auton_turn(int degrees, int speed){
    // Get direction
    int direction = abs(degrees) / degrees;
    // Reset inertial
    inertial.set_rotation(0);
    // Turn until degrees is reached
    while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(-speed*direction, speed*direction);
        pros::delay(10);
    }
    
    // Wait to let the robot settle
    pros::delay(100);
    
    // Self correct here
    if(fabs(inertial.get_rotation()) > abs(degrees)){
        while(fabs(inertial.get_rotation()) > abs(degrees)){ 
        setDrive(0.50 * speed * direction, 0.50 * -speed * direction); // Speed is lessened to slow it
        pros::delay(10);
        }
    }
    else if(fabs(inertial.get_rotation()) < abs(degrees)){
        while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(0.50 * -speed * direction, 0.50 * speed*direction);
        pros::delay(10);
        }
    }
    
    
    // Stop
    setDrive(0,0);
}


void auton_swing(int degrees, int units, int speed){
    // Get direction
    int direction = abs(degrees) / degrees;
    // Reset inertial
    inertial.set_rotation(0);
    // Turn until degrees is reached
    while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(-speed*direction, speed*direction);
        pros::delay(10);
    }
    while(fabs(avgDriveEncoderValue()) < abs(units)){
        setDrive(speed*direction - inertial.get_rotation(), speed*direction + inertial.get_rotation()); // Self correcting driving ?
        pros::delay(10);
    }
    // Wait to let the robot settle
    pros::delay(100);
    // Self correct here
    if(fabs(inertial.get_rotation()) > abs(degrees)){
        while(fabs(inertial.get_rotation()) > abs(degrees)){ 
        setDrive(0.50 * speed * direction, 0.50 * -speed * direction); // Speed is lessened to slow it
        pros::delay(10);
        }
    }
    else if(fabs(inertial.get_rotation()) < abs(degrees)){
        while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(0.50 * -speed * direction, 0.50 * speed*direction);
        pros::delay(10);
        }
    }
    
    
    // Stop
    setDrive(0,0);
}



/*
*
* ///////////////// PID Drive Functions ///////////////// 
* 
*/



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
    double lateralMotion = (error * kP + integral * kI + derivative * kD)/12.0; 

    // Turn PID output
    double rotationalMotion = (turnError * kP + turnIntegral * kI + turnDerivative * kD)/12.0;

    // Drive
    setDriveVoltage(lateralMotion + rotationalMotion, lateralMotion - rotationalMotion); 
    
    // Delay
    pros::delay(util::DELAY_TIME);
}