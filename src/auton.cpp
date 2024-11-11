#include "main.h"

void autonomous() {
	inertial.tare(); // Set inertial values to 0
	//resetDriveEncoders();// Reset drive sensors to 0
	//resetPID(); // Reset PID values
	//auton_turn(90, 30);
	//pros::delay(50);
	auton_drive(100, 20);
}
