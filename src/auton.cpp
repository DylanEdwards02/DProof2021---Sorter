#include "main.h"

void ProofRunFast()
{
  DriveLeftBack.move_velocity(200);
  DriveRightBack.move_velocity(200);
  delay(1000);
  DriveRightBack.move_velocity(0);
  DriveLeftBack.move_velocity(0);
}

void AutonTest()
{
  setTargetMove(13.0, 0.0);
  while(InPosition==false)
  {
  }
  pros::lcd::print(6, "Done");
  // setTargetTurn(90.0);
  // while(InPosition==false)
  // {
  // }
}
