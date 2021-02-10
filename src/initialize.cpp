#include "main.h"


void MotorInitialize()
{
  pros::lcd::initialize();
  DriveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  DriveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  DriveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  DriveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  intakeR.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  intakeL.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  frontRollers.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  /*
  Gyro.reset();
  while(Gyro.is_calibrating())
  {
    delay(10);
  }
  */
  //Bump Switches Defined Here
  /*
  pros::ADIDigitalIn switchTop ('A');
  pros::ADIDigitalIn switchBottom ('B');
  pros::ADIDigitalIn AutoUP ('C');
  pros::ADIDigitalIn AutoDOWN ('D');
  */
  //pros::lcd::register_btn1_cb(lcd_center_button);
  //pros::lcd::register_btn0_cb(lcd_left_button);
  //pros::lcd::register_btn2_cb(lcd_right_button);
  //autonselector();
}
