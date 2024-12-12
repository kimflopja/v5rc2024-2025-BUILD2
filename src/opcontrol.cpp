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

void skillsOpControl(){
	// Arcade Drive
	opcontrol_arcadedrive();
	// L1/L2 Lift
	lift_funcL1();
	// Arrows Clamp
	clamp_piston();
}

void HTHOpControl(){
	// Tank Drive
	opcontrol_tankdrive();
	// Arrows Lift
	lift_funcArrows();
	// L1/L2 Clamp
	clamp_pistonL1();
}

void opcontrol() {
	lift.move_absolute(0, 50);
	setUpStart(); // Sets lift state to 1, releases intake
	while (true) {

		
		// *** Skills or HTH ***
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