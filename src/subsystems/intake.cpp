#include "vex.h"

//auton functions
void spinIntake(int direction) {
    intake.spin(fwd, 12.7 * direction, volt);
}

void stopIntake() {
    intake.spin(fwd, 2, volt);
}

//opcontrol functions
void intakeControl() {
    if (master.ButtonR1.pressing()) {
        intake.spin(fwd, 12.7, volt);
    } 
    else if (master.ButtonR2.pressing()) {
        intake.spin(reverse, 12.7, volt);
    }
    else {
        intake.spin(fwd, 2, volt);
    }
}
