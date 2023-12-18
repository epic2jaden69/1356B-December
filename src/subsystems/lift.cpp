#include "vex.h"

int liftState = 0;      //0 = DOWN
                        //1 = UP
                        //2 = HALF


//auton functions
void spinLift(int state) {
    if (state == 0) {
        lift.spinToPosition(195, degrees, false); 
    }
    else if (state == 1) {
        lift.spinToPosition(-390, degrees, false); 
    }
    else if (state == 2) {  
        lift.spinToPosition(-50, degrees, false);
    }
}

//opcontrol functions
void liftControl() {
    if (master.ButtonL2.pressing()) {
        if (liftState == 0) {
            lift.spinToPosition(-390, degrees, false);
            wait(200, msec);
            liftState = 1;
        } 
        else if (liftState == 1) {
            lift.spinToPosition(195, degrees, false);
            wait(200, msec);
            liftState = 0;
        }
    }
    else if (master.ButtonLeft.pressing()) {
        lift.spinToPosition(-50, degrees, false);
    }
    if (master.ButtonDown.pressing()) {
        lift.spin(fwd);
    }
    Brain.Screen.printAt(50, 150, "Lift: %f", lift.position(degrees));
}