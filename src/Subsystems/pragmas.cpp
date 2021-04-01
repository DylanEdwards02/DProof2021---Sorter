#include "main.h"

//Intake Motors
pros::Motor intakeL(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); //Dont Know as of 12/2
pros::Motor intakeR(9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); //Dont Know as of 12/2
pros::Motor frontRollers(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS); //NEED to change to Bottom Rollers
pros::Motor backRoller(15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); //NEED to change to TopRollers

//Drive Motors
pros::Motor DriveRightBack(20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); //Should be 20
pros::Motor DriveRightFront(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DriveLeftBack(19, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); //Should be 19
pros::Motor DriveLeftFront(14, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);

//OLD PRAGMAS
// pros::Motor intakeL(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor intakeR(10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor flywheel(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor uptake(7, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor DriveRightBack(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor DriveRightFront(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor DriveLeftBack(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor DriveLeftFront(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//************************************
//Sensors
//************************************

//Optical Sensors
pros::Optical TopOptical (5);
pros::Optical LowerOptical (7);
pros::Distance TopDistance (8);

//Rotation Sensors
//pros::Rotation DREncoder (16); Currently not in use
//pros::Rotation DLEncoder (11); Currently not in use
//pros::Rotation DBEncoder (8); Currently not in use

//Line Followers
//pros::ADILineSensor LineSensorTop('A'); Currently not in use
//pros::ADILineSensor LineSensorMiddle('B'); Currently not in use

//Bump Switches
//pros::ADIDigitalIn button ('A');
