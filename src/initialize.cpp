#include "main.h"
int max_case = 6;
int switchval;
std::string switchtext;

void lcd_left_button()
{
 static bool lpressed = false;
 lpressed = !lpressed;
 if (lpressed)
 {
   pros::lcd::clear_line(2);
   switchval--;
   if (switchval < 0)
   {
     switchval = max_case;
   }
   if (switchval == 0)
   {
     switchtext = "Deploy";
   }
   if (switchval == 1)
   {
     switchtext = "Homerow    -   Left";
   }
   if (switchval == 2)
   {
     switchtext = "Homerow    -   Right";
   }
   if (switchval == 3)
   {
     switchtext = "TwoPoint   -   Left";
   }
   if (switchval == 4)
   {
     switchtext = "TwoPoint   -   Right";
   }
   if (switchval == 5)
   {
     switchtext = "CenterAuton    -   Left";
   }
   if (switchval == 6)
   {
     switchtext = "Unassigned";
   }

   pros::lcd::set_text(2, std::to_string(switchval));
   pros::lcd::set_text(1, std::string(switchtext));
 }
 else
 {
 }
}
void lcd_right_button()
{
 static bool rpressed = false;
 rpressed = !rpressed;
 if (rpressed)
 {
   pros::lcd::clear_line(2);
   switchval++;
   if (switchval > max_case)
   {
     switchval = 0;
   }
   if (switchval == 0)
   {
     switchtext = "Deploy";
   }
   if (switchval == 1)
   {
     switchtext = "Homerow    -   Left";
   }
   if (switchval == 2)
   {
     switchtext = "Homerow    -   Right";
   }
   if (switchval == 3)
   {
     switchtext = "TwoPoint   -   Left";
   }
   if (switchval == 4)
   {
     switchtext = "TwoPoint   -   Right";
   }
   if (switchval == 5)
   {
     switchtext = "CenterAuton    -   Left";
   }
   if (switchval == 6)
   {
     switchtext = "Unassigned";
   }

   pros::lcd::set_text(2, std::to_string(switchval));
   pros::lcd::set_text(1, std::string(switchtext));
 }
 else
 {
 }
}

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
<<<<<<< Updated upstream
=======
  LowerOptical.set_led_pwm(85);
  Gyro.reset();
  while(Gyro.is_calibrating())
  {
    delay(10);
  }


>>>>>>> Stashed changes
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
