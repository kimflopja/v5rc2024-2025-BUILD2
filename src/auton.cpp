#include "main.h"

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

int autonSel;

void competition_initialize() {
	/// ...
	int autonSel = autonSelector();
	while (true) {
		 pros::lcd::print(2, "State: %d", autonSel);
	}
}

/*
* Autonomous
*/
void autonomous() {
	inertial.tare(); // Set inertial values to 0
	resetDriveEncoders();// Reset drive sensors to 0
	resetPID();
	setUpStart();
	int autonSel = 4;
	switch (autonSel)
  	{
		case 0: // Far Side
			farSide();
			break;
		case 1: // Close Side
			closeSide();
			break;
		case 2: // Far Side Mirrored
			farSideMirrored();
			break;
		case 3: // Close Side Mirrored
			closeSideMirrored();
			break;
		case 4: // Skills
			autonSkills2();
			break;
		case 5:// test
			driveTest();
			break;
  	}
}
