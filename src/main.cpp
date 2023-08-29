#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/ /*--------------------------------------------------------------------------------------*/
/*                             VEXcode Config                                */ /*                                   VEXcode Config                                     */
/*                                                                           */ /*                                                                                      */
/*  Before you do anything else, start by configuring your motors and        */ /*   在进行其他操作之前，首先使用屏幕右上方的 V5 端口图标配置电机和传感器。                   */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */ /*   这样做会自动更新 robot-config.cpp 和 robot-config.h，因此您无需更新。确保电机正确反转。 */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */ /*   the drive, spinning all motors forward should drive the robot forward.             */
/*  you don't have to. Ensure that your motors are reversed properly. For    */ /*--------------------------------------------------------------------------------------*/
/*  the drive, spinning all motors forward should drive the robot forward.   */ 
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/ /*---------------------------------------------------------------------------*/ 
/*                             JAR-Template Config                           */ /*                             JAR-Template Config                           */
/*                                                                           */ /*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */ /*  所有神奇的事情都发生在这里。请按照以下说明输入机器人的所有物理常数和数值。      */
/*  all the physical constants and values for your robot. You should         */ /*  您应该已经使用侧边栏配置器手动配置了机器人。                                 */
/*---------------------------------------------------------------------------*/ /*---------------------------------------------------------------------------*/

Drive chassis(

  // Specify your drive setup below. There are seven options:
  // ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
  // For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
  // 请在下面指定硬盘设置。共有七个选项：
  // ZERO_TRACKER_NO_ODOM(无里程计), ZERO_TRACKER_ODOM, 
  // TANK_ONE_ENCODER, TANK_ONE_ROTATION, 
  // TANK_TWO_ENCODER, TANK_TWO_ROTATION, 
  // HOLONOMIC_TWO_ENCODER, HOLONOMIC_TWO_ROTATION
  // 例如，如果您不使用里程计，则在下面输入 ZERO_TRACKER_NO_ODOM：
  ZERO_TRACKER_NO_ODOM,

  // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
  // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".
  // 将驱动电机的名称添加到下面的电机组中，用逗号分隔，例如：motor_group(Motor1,Motor2,Motor3)。
  // 您在使用侧边栏配置器配置机器人时所选择的电机名称都可以输入，不一定非得是 "Motor1"和 "Motor2"。

  // Left Motors:
  motor_group(LAA, LBB),

  // Right Motors:
  motor_group(RAA, RBB),

  // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
  // 以端口格式指定惯性传感器的端口号（如 "PORT1"，而非简单的 "1"）：
  PORT3,

  // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
  // 输入车轮直径（4" 的车轮实际上更接近 4.125"）：
  4.125,

  // External ratio, must be in decimal, in the format of input teeth/output teeth.
  // If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
  // If the motor drives the wheel directly, this value is 1:
  // 外部比率，必须为十进制，格式为输入齿数/输出齿数。
  // 如果电机的齿轮为 84 齿，车轮的齿轮为 60 齿，则该值为 1.4。
  // 如果电机直接驱动车轮，该值为 1：
  0.42,

  // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
  // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
  // 陀螺仪刻度，这是机器人旋转 360 度时陀螺仪的读数。
  // 在大多数情况下，360 在这里就可以了，但在需要精确度时，这个比例系数会非常有用。
  360,

  /*---------------------------------------------------------------------------*/ /*-----------------------------------------------------*/
  /*                                  PAUSE!                                   */ /*                        PAUSE!                       */
  /*                                                                           */ /*                                                     */
  /*  The rest of the drive constructor is for robots using POSITION TRACKING. */ /*  驱动构造函数的其余部分适用于使用位置跟踪功能的机器人。  */
  /*  If you are not using position tracking, leave the rest of the values as  */ /*  如果不使用位置跟踪，其余值保持不变。                  */
  /*  they are.                                                                */ /*-----------------------------------------------------*/
  /*---------------------------------------------------------------------------*/

  // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.
  // 如果使用 ZERO_TRACKER_ODOM，则只需调整前向跟踪器中心距（FORWARD TRACKER CENTER DISTANCE）。

  // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
  // 仅适用于 HOLDNOMIC 驱动器： 按位置输入驱动电机。只有整体式驱动装置才需要这样做，否则这部分内容可以不写。
  //LF:      //RF:    
  PORT1,     -PORT2,

  //LB:      //RB: 
  PORT3,     -PORT4,

  // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
  // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
  // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
  // 如果使用的是位置跟踪，则为正向跟踪器端口（与底盘方向平行的跟踪器）。
  // 如果是旋转传感器，则以 "PORT1 "格式输入，并在下面输入端口。
  // 如果是编码器，则输入整数端口。Triport A 将是 "1", Triport B 将是 "2"，以此类推。
  3,

  // Input the Forward Tracker diameter (reverse it to make the direction switch):
  // 输入正向跟踪器直径（反向可切换方向）：
  2.75,

  // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
  // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
  // This distance is in inches:
  // 输入正向跟踪器中心距离（正距离对应机器人右侧的跟踪器，负距离对应机器人左侧的跟踪器）。
  // 如果是零跟踪器坦克驱动，则输入机器人中心到驱动右侧的正距离。
  // 该距离以英寸为单位：
  -2,

  // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
  // 按照与正向跟踪器端口相同的步骤输入侧向跟踪器端口：
  1,

  // Sideways tracker diameter (reverse to make the direction switch):
  // 侧向跟踪器直径（反向切换方向）：
  2.75,

  // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
  // 侧向跟踪器中心距离（正距离在机器人中心后方，负距离在前方）：
  5.5

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Turn Test");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Full Test");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  ArmG.setVelocity(100, pct);
  RingG.setVelocity(100, pct);
  LG.setStopping(brake);
  RG.setStopping(brake);
  ProjG.setStopping(hold);
  ArmG.setStopping(hold);
  RingG.setStopping(brake);  
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      Left1();  //在這揀編程     //This is the default auton, if you don't select from the brain.
      break;                    //Change these to be your own auton functions in order to use the auton selector.
    case 1:                     //Tap the screen to cycle through autons.
      Left1();
      break;
    case 2:
      Left2();
      break;
    case 3:
      Right1();
      break;
    case 4:
      Right2();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

