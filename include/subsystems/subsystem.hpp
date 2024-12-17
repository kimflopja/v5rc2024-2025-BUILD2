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
void setClamp(Clamp clampState);
void clamp_pistonArrows();
void clamp_pistonL1();

/*
* Latch
*/
void latch_func();
void setLatch(Latch latchState);

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