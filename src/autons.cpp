#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .6, .02, 4.45, 15);
  chassis.set_swing_constants(12, .4, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 100, 2000);
  chassis.set_turn_exit_conditions(1, 100, 2000);
  chassis.set_swing_exit_conditions(1, 100, 700);
}

bool ON = true;
int BS = 0;
int Shootaa (){
  ON = true;
  while(ON){
    ProjG.spin(forward, 100*120, voltageUnits::mV);
    if(Shoot.pressing()){
      ProjG.stop();
      wait(0.2, sec);
      ProjG.spin(forward, 100*120, voltageUnits::mV);
      wait(0.25, sec);
      continue;
    }
  }
  
  return 0;
}

int AutoShoot(){
  Proj1.spin(forward, 100, pct);
  wait(0.25, sec);
  while(true){
    Proj1.spin(forward, 100, pct);
    if(Shoot.pressing()){
      Proj1.stop();
      break;
    }
  }
  return 0;
}

void Left1(){//左1
  chassis.turn_to_angle(-45);
  chassis.drive_distance(25);
  chassis.turn_to_angle(0);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 300, degrees, false);
  wait(0.25, sec);
  chassis.drive_distance(15);//入預裝
  
  chassis.left_swing_to_angle(-30);
  chassis.drive_distance(-23);
  ArmG.spinFor(reverse, 270, degrees, false);
  chassis.turn_to_angle(-135);
  RingG.spin(fwd, 100*110, voltageUnits::mV);
  chassis.drive_timeout = 1200;
  chassis.drive_distance(30);
  wait(0.25, sec);
  chassis.drive_timeout = 1300;
  chassis.drive_distance(-22);
  wait(0.25, sec);//拉三角位的粽球 For AWP

  RingG.stop();
  default_constants();
  chassis.turn_to_angle(-240);
  RingG.spin(reverse, 100*110, voltageUnits::mV);
  chassis.drive_distance(50);//去接觸自方聯隊横向的障碍杆 For AWP
  //chassis.turn_to_angle(-270);

}

void Left2(){//左2
  chassis.drive_distance(42);
  chassis.turn_to_angle(-90);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 150, degrees, false);
  chassis.drive_distance(13);
  chassis.drive_distance(-12);//入預裝

  chassis.right_swing_to_angle(0);
  ArmG.spinFor(reverse, 120, degrees, false);
  RingG.spin(fwd, 100*110, voltageUnits::mV);
  chassis.drive_distance(10);
  chassis.drive_distance(-5);
  RingG.stop();
  chassis.right_swing_to_angle(90);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(26);
  default_constants();
  ArmG.spinFor(reverse, 50, degrees, false);
  RingG.spin(reverse, 70*110, voltageUnits::mV);
  wait(0.5, sec);
  ArmG.spinFor(fwd, 100, degrees, false);
  wait(0.5, sec);//獲取中立區左方的粽球並放入自方進攻區
  
  chassis.drive_distance(-15);
  ArmG.spinFor(reverse, 50, degrees, false);
  chassis.right_swing_to_angle(45);
  chassis.drive_distance(-40);
  chassis.right_swing_to_angle(110);
  chassis.drive_distance(25);
  chassis.right_swing_to_angle(90);
  chassis.drive_distance(25);//去張自方聯隊横向下的粽球推向自方進攻區
  
  /*RingG.spin(fwd, 70*110, voltageUnits::mV);
  chassis.drive_max_voltage = 7;
  chassis.drive_distance(16);
  wait(0.5, sec);
  //chassis.left_swing_to_angle(50);
  default_constants();
  chassis.right_swing_to_angle(90);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(13);
  RingG.spin(reverse, 70*110, voltageUnits::mV);
  wait(0.5, sec);
  ArmG.spinFor(fwd, 50, degrees, false);
  wait(0.5, sec);
  chassis.drive_distance(-20);
  chassis.right_swing_to_angle(135);
  RingG.spin(fwd, 70*110, voltageUnits::mV);
  chassis.drive_distance(20);//*/
}

void Right1(){//右1
  chassis.drive_distance(43);
  chassis.turn_to_angle(90);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 150, degrees, false);
  wait(0.1, sec);
  chassis.drive_distance(15);//入預裝

  chassis.left_swing_to_angle(65);
  chassis.drive_distance(-25);
  chassis.turn_to_angle(-100);
  ArmG.spinFor(reverse, 110, degrees, false);
  chassis.drive_distance(13);
  RingG.spinFor(fwd, 300, degrees, false);
  chassis.left_swing_to_angle(-120);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(93);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 110, degrees, false);
  wait(0.1, sec);
  chassis.drive_distance(15);//獲取不在中立區的粽球並放入自方球門

  chassis.left_swing_to_angle(55);
  ArmG.spinFor(fwd, 1200, degrees, false);
  chassis.drive_distance(-40);
  chassis.drive_max_voltage = 2;
  chassis.drive_distance(-5);//去接觸自方聯隊縱向的障碍杆 For AWP
}

void Right2(){//右2
  chassis.drive_distance(43);
  chassis.turn_to_angle(90);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 150, degrees, false);
  chassis.drive_distance(15);//入預裝
  
  chassis.drive_distance(-14);
  chassis.left_swing_to_angle(-0);
  ArmG.spinFor(reverse, 110, degrees, false);
  RingG.spin(fwd, 100*110, voltageUnits::mV);
  chassis.drive_distance(8);
  chassis.drive_distance(-8);
  RingG.stop();
  chassis.left_swing_to_angle(90);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 110, degrees, false);
  chassis.drive_distance(20);//獲取中立區右方的粽球並放入自方球門

  chassis.drive_distance(-30);
  chassis.turn_to_angle(-75);
  ArmG.spinFor(reverse, 100, degrees, false);
  RingG.spin(fwd, 100*110, voltageUnits::mV);
  chassis.drive_distance(7);
  chassis.drive_distance(-17);
  RingG.stop();
  chassis.turn_to_angle(90);
  RingG.spinFor(reverse, 300, degrees, false);
  wait(0.1, sec);
  ArmG.spinFor(fwd, 110, degrees, false);
  chassis.drive_distance(20);//獲取中立區左方的粽球並放入自方球門

  chassis.drive_distance(-20);
  chassis.left_swing_to_angle(0);
  chassis.left_swing_to_angle(-105);
}

void Skill(){//未完成
  Brain.resetTimer();
  chassis.turn_to_angle(-45);
  chassis.drive_distance(25);
  chassis.turn_to_angle(0);
  RingG.spinFor(reverse, 500, degrees, false);
  wait(0.25, sec);
  ArmG.spinFor(fwd, 300, degrees, false);
  wait(0.25, sec);
  chassis.drive_distance(15);
  chassis.drive_distance(-20);
  ArmG.spinFor(reverse, 300, degrees, false);
  chassis.right_swing_to_angle(30);
  chassis.left_swing_to_angle(70);
  task a = task(Shootaa);
  waitUntil( Brain.timer(sec) > 45 );
  ON = false;
  task aa = task(AutoShoot);
  chassis.left_swing_to_angle(120);
  chassis.drive_distance(25);
  chassis.right_swing_to_angle(90);
  chassis.drive_distance(80);
  chassis.right_swing_to_angle(45);
  chassis.drive_distance(20);
  chassis.right_swing_to_angle(0);
  ArmG.spinFor(fwd, 300, degrees, false);
  chassis.drive_distance(20);
  chassis.left_swing_to_angle(-90);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(20);
  chassis.drive_distance(30);
  chassis.drive_distance(40);
  chassis.drive_distance(-70);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(355);
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
  chassis.drive_to_point(0,0);
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