void left_drive(int vel){
  //printf("left_drive\n");
  vel *= 120;
  LG.spin(reverse, vel, voltageUnits::mV);
}

void right_drive(int vel){
  //printf("right_drive\n");
  vel *= 120;
  RG.spin(reverse, vel, voltageUnits::mV);
}

bool RemoteControlCodeEnabled = true; // 启用遥控
bool DrivetrainLNeedsToBeStopped_Controller1 = true; // 左传动系统是否需停止运行
bool DrivetrainRNeedsToBeStopped_Controller1 = true; // 右传动系统是否需停止运行

// define a task that will handle monitoring inputs from Controller1
// 定义一个任务，处理来自 Controller1 的监控输入 || 遥控自动循环功能控制器
// 此处 电机给电压 = 控制器操纵杆轴位置(-100 ~ 100) * 120 
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  // 每 20 毫秒处理一次控制器输入
  // 根据输入值更新电机
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // 根据控制器操纵杆轴线计算传动系统电机速度
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed  = -Controller1.Axis3.position() - Controller1.Axis1.position();
      int drivetrainRightSideSpeed = -Controller1.Axis3.position() + Controller1.Axis1.position();
      
      // check if the value is inside of the deadband range
      // 检查数值是否在死区范围内
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        // 检查左侧电机是否已经停止
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          // 停止左驱动电机
          LG.stop();
          // tell the code that the left motor has been stopped
          // 修改外部用于判断的定义变量
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        // 重置切换开关，以便死区代码知道下次输入处于死区范围时左电机将停止运行
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // 右侧同左侧
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          RG.stop();
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      // 只有当数值不在死区范围内时，才告诉左驱动电机旋转
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        //LG.setVelocity(drivetrainLeftSideSpeed, percent);
        //LG.spin(forward);
        left_drive(drivetrainLeftSideSpeed);
      }
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        //RG.setVelocity(drivetrainRightSideSpeed, percent);
        //RG.spin(forward);
        right_drive(drivetrainRightSideSpeed);
      }
    }
    // wait before repeating the process
    // 间隔 20ms 后循环处理
    wait(20, msec);
  }
  return 0;
}

