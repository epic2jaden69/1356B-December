#include "vex.h"

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 2;
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}

void default_constants(){
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 3, 0);
  chassis.set_turn_constants(11, .46, 0.01, 4.2, 15);  // Initial JAR values: 9, .4, .03, 4, 15
  chassis.set_swing_constants(12, .3, .003, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 200, 1500);
  chassis.set_turn_exit_conditions(0.5, 250, 800);
  chassis.set_swing_exit_conditions(1, 250, 800);
}

// Our autons
void test_functions() {  
  // Idk why but having a negative x-value yields bad results for drive_to_point()

  default_constants();
  chassis.set_coordinates(0, 0, 0);

  spinIntake(1);

  chassis.drive_distance(10);

  chassis.turn_to_angle(90);

  chassis.drive_distance(-10);

  chassis.left_swing_to_angle(180);

  chassis.turn_to_angle(-90);

  stopIntake();
} 

void far_side() {
  // Initialize the movement constants
  default_constants();

  // Deploy intake
  slapper.spin(forward, 12, volt);

  // Grab the elevation triball
  spinIntake(1);
  chassis.drive_distance(4);

  chassis.drive_distance(-33);

  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(2, -2);

  // Left Wing down

  // Descore the matchload triball
  chassis.drive_distance(-8);
  chassis.drive_distance(1);

  // Left Wing up

  // (Hopefully) score the matchload triball
  chassis.drive_max_voltage = 10;
  chassis.drive_to_point(25, -8);
  chassis.drive_max_voltage = 12;

  chassis.drive_distance(12.5);

  // Spin 180
  chassis.turn_to_angle(90);

  spinIntake(-1);

  // Score the elevation triball
  chassis.drive_distance(10);
  wait(50, msec);

  chassis.drive_distance(-15);
  chassis.set_coordinates(0, 0, 0);

  // Start heading towards the closest center bar triball
  chassis.turn_to_point(-54, 22);

  spinIntake(1);
  chassis.drive_distance(50);

  chassis.turn_to_angle(72.5);

  // Outtake, leaving that one in front of the goal
  spinIntake(-1);
  wait(200, msec);

  // Get the middle triball along the bar
  spinIntake(1);
  chassis.turn_to_angle(-20);
  chassis.drive_distance(19);

  chassis.turn_to_angle(-90);

  // Both wings down

  // Push the triballs into the goal with the wings
  chassis.drive_distance(-40);

  chassis.drive_distance(17);

  // Spin 180
  chassis.turn_to_angle(90);

  // Score the last triball in intake
  spinIntake(-1);
  chassis.drive_distance(10);

  // Back up to make sure triballs count
  chassis.drive_distance(-10);
}


// Skills 
void programming_skills() {
  default_constants();
  chassis.set_coordinates(0, 0, 0);

}
























//   // method for just testing auton functions :-)
//   default_constants();
//   chassis.set_coordinates(0, 0, 0);

//   spinIntake(1);

//   // intake deploy
//   // lift.spin(reverse, 5.0, volt);
//   // cata.spin(reverse, 11.0, volt);
//   // wait(250, msec);
//   // lift.stop();
//   // cata.stop();

//   //get elevation triball
//   chassis.drive_distance(7);
//   wait(100, msec);
//   stopIntake();
//   chassis.drive_distance(-30);
//   chassis.turn_to_angle(180);
//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_to_point(-28, 26);
  
// }

// void far_side() {
//   // make sure all the pid constants and velocities are properly set up, call this at the start of each auto
//   default_constants();
//   chassis.drive_timeout = 1000;
//   chassis.turn_timeout = 750;

//   spinIntake(1);

//   // intake deploy
//   lift.spin(reverse, 5.0, volt);
//   cata.spin(reverse, 11.0, volt);
//   wait(250, msec);
//   lift.stop();
//   cata.stop();

//   // rush to the middle and turn
//   chassis.drive_distance(43);
//   chassis.turn_to_angle(90);
  
//   // outtake triball and push in
//   spinIntake(-1);
//   wait(100, msec);
//   chassis.drive_max_voltage = 12;
//   chassis.drive_distance(9);

