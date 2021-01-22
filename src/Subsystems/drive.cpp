#include "main.h"

//HelperFunctions

//Drive Functions
void setDrive (int leftpower, int rightpower) //Motor percentage
{
  DriveLeftFront = leftpower;
  DriveLeftBack = leftpower;
  DriveRightFront = rightpower;
  DriveRightBack = rightpower;
  //Sets power to both the left and right sides. The function accepts two variables so you can set each side differently for
  //whatever type of motion you are trying to mimic.
}

void setDriveVolt (int leftVolt, int rightVolt) //Motor voltage
{
  DriveLeftFront.move_voltage(leftVolt);
  DriveLeftBack.move_voltage(leftVolt);
  DriveRightFront.move_voltage(rightVolt);
  DriveRightBack.move_voltage(rightVolt);
  //Same as setDrive but utilizing voltage instead of percentage. Voltage allows for higher speeds than percentage, although
  //the difference is small, it is noticable.
}


//OP Control Functions
void setDriveMotors ()
{
  int leftjoystickval = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightjoystickval = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  pros::lcd::print(4, "Left: %f/n", leftjoystickval);
  pros::lcd::print(5, "Right: %f/n", rightjoystickval);
  if(abs(leftjoystickval) < 10)
    {
      leftjoystickval = 0;
    }
  if(abs(rightjoystickval) < 10)
    {
      rightjoystickval = 0;
    }

  float leftjoystick = (leftjoystickval^2/127)*100;
  float rightjoystick = (rightjoystickval^2/127)*100;
  setDriveVolt(leftjoystick, rightjoystick);
}
