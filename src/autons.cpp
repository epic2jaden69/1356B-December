#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 3, 0);
  chassis.set_turn_constants(10, .4, .03, 4, 15);
  chassis.set_swing_constants(12, .3, .002, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 3500);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 2;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
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

// our autons
void test_functions() {    
  // method for just testing auton functions :-)
  lift.spinFor(reverse, 200, msec);
  wait(1, sec);
}

void far_side() {
  // make sure all the pid constants and velocities are properly set up, call this at the start of each auto
  default_constants();
  chassis.drive_timeout = 1000;
  chassis.turn_timeout = 750;

  spinIntake(1);

  // intake deploy
  lift.spin(reverse, 5.0, volt);
  cata.spin(reverse, 11.0, volt);
  wait(250, msec);
  lift.stop();
  cata.stop();

  // rush to the middle and turn
  chassis.drive_distance(43);
  chassis.turn_to_angle(90);
  
  // outtake triball and push in
  spinIntake(-1);
  wait(100, msec);
  chassis.drive_max_voltage = 12;
  chassis.drive_distance(9);

  // back out, turn, and grab another triball
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;
  spinIntake(1);
  chassis.turn_to_angle(-116);
  chassis.drive_distance(25);
  //stopIntake();

  // drive back and turn back to the front off the goal;
  chassis.drive_distance(-25);
  chassis.turn_to_angle(90);

  // outtake triball and push in
  spinIntake(-1);
  wait(250, msec);
  chassis.drive_max_voltage = 12;
  chassis.drive_distance(9);

  // back out, turn, and grab another triball
  chassis.drive_distance(-9);
  chassis.drive_max_voltage = 10;
  spinIntake(1);
  chassis.turn_to_angle(-70);
  chassis.drive_distance(23);
  //stopIntake();

  // drive back and turn back to the front off the goa;
  chassis.drive_distance(-23);
  chassis.turn_to_angle(90);

  // outtake triball and push in
  spinIntake(-1);
  wait(250, msec);
  chassis.drive_max_voltage = 12;
  chassis.drive_distance(13);
  wait(500, msec);
  chassis.drive_distance(-13);
}

void close_side() {
  default_constants();

  // score preload
  deployWings(1);
  wait(750, msec);
  deployWings(0);

  // deploy intake
  lift.spin(reverse, 5.0, volt);
  cata.spin(reverse, 11.0, volt);
  wait(250, msec);
  lift.stop();
  cata.stop();

  // turn and descore the matchload triball
  chassis.turn_timeout = 1000;
  chassis.turn_to_angle(-154);

  // while outtaking, drive towards the elevation bar
  spinIntake(-1);
  chassis.drive_max_voltage = 7;
  chassis.drive_distance(51);                                                                             
}

// skills auto
void prog_skills() {
  default_constants();

  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(-11);

  // init the start location and lift degrees
  chassis.set_coordinates(0, 0, 45);
  lift.setPosition(0, degrees);

  // // deploy intake
  lift.spin(reverse, 5.0, volt);
  cata.spin(reverse, 11.0, volt);
  wait(250, msec);
  lift.stop();
  cata.stop();

  chassis.drive_timeout= 500;
  chassis.drive_max_voltage = 12;

  // push preload into side of goal
  chassis.drive_distance(-32);
  chassis.drive_timeout = 3500;
  chassis.drive_max_voltage = 10;
  wait(250, msec);

  // // line up with the matchload bar
  chassis.drive_distance(3);
  chassis.turn_to_angle(12);
  chassis.drive_distance(16);
  chassis.turn_to_angle(-67);
  spinCata();
  chassis.drive_distance(4);

  // start shooting for 35 seconds
  chassis.drive_with_voltage(0, 0.5);
  wait(29, sec);
  stopCata();
  spinLift(0);

  // cross the elevation bar
  chassis.drive_timeout = 300;
  chassis.drive_distance(-5);
  chassis.turn_timeout = 100;
  chassis.turn_to_angle(-95);
  chassis.turn_timeout = 1000;
  chassis.drive_max_voltage = 9;
  chassis.drive_to_point(27, 30);
  chassis.turn_to_angle(-92);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-73);
  chassis.set_coordinates(0, 0, 0);

  //tbd
  chassis.drive_max_voltage = 12;
  chassis.drive_to_point(-27, -30);
  chassis.drive_distance(10);
  chassis.turn_to_angle(-110);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(20);
  chassis.drive_distance(-5);
  intake.stop();
  chassis.turn_to_angle(0);
  chassis.drive_max_voltage = 6;
  chassis.drive_timeout = 3000;
  chassis.drive_distance(17);
  chassis.drive_to_point(-44, 20);
  chassis.turn_to_angle(12);
  deployWings(1);
  wait(500, msec);
  chassis.drive_max_voltage = 12;
  chassis.drive_timeout = 1000;
  chassis.drive_distance(-55);
  wait(100, msec);
  deployWings(0);
  wait(1000, msec);
  chassis.drive_to_point(-70, 10);
  chassis.turn_to_angle(-20);
  deployWings(1);
  wait(500, msec);
  chassis.drive_distance(-55);
  wait(100, msec);
  chassis.drive_distance(30);
}