//   // back out, turn, and grab another triball
//   chassis.drive_distance(-10);
//   chassis.drive_max_voltage = 10;
//   spinIntake(1);
//   chassis.turn_to_angle(-116);
//   chassis.drive_distance(25);
//   //stopIntake();

//   // drive back and turn back to the front off the goal;
//   chassis.drive_distance(-25);
//   chassis.turn_to_angle(90);

//   // outtake triball and push in
//   spinIntake(-1);
//   wait(250, msec);
//   chassis.drive_max_voltage = 12;
//   chassis.drive_distance(9);

//   // back out, turn, and grab another triball
//   chassis.drive_distance(-9);
//   chassis.drive_max_voltage = 10;
//   spinIntake(1);
//   chassis.turn_to_angle(-70);
//   chassis.drive_distance(23);
//   //stopIntake();

//   // drive back and turn back to the front off the goa;
//   chassis.drive_distance(-23);
//   chassis.turn_to_angle(90);

//   // outtake triball and push in
//   spinIntake(-1);
//   wait(250, msec);
//   chassis.drive_max_voltage = 12;
//   chassis.drive_distance(13);
//   wait(500, msec);
//   chassis.drive_distance(-13);
// }

// void close_side() {
//   default_constants();

//   // score preload
//   deployWings(1);
//   wait(750, msec);
//   deployWings(0);

//   // deploy intake
//   lift.spin(reverse, 5.0, volt);
//   cata.spin(reverse, 11.0, volt);
//   wait(250, msec);
//   lift.stop();
//   cata.stop();

//   // turn and descore the matchload triball
//   chassis.turn_timeout = 1000;
//   chassis.turn_to_angle(-154);

//   // while outtaking, drive towards the elevation bar
//   spinIntake(-1);
//   chassis.drive_max_voltage = 7;
//   chassis.drive_distance(51);                                                                             
// }

// // skills auto
// void prog_skills() {
//   default_constants();

//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_distance(-11);

//   // init the start location and lift degrees
//   chassis.set_coordinates(0, 0, 45);
//   lift.setPosition(0, degrees);

//   // // deploy intake
//   lift.spin(forward, 5.0, volt);
//   wait(200, msec);
//   lift.stop();

//   chassis.drive_timeout= 500;
//   chassis.drive_max_voltage = 12;

//   // push preload into side of goal
//   chassis.drive_distance(-35);
//   chassis.drive_timeout = 3500;
//   chassis.drive_max_voltage = 10;
//   wait(250, msec);

//   // // line up with the matchload bar
//   chassis.drive_distance(5);
//   chassis.turn_to_angle(108);
//   chassis.drive_distance(-1);
//   deployWings(1);
//   spinLift(1);
//   spinCata();

//   // start shooting for 30 seconds
//   wait(1, sec);
//   deployWings(0);
//   stopCata();
//   spinLift(0);
//   wait(500, msec);

//   // cross the elevation bar
//   chassis.drive_timeout = 1000;
//   chassis.turn_to_angle(45);
//   chassis.turn_timeout = 1000;
//   chassis.drive_max_voltage = 9;
//   chassis.drive_distance(28);
//   chassis.turn_to_angle(90);
//   chassis.drive_timeout = 2000;
//   chassis.drive_distance(70);
//   chassis.set_coordinates(0, 0, 0);

//   //tbd
//   chassis.drive_max_voltage = 12;
//   chassis.drive_to_point(35, 32);
//   chassis.drive_distance(10);
//   chassis.drive_distance(-10);
//   chassis.turn_to_angle(-180);
//   chassis.drive_timeout = 1000;
//   chassis.drive_distance(15);
//   chassis.set_coordinates(0, 0, 0);
//   intake.stop();
//   chassis.turn_to_angle(-40);
//   chassis.drive_max_voltage = 6;
//   chassis.drive_timeout = 3000;
//   chassis.drive_distance(42);
//   chassis.turn_to_angle(15);
//   deployWings(1);
//   wait(500, msec);
//   chassis.drive_max_voltage = 12;
//   chassis.drive_timeout = 1000;
//   chassis.drive_distance(-55);
//   wait(100, msec);
//   deployWings(0);
//   wait(1000, msec);
//   chassis.turn_to_angle(-40);
//   chassis.drive_distance(-50);
//   chassis.turn_to_angle(-15);
//   deployWings(1);
//   wait(500, msec);
//   chassis.drive_distance(-55);
//   wait(100, msec);
//   chassis.drive_distance(30);
// }

