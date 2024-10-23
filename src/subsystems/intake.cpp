#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// TOp button run, bottom button run reverse.
// Hit same button to stop it
void intake_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intake.move(40);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {

    }
}