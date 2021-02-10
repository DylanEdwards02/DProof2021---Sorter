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
  //Retrieves the values from the controller. More specifically, the left and right analog sticks. We later set use these values
  //Power the each side of the drive train via a tank drive configuration.

  //pros::lcd::print(4, "Left: %f/n", leftjoystickval);
  //pros::lcd::print(5, "Right: %f/n", rightjoystickval);
  //Prints for troubleshooting
  if(abs(leftjoystickval) < 10)
    {
      leftjoystickval = 0;
    }
  if(abs(rightjoystickval) < 10)
    {
      rightjoystickval = 0;
    }
  //These two if statements create a deadzone on the controller so that the motors aren't constantly in motion when driving.
  //Deadzones allow the analog sticks to have a bit of tolerance around the 0 value.

  float leftjoystick = (leftjoystickval^2/127)*100;
  float rightjoystick = (rightjoystickval^2/127)*100;
  //These statements are where we calculate the value that is passed into our motors via the stepper functions mentioned above.
  //We utilize exponential control as it allows for better control of the bot on the field. Along with exponential control, we
  //use voltage control on the drive motors to give us an edge on those who utilize velocity.

  setDriveVolt(leftjoystick, rightjoystick);
  //Assigns the drive values to the stepper function
}

//Auton Functions

void DriveForTime(int Time)
{
  DriveRightFront.move_voltage(9000);
  DriveLeftFront.move_voltage(9000);
  DriveRightBack.move_voltage(9000);
  DriveLeftBack.move_voltage(9000);
  delay(Time);
  DriveRightFront.move_voltage(0);
  DriveLeftFront.move_voltage(0);
  DriveRightBack.move_voltage(0);
  DriveLeftBack.move_voltage(0);
}

void SlowSquare()
{
  DriveRightFront.move_voltage(5000);
  DriveLeftFront.move_voltage(5000);
  DriveRightBack.move_voltage(5000);
  DriveLeftBack.move_voltage(5000);
  delay(700);
  DriveRightFront.move_voltage(0);
  DriveLeftFront.move_voltage(0);
  DriveRightBack.move_voltage(0);
  DriveLeftBack.move_voltage(0);
}
