#include "vex.h"

//auton functions
void spinSlapper() {
    slapper.spin(forward, 12, volt);
}

//opcontrol functions
bool slapperRunning = false;

void slapperTask() {
    while (true) {
        if (!slapperRunning){
            // Code for when limit switch is replaced XD - Commented 12/16/2023
            // if (limit_switch.value() == 0) {
            //     slapper.stop();
            // }
            // else {
            //     slapper.spin(forward, 8, volt);
            // }
            slapper.stop();
        }

        if (master.ButtonL1.pressing()) {
            if (slapperRunning) {
                wait(200, msec);
                slapperRunning = false;
            } else {
                slapper.spin(forward, 12, volt);
                wait(200, msec);
                slapperRunning = true;
            }
        }

        wait(20, msec);
    }
}
