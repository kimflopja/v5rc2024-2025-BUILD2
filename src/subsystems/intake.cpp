#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

void setIntake(int power){
    intake.move(power);
}

void intake_func(){
    int intakeState = 0;
    if (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        if(intakeState = 0){
            intakeState = 1;
        } else {
            intakeState = 0;
        }
    }
    if (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        if(intakeState = 0){
            intakeState = -1;
        } else {
            intakeState = 0;
        }
    }
    // int intakeState = 50 * ((controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) - (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)));
    int intakePower = 127 * intakeState;

    setIntake(intakePower);
} 