#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	lift.move_absolute(0, 50);
	setUpStart(); // Sets lift state to 1, releases intake
	while (true) {

		
		// Drive
		// *** If skills, arcade drive ***
		//opcontrol_tankdrive(); // Tank drive
		opcontrol_arcadedrive(); // Arcade drive

		// . . .
    	// More op control code goes here
		// Set up
		// Clamp
		clamp_piston(); // Skills
		//clamp_pistonL1(); // HTH
		// Lift
		lift_funcL1(); // Skills
		//lift_funcArrows(); // HTH
		// Intake
		intake_func();
		// Hook
		hook_piston_func();
		// Switchblade
		clear_arm();
    	// . . .

		// Delay 
		pros::delay(util::DELAY_TIME); 
	}
}