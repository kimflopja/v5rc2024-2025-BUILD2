#include "main.h"


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
    int x = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int y = controller_master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    //Extra precision
    setArcadeDrive((x*abs(x))/100, (y*abs(y))/100);
}




/*
*
* ///////////////// Telemetry Functions :3 ///////////////// 
* 
*/

/*
* Sets the "absolute" zero point of the motors to the current position
*/
void tarePosition(){
    left_motor1.tare_position();
    left_motor2.tare_position();
    left_motor3.tare_position();

    right_motor1.tare_position();
    right_motor2.tare_position();
    right_motor3.tare_position();
}

/*
* Reset encoders
*/

/*
* Potentiometer
*/

