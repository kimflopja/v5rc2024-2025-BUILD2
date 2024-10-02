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
void setArcadeDrive(int x, int y);

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
void tarePosition();

/*
* Resets drive sensors at the start of opcontrol
*/
void opcontrol_drive_sensors_reset();

