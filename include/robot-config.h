#include "vex.h"

using namespace vex;

extern brain Brain;

extern controller master;
extern inertial imu;

//sensors
extern digital_in limit_switch;

//drivetrain
extern motor LeftFront;
extern motor LeftMiddle;
extern motor LeftBack;
    
extern motor RightFront;
extern motor RightMiddle;
extern motor RightBack;

extern motor_group RightDrive;
extern motor_group LeftDrive;

//other motors
extern motor cata;
extern motor intake;
extern motor lift;

//pneumatics
extern digital_out wings;

// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );