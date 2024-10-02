#include "main.h"


/*
* Controller
*/
pros::Controller controller_master(pros::E_CONTROLLER_MASTER);

/*
* Drivetrain motors
*/

// *** Change ports according to what we use ***
// Test robo has : 19, 20 and -1 -2
pros::Imu inertial(10); 

pros::Motor left_motor1(19, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor left_motor2(20, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);  
pros::Motor left_motor3(-3, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees); // Reversed

pros::Motor right_motor1(-1, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor right_motor2(-2, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);    
pros::Motor right_motor3(-6, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees); // Reversed


/*
* Subsystem motors
*/

/*
* Misc, for values and such
*/