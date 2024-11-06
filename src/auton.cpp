#include "main.h"

void autonomous() {
	inertial.tare(); // Reset inertial posiiton to 0
	resetDriveEncoders();// Reset drive sensors to 0
	// Set brake to hold ?
	// Diff program for diff auton OR auton selector
}