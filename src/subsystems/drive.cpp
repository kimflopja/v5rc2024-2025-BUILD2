#include "main.h"


/*
*
* ///////////////// Movement Functions :3 ///////////////// 
* 
*/

PID chassis;

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
    int y = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
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
    chassis.reset_PID();
}



/*
* Drive with PID output
*/
void auton_drive(int goal, int speed){
    // Get direction
    int direction = abs(goal)/goal;
    // Reset
    resetDriveEncoders();
    // Drive until goal is reached
    while(fabs(avgDriveEncoderValue()) < abs(goal)){
        setDrive(speed*direction, speed*direction); // Self correcting driving ?
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
    pros::lcd::print(2, "rotation: %f", inertial.get_rotation()); // Troubleshooting
    while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(-speed*direction, speed*direction);
        pros::delay(10);
        pros::lcd::print(0, "rotation: %f", inertial.get_rotation()); // Troubleshooting
    }
    
    // Wait to let the robot settle
    pros::delay(100);
    
    // Self correct here
    if(fabs(inertial.get_rotation()) > abs(degrees)){
        while(fabs(inertial.get_rotation()) > abs(degrees)){ 
        setDrive(0.50 * speed * direction, 0.50 * -speed * direction); // Speed is lessened to slow it
        pros::delay(10);
        pros::lcd::print(0, "rotation: %f", inertial.get_rotation()); // Troubleshooting
        }
    }
    else if(fabs(inertial.get_rotation()) < abs(degrees)){
        while(fabs(inertial.get_rotation()) < abs(degrees)){ 
        setDrive(0.50 * -speed * direction, 0.50 * speed*direction);
        pros::delay(10);
        pros::lcd::print(0, "rotation: %f", inertial.get_rotation()); // Troubleshooting
        }
    }
    
    
    // Stop
    setDrive(0,0);
}


