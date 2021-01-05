#include "main.h"

void ProofRunFast(void*)
{
  DriveLeftBack.move_velocity(200);
  DriveRightBack.move_velocity(200);
  delay(1000);
  DriveRightBack.move_velocity(0);
  DriveLeftBack.move_velocity(0);
}

void AutonTest()
{
  setTargetMove(36.0);
  while(InPosition==false)
  {
    delay(10);
  }
  pros::lcd::print(6, "Done");
}