// void prog_skills2() {
//   default_constants();

//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_distance(-11);

//   // init the start location and lift degrees
//   chassis.set_coordinates(0, 0, 45);
//   lift.setPosition(0, degrees);

//   // // deploy intake
//   lift.spin(forward, 5.0, volt);
//   wait(200, msec);
//   lift.stop();

//   chassis.drive_timeout= 500;
//   chassis.drive_max_voltage = 12;

//   // push preload into side of goal
//   chassis.drive_distance(-38);
//   chassis.drive_timeout = 3500;
//   chassis.drive_max_voltage = 10;
//   wait(250, msec);

//   // // line up with the matchload bar
//   chassis.turn_to_angle(10);
//   chassis.drive_distance(13);
//   chassis.turn_to_angle(-71);
//   chassis.drive_distance(3);
//   spinLift(2);
//   spinCata();

//   // start shooting for 30 seconds
//   wait(31, sec);
//   stopCata();
//   spinLift(0);
//   wait(500, msec);

//   // cross the elevation bar
//   chassis.drive_timeout = 1000;
//   chassis.turn_to_angle(-135);
//   chassis.turn_timeout = 1000;
//   chassis.drive_max_voltage = 9;
//   chassis.drive_distance(-19);
//   chassis.turn_to_angle(-90);
//   chassis.drive_timeout = 2000;
//   chassis.drive_distance(-72);
//   chassis.set_coordinates(0, 0, 0);

//   //tbd
//   chassis.drive_max_voltage = 12;
//   chassis.drive_to_point(-35, -32);
//   chassis.drive_distance(6);
//   chassis.turn_to_angle(0);
//   chassis.drive_timeout = 1000;
//   chassis.drive_distance(15);
//   chassis.set_coordinates(0, 0, 0);
//   intake.stop();
//   chassis.drive_to_point(-28, 35);
//   chassis.turn_to_angle(10);
//   deployWings(1);
//   chassis.drive_distance(-50);
//   wait(500, msec);
//   deployWings(0);;
//   chassis.drive_distance(30);
//   chassis.drive_to_point(-50, 35);
//   chassis.turn_to_angle(-15);
//   deployWings(1);
//   chassis.drive_distance(-50);
//   wait(500, msec);
//   deployWings(0);
//   chassis.drive_distance(25);


//   // chassis.turn_to_angle(-40);
//   // chassis.drive_max_voltage = 6;
//   // chassis.drive_timeout = 3000;
//   // chassis.drive_distance(42);
//   // chassis.turn_to_angle(15);
//   // deployWings(1);
//   // wait(500, msec);
//   // chassis.drive_max_voltage = 12;
//   // chassis.drive_timeout = 1000;
//   // chassis.drive_distance(-55);
//   // wait(100, msec);
//   // deployWings(0);
//   // wait(1000, msec);
//   // chassis.turn_to_angle(-40);
//   // chassis.drive_distance(-50);
//   // chassis.turn_to_angle(-15);
//   // deployWings(1);
//   // wait(500, msec);
//   // chassis.drive_distance(-55);
//   // wait(100, msec);
//   // chassis.drive_distance(30);
// }


// void prog_skills3()
// {
//   default_constants();

//   chassis.drive_max_voltage = 12.7;
//   chassis.drive_timeout = 1000;

//   chassis.drive_distance(-35);
//   wait(100, msec);

//   chassis.drive_distance(15);
//   chassis.turn_to_angle(-97.5);
//   chassis.drive_max_voltage = 5;
//   chassis.drive_distance(6);
//   wait(100, msec);

