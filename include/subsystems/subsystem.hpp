#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"


/*
*
* ///////////////// Subsystem Functions ///////////////// 
* 
*/



/*
* Intake
*/
void intake_func();
void setIntake(int power);


/*
* Lift
*/
void setLift(int liftState);
void lift_funcL1();
void lift_funcArrows();


/*
* Clamp
*/
void clamp_piston();
void clamp_pistonL1();

/*
* Hook
*/
void hook_piston_func();

/*
* Ring clear arm
*/
void clear_arm();
void setClearArm(int armState);

/*
* Ring clear arm
*/
void setUpStart();

// Skills or HTH
void skillsOpControl();
void HTHOpControl();