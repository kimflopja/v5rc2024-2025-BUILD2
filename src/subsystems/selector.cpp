#include "main.h"
#include "pros/llemu.hpp"

bool buttonLeftRegistered = false;
bool buttonRightRegistered = false;
int autonState = 0;

/**
* NOT IN USE OR IMPORTANT, IGNORE IT WHEN ITS ON THE BOT
*/
int autonSelector(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && !buttonLeftRegistered) {
        if(autonState < 3) autonState ++;
        else autonState = 3;
        buttonLeftRegistered = true;
    } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) buttonLeftRegistered = false;

    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && !buttonRightRegistered) {
        if(autonState > 0) autonState --;
        else autonState = 0;
        buttonRightRegistered = true;
    } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) buttonRightRegistered = false;

    pros::lcd::print(3, "0 - Far Side");
    pros::lcd::print(4, "1 - Close Side");
    pros::lcd::print(5, "2 - Far Side Mirrored");
    pros::lcd::print(6, "3 - Close Side Mirrored");
    pros::lcd::print(7, "4 - Auton Skills");
    pros::delay(50); // Delay
    return autonState;
}
