#include "main.h"

PID chassis;

void autonomous() {
	chassis.reset_PID();//Reset pid targets to 0
	inertial.tare(); //Resetjhg inertial posiiton to 0
	resetDriveEncoders();// Reset drive sensors to 0
	// Set brake to ___
	//Auton selector
}