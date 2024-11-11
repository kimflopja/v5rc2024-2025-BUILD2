#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"

/*
*
* ///////////////// Movement Functions :3 ///////////////// 
* 
*/



//////           //////
/// Opcontrol usage ///
//////           //////



/*
* Set the motors to a value
*/
void setDrive(int leftJoystick, int rightJoystick);

/*
* Set the motors to a value for ARCADE
*/
void setArcadeDrive(int rotate, int drive);

/*
* Tank drive
*/
void opcontrol_tankdrive();

/*
* Arcade drive
*/
void opcontrol_arcadedrive();



//////       //////
/// Auton usage ///
//////       //////



/*
* Drive auton
*/
void auton_drive(int goal, int speed);



/*
* Drive turn
*/
void auton_turn(int degrees, int speed);



/*
*
* ///////////////// Telemetry Functions :3 ///////////////// 
* 
*/

/*
* sets the zero point of the motors to the current position
*/
void resetDriveEncoders();

/*
* Gets the avg drive pos
*/
double avgDriveEncoderValue();

/*
* Reset PID
*/
void resetPID();