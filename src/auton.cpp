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


void SkillsAuton()
{
  //AutonIntakeEnable = true;
  // frontRollers.move_voltage(10000);
  // intakeL.move_voltage(-10000);
  // intakeR.move_voltage(-10000);
  // delay(500);
  // frontRollers.move_voltage(0);
  // intakeL.move_voltage(0);
  // intakeR.move_voltage(0);
  // //setActionTarget(12.0, 40.0);
  // setTargetMove(52); //Straight to Grab First two Balls
  // while(InPosition == false)
  // {
  //   //IntakeAuton();
  //   delay(10);
  // }
  // //AutonIntakeEnable = false;
  // setTargetMove(-16); //Back Away from Goal
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // setTargetTurn(-70); //Turn Towards Goal
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  // setTargetMove(20); //Movement to Goal
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  // PIDStop = false;
  // DriveForTime(100);
  // delay(1000);
  PIDStop = true;

  setTargetMove(-46);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(-123); //Turn to middle ball
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetMove(27); //Straight to middle ball
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(45);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetMove(50);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(-45);
  while(InPosition == false)
  {
    delay(10);
  }

  // setTargetTurn(-40);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // setTargetMove(12);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // setTargetTurn(40);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }

  // setTargetMove(31);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }

  // PIDStop = false;
  // DriveForTime(375);
  // delay(1000);
  // PIDStop = true;
  //
  //

}
