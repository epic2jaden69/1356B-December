#include "vex.h"

void controllerGUI() {
    master.Screen.clearLine(3);
    while (1) {
        master.Screen.clearLine(3);
        wait(100, msec);
        master.Screen.print("IMU: %f", imu.heading(degrees));
    }
}
