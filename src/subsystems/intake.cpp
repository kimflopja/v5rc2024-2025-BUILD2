#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

void setIntake(int state){
    intake.move(state);
}

void intake_func(){
    int intakeState = 50 * ((controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) - (controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)));
    setIntake(intakeState);
} 