#include "main.h"

<<<<<<< Updated upstream
void ProofRunFast(void*)
=======
void ProofRunFast() //SkillsAuton
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream

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
=======
    backRoller.move_voltage(10000);
    intakeL.move_voltage(-10000);
    intakeR.move_voltage(-10000);
    delay(500);
    backRoller.move_voltage(0);
    intakeL.move_voltage(0);
    intakeR.move_voltage(0);

    PIDStop = false;

    setTargetMove(34, 45);
    while(InPosition == false)
    {
      delay(10);
    }

    setTargetTurn(-45);
    while(InPosition == false)
    {
      delay(10);
    }

    intakeL.move_voltage(11000);
    intakeR.move_voltage(11000);
    frontRollers.move_voltage(12000);
    backRoller.move_voltage(10500);

    setTargetMove(38, -45);
    while(InPosition == false)
    {
      delay(10);
    }
    intakeL.move_voltage(0);
    intakeR.move_voltage(0);
    delay(100);

    Stop();
    KickoutFWD();
    setTargetMove(-40, -45);
    while(InPosition == false)
    {
      delay(10);
    }
    Stop();
    setTargetTurn(-180);
    while(InPosition == false)
    {
      delay(10);
    }

    setTargetMove(66, -180);
    while(InPosition == false)
    {
      delay(10);
    }

    setTargetTurn(-135);
    while(InPosition == false)
    {
      delay(10);
    }

    intakeL.move_voltage(11000);
    intakeR.move_voltage(11000);
    frontRollers.move_voltage(12000);
    backRoller.move_voltage(10500);

    setTargetMove(45, -135);
    while(InPosition == false)
    {
      delay(10);
    }
    intakeL.move_voltage(0);
    intakeR.move_voltage(0);
    delay(100);

    Stop();
    setTargetMove(-4, -135);
    while(InPosition == false)
    {
      delay(10);
    }
  }

void TwoPointLeft()
{
  backRoller.move_voltage(10000);
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  delay(500);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);

  PIDStop = false;
  //Deploy
  //delay(100);
  setTargetMove(34, 45);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(-45);
  while(InPosition == false)
  {
    delay(10);
  }

  intakeL.move_voltage(11000);
  intakeR.move_voltage(11000);
  frontRollers.move_voltage(12000);
  backRoller.move_voltage(10500);

  setTargetMove(38, -45);
  while(InPosition == false)
  {
    delay(10);
  }

  delay(100);

  Stop();

  setTargetMove(-40, -45);
  while(InPosition == false)
  {
    delay(10);
  }
}

void TwoPointRight()
{
  backRoller.move_voltage(10000);
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  delay(500);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);

  PIDStop = false;
  //Deploy
  //delay(100);
  setTargetMove(34, 135);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(225);
  while(InPosition == false)
  {
    delay(10);
  }

  intakeL.move_voltage(11000);
  intakeR.move_voltage(11000);
  frontRollers.move_voltage(12000);
  backRoller.move_voltage(10500);

  setTargetMove(38, 225);
  while(InPosition == false)
  {
    delay(10);
  }

  delay(100);

  Stop();

  setTargetMove(-40, 225);
  while(InPosition == false)
  {
    delay(10);
  }
}

void HomerowRight()
{
  backRoller.move_voltage(10000);
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  delay(500);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);

  PIDStop = false;
  //Deploy
  //delay(100);
  setTargetMove(34, 135);
>>>>>>> Stashed changes
  while(InPosition == false)
  {
    delay(10);
  }

<<<<<<< Updated upstream
  setTargetTurn(-123); //Turn to middle ball
=======
  setTargetTurn(225);
>>>>>>> Stashed changes
  while(InPosition == false)
  {
    delay(10);
  }

<<<<<<< Updated upstream
  setTargetMove(27); //Straight to middle ball
=======
  intakeL.move_voltage(11000);
  intakeR.move_voltage(11000);
  frontRollers.move_voltage(12000);
  backRoller.move_voltage(10500);

  setTargetMove(38, 225);
>>>>>>> Stashed changes
  while(InPosition == false)
  {
    delay(10);
  }

<<<<<<< Updated upstream
  setTargetTurn(45);
=======
  setTargetMove(-40, 225);
>>>>>>> Stashed changes
  while(InPosition == false)
  {
    delay(10);
  }
<<<<<<< Updated upstream

  setTargetMove(50);
=======
  setTargetTurn(0);
  while(InPosition == false)
  {
  delay(10);
  }

  setTargetMove(59, 0);
>>>>>>> Stashed changes
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(-45);
  while(InPosition == false)
  {
    delay(10);
  }

<<<<<<< Updated upstream
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

=======
  intakeL.move_voltage(11000);
  intakeR.move_voltage(11000);
  frontRollers.move_voltage(12000);
  backRoller.move_voltage(10500);

  setTargetMove(45, -45);
  while(InPosition == false)
  {
    delay(10);
  }

  delay(100);

  Stop();
}

void Deploy()
{
  backRoller.move_voltage(10000);
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  delay(1500);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
}

void CenterAuton()
{
  //Kev put your center auton code here
  delay(10);
>>>>>>> Stashed changes
}