//   spinCata();
//   chassis.drive_with_voltage(0.5, 0.5);
//   wait(27.5, sec);
//   stopCata();

//   chassis.set_coordinates(0, 0, 0);

//   chassis.drive_max_voltage = 11;
//   chassis.drive_timeout = 2000;
//   chassis.turn_to_angle(-55);
//   chassis.drive_distance(-30);
//   chassis.turn_to_angle(-17);

//   chassis.drive_max_voltage = 12.7;
//   chassis.drive_distance(-76);

//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_timeout = 1700;
//   wingsLeft.set(true);

//   chassis.drive_to_point(-35, -30);
//   deployWings(0);
//   wait(100, msec);
//   chassis.drive_distance(15);
//   wait(100, msec);
//   chassis.drive_timeout = 600;
//   chassis.drive_distance(-100);
//   chassis.drive_timeout = 1000;
//   wait(100, msec);
//   chassis.drive_distance(5);  

//   chassis.turn_to_angle(0);
//   chassis.set_coordinates(0, 0, 0);

//   chassis.drive_timeout = 2000;
//   chassis.drive_max_voltage = 5;
//   chassis.drive_distance(15);
//   chassis.drive_to_point(-25, 48);
//   chassis.turn_to_angle(15);

//   deployWings(1);
//   chassis.drive_max_voltage = 12.7;
//   chassis.drive_distance(-40);
//   wait(250, msec);
//   deployWings(0);
//   chassis.drive_distance(12);

//   chassis.drive_to_point(-50, 28);
//   chassis.turn_to_angle(-15);
//   deployWings(1);
//   chassis.drive_distance(-40);
//   wait(250, msec);
//   deployWings(0);
//   chassis.drive_distance(25);

//   chassis.turn_to_angle(90);
//   deployWings(1);
//   chassis.drive_distance(-23);
//   chassis.turn_to_angle(37.5);
//   chassis.drive_distance(-41);

//   chassis.turn_to_angle(0);
//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_max_voltage = 12.7;

//   wingsRight.set(true);
//   chassis.drive_to_point(55, -25);
//   wait(100, msec);
//   chassis.drive_distance(18);
//   wait(100, msec);
//   deployWings(0);
//   chassis.drive_timeout = 600;
//   chassis.drive_distance(-100);
//   chassis.drive_timeout = 1000;
//   wait(100, msec);
//   chassis.drive_distance(5); 
// }

// void close_side2()
// {
//   default_constants();
//   chassis.set_coordinates(0, 0, 0);

//   // intake deploy
//   lift.setPosition(0, degrees);
//   lift.spin(forward, 5, volt);
//   wait(200, msec);
//   lift.stop();

  
//   spinIntake(1);
//   //intake.spin(fwd, 12.7, volt);
//   chassis.turn_to_angle(15);
//   chassis.drive_distance(47);
//   chassis.drive_distance(-3);

//   chassis.turn_to_angle(-90);
//   deployWings(1);
//   chassis.drive_timeout = 700;
//   chassis.drive_distance(-15);
//   chassis.drive_timeout = 1000;

//   deployWings(0);

//   chassis.drive_distance(3);
//   chassis.turn_to_angle(90);

//   intake.spin(reverse, 12.7, volt);
//   chassis.drive_distance(15);

//   chassis.drive_distance(-23);

//   intake.spin(fwd, 12.7, volt);
//   chassis.set_coordinates(0, 0, 0);
//   chassis.drive_to_point(18, -8);

//   chassis.set_coordinates(0, 0, 0);
//   chassis.turn_to_angle(180);
//   chassis.drive_distance(14);
//   chassis.turn_to_angle(-90);
//   intake.spin(reverse, 6, volt);
//   wait(200, msec);
//   chassis.turn_to_angle(35);
//   chassis.set_coordinates(0, 0, 0);

//   chassis.drive_max_voltage = 12.7;
//   chassis.drive_to_point(-22, -20);

//   chassis.drive_distance(-10);
//   wait(50, msec);
//   chassis.drive_distance(10);
// }