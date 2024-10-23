#pragma once

#include "api.h"

/*
* Controller
*/
extern pros::v5::Controller controller_master;


/*
* Drivetrain motors
*/

extern pros::Imu inertial;

extern pros::Motor left_motor1;
extern pros::Motor left_motor2;        
extern pros::Motor left_motor3;

extern pros::Motor right_motor1;
extern pros::Motor right_motor2;     
extern pros::Motor right_motor3;



/*
* Subsystem motors
*/

extern pros::Motor lift;     

extern pros::Motor intake;

extern pros::adi::Pneumatics clamp_piston1;  

/*
* Pneumatics
*/





/*
* Sensors
*/




/*
* Misc, for values and such
*/