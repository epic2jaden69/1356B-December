#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;


// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

controller master = controller(primary);
inertial imu = inertial(PORT4);

//sensors
digital_in limit_switch = digital_in(Brain.ThreeWirePort.A);

//drivetrain
motor LeftFront = motor(PORT9, ratio6_1, true);
motor LeftMiddle = motor(PORT7, ratio6_1, true);
motor LeftBack = motor(PORT6, ratio6_1, true);
    
motor RightFront = motor(PORT1, ratio6_1, false);
motor RightMiddle = motor(PORT3, ratio6_1, false);
motor RightBack = motor(PORT2, ratio6_1, false);

motor_group RightDrive = motor_group(RightFront, RightMiddle, RightBack);
motor_group LeftDrive = motor_group(LeftFront, LeftMiddle, LeftBack);

//other motors
motor cata = motor(PORT5, ratio36_1);
motor intake = motor(PORT20, ratio18_1);
motor lift = motor(PORT10, ratio18_1);

//pneumatics
digital_out wings = digital_out(Brain.ThreeWirePort.D);


// VEXcode device constructors

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}