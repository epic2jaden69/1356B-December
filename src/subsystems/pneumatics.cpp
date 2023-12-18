#include "vex.h"

//auton functions
void deployWings(int state) {
    if (state == 0) {
        wingsLeft.set(false);
        wingsRight.set(false);
    }
    else if (state = 1) {
        wingsLeft.set(true);
        wingsRight.set(true);
    }
}

//opcontrol functions
bool wingsExtended = false;

void wingsTask() {
    while (true) {
        if (master.ButtonL2.pressing()) {
            if (wingsExtended) {
                wingsLeft.set(false);
                wingsRight.set(false);
                wait(200, msec);
                wingsExtended = false;
            }
            else {
                wingsLeft.set(true);
                wingsRight.set(true);
                wait(200, msec);
                wingsExtended = true;
            }
        }
        wait(20, msec);
    }
}