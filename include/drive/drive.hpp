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
* Turning
*/
void drive_turn();



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