int AutoShoot2(){
  //wait(0.1, sec);
  Proj1.setVelocity(100, pct);
  Proj1.spinFor(forward, 300, degrees, false);
  wait(0.35, sec);
  Proj1.spinFor(forward, 300, degrees, false);
  return 0;
}

int Shootaaa (){
  while(true){
    ProjG.spin(forward, 100*110, voltageUnits::mV);
    if(Shoot.pressing()){
      ProjG.stop();
      break;
    }
  }
  return 0;
}

/*---------------------------------------------------------------------------*/ /*--------------------------------------------------*/
/*                                                                           */ /*                                                  */
/*                              User Control Task                            */ /*                       手 动                      */
/*                                                                           */ /*                                                  */
/*  This task is used to control your robot during the user control phase of */ /*  该任务用于在 VEX 竞赛的用户控制阶段控制您的机器人。 */
/*  a VEX Competition.                                                       */ /*  您必须修改代码，在此处添加自己的机器人专用命令。    */
/*                                                                           */ /*--------------------------------------------------*/
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
   /* 各电机组停止模式初始化 | coast(滑行) | brake(制动) | hold(制动并保持位置) */
  int MV = 110;
  LG.setStopping(coast);
  RG.setStopping(coast);
  ProjG.setStopping(hold);
  ArmG.setStopping(hold);
  RingG.setStopping(brake);  
  Brain.Timer.reset();
  //RingSen1.setLightPower(100);
  
  while(true){
    ////////////////////////////////////////////////////////////////////////////////////////
    // ======================================= NBT ====================================== //
    //int a = Shoot.pressing();

    //printf("%i\n", a);
    //LG.spin(fwd, Controller1.Axis3.position(pct)*MV, voltageUnits::mV); RG.spin(fwd, Controller1.Axis2.position(pct)*MV, voltageUnits::mV);//Tank
    task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);//遙控車

    if(Controller1.ButtonLeft.pressing()) {
      ProjG.spinFor(forward, 100, degrees, false);
      wait(0.3, sec);
      BS = 1;
      ProjG.spin(forward, 100, pct);      
    } else if (Controller1.ButtonUp.pressing()) {
      task aa = task(Shootaa);
    } else if (Controller1.ButtonRight.pressing()) {
      ON = false;
      ProjG.stop();
    } if (BS == 1 and Shoot.pressing()) { // Shoot.pressing - 判断限位开关是否被按下
      ProjG.stop();
      BS = 0;
    }

    if(Controller1.ButtonR1.pressing()){
      ArmG.spin(fwd, 100*MV, voltageUnits::mV);
    }
    else if(Controller1.ButtonL1.pressing() and ArmG.position(deg) >= 70){
      
      ArmG.spin(reverse, 100*MV, voltageUnits::mV);
    }
    else if (Controller1.ButtonL2.pressing()) {
      ArmG.resetPosition();
      ArmG.spin(reverse, 100*MV, voltageUnits::mV);
    }
    else{
      ArmG.stop();
    }

    if(Controller1.ButtonL1.pressing()){
      RingG.spin(fwd, 70*MV, voltageUnits::mV);
    }
    else if(Controller1.ButtonR1.pressing()){
      RingG.spin(reverse, 70*MV, voltageUnits::mV);
    }
    else if(Controller1.ButtonR2.pressing()){
      //RingG.spin(reverse, 100*MV, voltageUnits::mV);
    }
    else{
      RingG.stop();
    }

    if(Controller1.ButtonA.pressing()){
      LG.setStopping(hold);
      RG.setStopping(hold); 
    }
    else if (Controller1.ButtonB.pressing()){
      LG.setStopping(coast);
      RG.setStopping(coast);
    }

    /*if(Controller1.ButtonR1.pressing()){
      ProjG.setVelocity(100, pct);
      ProjG.spinFor(forward, 300, degrees, false);
      wait(0.35, sec);
      BoolShoot = true;
      ProjG.spin(forward, 100, pct);
    }
    if(BoolShoot == true and Shoot.pressing()){
      ProjG.stop();
      BoolShoot = false;
    }
    if(Controller1.ButtonR2.pressing()){
      ProjG.stop(); 
    }//*/
    

   
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
