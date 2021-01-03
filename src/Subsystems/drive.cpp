#include "main.h"


void setDrive (int leftpower, int rightpower)
{
  DriveLeftFront = leftpower;
  DriveLeftBack = leftpower;
  DriveRightFront = rightpower;
  DriveRightBack = rightpower;
}

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

  float leftjoystick = leftjoystickval^2/127;
  float rightjoystick = rightjoystickval^2/127;
  setDrive(leftjoystick, rightjoystick);
}
