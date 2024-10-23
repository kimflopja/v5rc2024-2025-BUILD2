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

// Top Left: -11, Green
// Bottom Left: 20 (Back), 6 (Front), Green
pros::Motor left_motor1(-11, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor left_motor2(20, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);  
pros::Motor left_motor3(6, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees); // Reversed

// Top Right: -10, Green
// Bottom Right: 1 (Back), 5 (Front), Green
pros::Motor right_motor1(10, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor right_motor2(-1, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);    
pros::Motor right_motor3(-5, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees); // Reversed


/*
* Subsystem motors
*/

// Intake System: -15, Green
// Lift: -16, Red, !Because FWD is down!
//arm goes up at start of match
pros::Motor intake(-15, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor lift(-16, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

// Pneumatics
// Solenoid: h
pros::adi::Pneumatics clamp_piston1('h', false);   

/*
* Misc, for values and such
*/