#include "vex.h"

//auton functions
void spinCata() {
    cata.spin(reverse, 11, volt);
}

void stopCata() {
    cata.stop();
}

//opcontrol functions
bool cataRunning = false;

void cataControl() {
    if (master.ButtonL1.pressing()) {
        if (cataRunning) {
            cata.stop();
            lift.stop();
            wait(200, msec);
            cataRunning = false;
        } else {
            cata.spin(reverse, 11, volt);
            lift.spin(reverse, 2, volt);
            wait(200, msec);
            cataRunning = true;
        }
    }
}
