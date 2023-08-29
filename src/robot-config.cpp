#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
controller Controller1 = controller();
// NBT part
/*motor LGMotorA = motor(PORT13, ratio6_1, true);
motor LGMotorB = motor(PORT20, ratio6_1, true);
motor_group LG = motor_group(LGMotorA, LGMotorB);
motor RGMotorA = motor(PORT12, ratio6_1, false);
motor RGMotorB = motor(PORT19, ratio6_1, false);
motor_group RG = motor_group(RGMotorA, RGMotorB);*/

motor LGMotorA = motor(PORT11, ratio6_1, false);
motor LGMotorB = motor(PORT12, ratio6_1, false);
motor_group LG = motor_group(LGMotorA, LGMotorB);
motor RGMotorA = motor(PORT1, ratio6_1, true);
motor RGMotorB = motor(PORT2, ratio6_1, true);
motor_group RG = motor_group(RGMotorA, RGMotorB);

motor LAA = motor(PORT11, ratio6_1, true);
motor LBB = motor(PORT12, ratio6_1, true);
motor RAA = motor(PORT1, ratio6_1, false);
motor RBB = motor(PORT2, ratio6_1, false);

motor Proj1 = motor(PORT17, ratio36_1, true);
motor Proj2 = motor(PORT21, ratio36_1, false);
motor_group ProjG = motor_group(Proj1, Proj2);

motor Arm1 = motor(PORT6, ratio36_1, false);
motor Arm2 = motor(PORT7, ratio36_1, true);
motor_group ArmG = motor_group(Arm1, Arm2);

motor Ring1 = motor(PORT16, ratio6_1, true);
motor Ring2 = motor(PORT21, ratio6_1, false);
motor_group RingG = motor_group(Ring1, Ring2);

//inertial Iner = inertial(PORT13);
limit Shoot = limit(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
//bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}