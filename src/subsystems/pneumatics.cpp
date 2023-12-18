#include "vex.h"

//auton functions
void deployWings(int state) {
    if (state == 0) {
        wings.set(false);
    }
    else if (state = 1) {
        wings.set(true);
    }
}

//opcontrol functions
bool wingsExtended = false;

void wingsControl() {
    if (master.ButtonA.pressing()) {
        if (wingsExtended) {
            wings.set(false);
            wait(250, msec);
            wingsExtended = false;
        }
        else {
            wings.set(true);
            wait(250, msec);
            wingsExtended = true;
        }
    }
}