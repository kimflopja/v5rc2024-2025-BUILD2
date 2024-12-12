#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

/**
* preferably dont touch
*/
bool buttonPressed = false; 
bool intakeMove = false;
bool intakeMoveRev = false;

/**
* preferably dont touch
*/
void setIntake(int power){
    intake.move(power);
}

/**
* The INTAKE.
* Not sure why this would need to be changed.
* If you want to change the speed of the intake, scroll down and see my instructions.
*/
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
        setIntake(100); // Change THIS to change the speed.
    }
    else if(intakeMoveRev) {
        setIntake(-100); // And THIS to change the speed.
    }
    else setIntake(0); // Do NOT change this.
    

    //int intakeState = 110 * ((controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) - (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))); 
    //setIntake(intakeState);
} 
