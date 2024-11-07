#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

bool buttonPressed = false; 
bool intakeMove = false;
bool intakeMoveRev = false;

void setIntake(int power){
    intake.move(power);
}

// Rising edge circuit
void intake_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !buttonPressed){
        buttonPressed = true;
        intakeMoveRev = !intakeMoveRev;
        intakeMove = false;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        buttonPressed = false;
    }

    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !buttonPressed){
        buttonPressed = true;
        intakeMove = !intakeMove;
        intakeMoveRev = false;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        buttonPressed = false;
    }


    if(intakeMove){
        setIntake(100);
    }
    else if(intakeMoveRev) {
        setIntake(-100);
    }
    else setIntake(0);
    

    //int intakeState = 110 * ((controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) - (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))); 
    //setIntake(intakeState);
} 
