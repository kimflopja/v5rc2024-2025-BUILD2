#include "main.h"

void autonomous() {
	inertial.tare_heading(); // Set inertial heading to 0
	//resetDriveEncoders();// Reset drive sensors to 0
	// Set brake to hold ?
	// Diff program for diff auton OR auton selector
	auton_turn(90, 30);
	//pros::delay(50);
	auton_drive(100, 20);
}
