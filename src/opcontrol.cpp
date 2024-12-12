#include "main.h"

/**
 * OP control for Skills.
 */

void skillsOpControl(){
	// Arcade Drive
	opcontrol_arcadedrive();
	// L1/L2 Lift
	lift_funcL1();
	// Arrows Clamp
	clamp_piston();
}

/**
 * OP control for HTH.
 */


void HTHOpControl(){
	// Tank Drive
	opcontrol_tankdrive();
	// Arrows Lift
	lift_funcArrows();
	// L1/L2 Clamp
	clamp_pistonL1();
}

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
	lift.move_absolute(0, 50); // Makes sure the lift is at ZERO, so the hang works PROPERLY.
	// If there is a problem with the LIFT, go to LIFT.CPP and change the values.
	setUpStart(); // Releases intake.
	while (true) {

		
		/**
		 * Skills or HTH
		 * Comment out the one you are NOT using.
		 */

		//skillsOpControl();
		HTHOpControl();

		// . . .
    	// More op control code goes here
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