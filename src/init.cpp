#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	
	// Tare Position //
	lift.tare_position(); // Set ABS lift position to ZERO
	intake.tare_position(); // Set ABS lift position to ZERO

	// Set Motor Brakes to ____
	// Drivetrain: COAST
	left_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_motor3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	// Intake:
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	// Lift:
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}