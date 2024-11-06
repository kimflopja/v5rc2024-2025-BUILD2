#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

bool r1Pressed = false; 
bool r2Pressed = true;
bool intakeMove = false;

void setIntake(int power){
    intake.move(power);
}

// Rising edge circuit
void intake_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !r1Pressed){
        r1Pressed = true;
        intakeMove = !intakeMove;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) r1Pressed = false;

    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !r2Pressed){
        r2Pressed = true;
        intakeMove = !intakeMove;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) r2Pressed = false;

    if(intakeMove && r1Pressed){
        r2Pressed = false;
        setIntake(127);
    }
    if(intakeMove && r2Pressed) {
        r1Pressed = false;
        setIntake(-127);
    }
    

    //int intakeState = 110 * ((controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) - (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))); 
    //setIntake(intakeState);
} 
