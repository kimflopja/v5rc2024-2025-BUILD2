#include "main.h"

bool buttonRegistered = false;
bool oneActivated = false;
int armState = 0;

//when one is down, the other is opposite
// even number
// arm comes down at the start
// state -- first time its pressed it comes down
// when even number, intake on
// when odd number, shut off intake

void setClearArm(int armState){
    switch (armState) {
        case 0: // initial press
            switchBlade1.retract();
            switchBlade2.extend();
            break;
        case 1: // intake off
            switchBlade1.extend();
            switchBlade2.extend();
            setIntake(0);
            break;
        case 2: // intake on
            switchBlade1.retract();
            switchBlade2.retract();
            break;
    }
}

void clear_arm(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && !buttonRegistered) { // Up
        if(armState == 1) armState = 2;
        else if(armState == 0) armState = 1;
        else if (armState == 2) armState = 1;
        buttonRegistered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) buttonRegistered = false;

  setClearArm(armState);
  pros::delay(50); // Delay

}

