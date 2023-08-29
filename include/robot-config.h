using namespace vex;

extern brain Brain;

using signature = vision::signature;

// NBT part
extern motor Proj1;
extern motor Proj2;
extern motor_group ProjG;
extern motor Ring1;
extern motor Ring2;
extern motor_group RingG;
extern motor Roller;
extern motor_group ArmG;
extern optical RollerSen;
extern limit Shoot;
extern vision VisionTop;
extern distance RingSen1;
extern distance FwdDistance;
extern distance BackDistance;
extern rotation Shoot2;
extern digital_out RingUD;
extern digital_out End1;
extern digital_out Power;

extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;

extern signature SIG_RED;
extern signature SIG_BLUE;
extern signature SIG_YELLOW;


// VEXcode devices
extern motor_group LG;
extern motor LGMotorA;
extern motor LGMotorB;
extern motor LAA;
extern motor LBB;
extern motor_group RG;
extern motor RGMotorA;
extern motor RGMotorB;
extern motor RAA;
extern motor RBB;
extern inertial Iner;
extern gps GPS;
extern signature fEye__SIG_1;
extern signature fEye__SIG_2;
extern signature fEye__SIG_3;
extern signature fEye__SIG_4;
extern signature fEye__SIG_5;
extern signature fEye__SIG_6;
extern signature fEye__SIG_7;
extern vision fEye;
extern motor_group Arm;
extern digital_out Tail;
extern digital_out Claw;
extern led BatteryLed;
extern led DriveLed;
extern led ArmLed;
extern signature cEye__SIG_1;
extern signature cEye__SIG_2;
extern signature cEye__SIG_3;
extern signature cEye__SIG_4;
extern signature cEye__SIG_5;
extern signature cEye__SIG_6;
extern signature cEye__SIG_7;
extern vision cEye;
extern rotation ArmSen;
extern distance ClawSen;
extern distance TailSen;
extern motor HighY;
extern motor Intake;
extern controller Controller1;
extern digital_out Sausage;

extern smartdrive Drivetrain;
extern inertial TurnGyroSmart;
extern drivetrain Drivetrainnogyro;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );