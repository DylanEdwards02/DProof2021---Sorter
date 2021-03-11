#include "main.h"

void ProofRunFast()
{
  frontRollers.move_voltage(10000);
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  delay(500);
  frontRollers.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  setTargetTurn(20);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  frontRollers.move_voltage(5000);
  setTargetMove(51, 20);
  while(InPosition == false)
  {
    delay(10);
  }
  frontRollers.move_voltage(0);
  setTargetMove(-17, 20);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  setTargetTurn(-45);
  while(InPosition == false)
  {
    delay(10);
  }
  setTargetMove(22, -45);
  while(InPosition == false)
  {
    delay(10);
  }
  PIDStop = true;
  DriveForTime(750);
    frontRollers.move_voltage(10000);
    backRoller.move_voltage(10000);
    intakeL.move_voltage(10000);
    intakeR.move_voltage(10000);
    delay(750);
    frontRollers.move_voltage(0);
    backRoller.move_voltage(0);
    intakeL.move_voltage(0);
    intakeR.move_voltage(0);
  PIDStop = false;
  KickoutFWD();
  setTargetMove(-50, -45);
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
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  setTargetMove(42.75, -180);
  while(InPosition == false)
  {
    delay(10);
  }

  setTargetTurn(-135);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  setTargetMove(50, -135);
  while(InPosition == false)
  {
    delay(10);
  }
  PIDStop = true;
  DriveForTime(1000);
  frontRollers.move_voltage(10000);
  backRoller.move_voltage(10000);
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  delay(750);
  frontRollers.move_voltage(0);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  PIDStop = false;
  KickoutFWD();
  setTargetMove(-48, -135);
  while(InPosition == false)
  {
    delay(10);
  }
  Stop();
  setTargetTurn(-270);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  setTargetMove(26, -270);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  setTargetTurn(-180);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  frontRollers.move_voltage(5000);
  setTargetMove(32,-180);
  while(InPosition == false)
  {
    delay(10);
  }
  PIDStop = true;
  DriveForTime(600);
  frontRollers.move_voltage(10000);
  backRoller.move_voltage(10000);
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  delay(500);
  frontRollers.move_voltage(0);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  PIDStop = false;
  KickoutFWD();
  setTargetMove(-21, -180);
  while(InPosition == false)
  {
    delay(10);
  }
  Stop();
  setTargetTurn(-270);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  frontRollers.move_voltage(8000);
  setTargetMove(48, -270);
  while(InPosition == false)
  {
    delay(10);
  }
  setTargetMove(-14, -270);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  frontRollers.move_voltage(0);
  setTargetTurn(-225);
  while(InPosition == false)
  {
    delay(10);
  }
  setTargetMove(32, -225);
  while(InPosition == false)
  {
    delay(10);
  }
  PIDStop = true;
  DriveForTime(1000);
  frontRollers.move_voltage(10000);
  backRoller.move_voltage(10000);
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  delay(750);
  frontRollers.move_voltage(0);
  backRoller.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  PIDStop = false;
  KickoutFWD();
  setTargetMove(-45, -225);
  while(InPosition == false)
  {
    delay(10);
  }
  Stop();
  setTargetTurn(-360);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  frontRollers.move_voltage(4000);
  setTargetMove(27, -360);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  frontRollers.move_voltage(0);
  setTargetTurn(-450);
  while(InPosition == false)
  {
    delay(10);
  }

  PIDStop = true;
  intakeL.move_voltage(-8000);
  intakeR.move_voltage(-8000);
  DriveForTime(2500);
  Square();
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  delay(200);
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  delay(500);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  frontRollers.move_voltage(10000);
  backRoller.move_voltage(10000);
  delay(500);
  backRoller.move_voltage(-10000);
  frontRollers.move_voltage(6000);
  intakeL.move_voltage(10000);
  intakeR.move_voltage(10000);
  delay(1300);
  backRoller.move_voltage(0);
  frontRollers.move_voltage(0);
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);
  PIDStop = false;
  intakeL.move_voltage(-10000);
  intakeR.move_voltage(-10000);
  setTargetMove(-12, 450);
  while(InPosition == false)
  {
    delay(10);
  }
  intakeL.move_voltage(0);
  intakeR.move_voltage(0);

}

void AutonTest()
{
  //PIDStop = true;
  //DriveForTime(3000);
  setTargetMove(-50,0);
  while(InPosition == false)
  {
    delay(10);
  }
}
void Homerow()
  {
    //Deploy

    frontRollers.move_voltage(10000);
    intakeL.move_voltage(-10000);
    intakeR.move_voltage(-10000);
    delay(500);
    frontRollers.move_voltage(0);
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

    setTargetTurn(-180);
    while(InPosition == false)
    {
      delay(10);
    }

    setTargetMove(59, -180);
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

    delay(100);

    Stop();
  }
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
  // PIDStop = true;
  //
  // setTargetMove(-46,0);
  //
  // AutonIntakeEnable = true;
  // frontRollers.move_voltage(10000);
  // intakeL.move_voltage(-10000);
  // intakeR.move_voltage(-10000);
  // delay(600);
  // frontRollers.move_voltage(0);
  // intakeL.move_voltage(0);
  // intakeR.move_voltage(0);
  // delay(200);
  // PIDStop = false;
  //
  // setTargetTurn(10);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // setTargetMove(36,10);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // setTargetTurn(-45);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // intakeL.move_voltage(10000);
  // intakeR.move_voltage(10000);
  // frontRollers.move_voltage(6000);
  // setTargetMove(13.75,-45);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  // intakeL.move_voltage(0);
  // intakeR.move_voltage(0);
  // PIDStop = true;
  // DriveForTime(300);
  // frontRollers.move_voltage(10000);
  // backRoller.move_voltage(10000);
  // delay(1000);
  // frontRollers.move_voltage(0);
  // backRoller.move_voltage(0);
  // PIDStop = false;
  // setTargetMove(-50,-45);
  //
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  //
  // setTargetTurn(-123); //Turn to middle ball
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  // setTargetMove(27,0); //Straight to middle ball
  //
  // setTargetTurn(-10);
  //
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  //
  // setTargetTurn(45);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  // setTargetMove(50,0);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  // setTargetTurn(-45);
  //
  // setTargetMove(-15,0);
  // while(InPosition == false)
  // {
  //   delay(10);
  // }
  //
  //
  // // setTargetTurn(-40);
  //
  // PIDStop = true;
  // DriveBForTime(1000);
  // // setTargetTurn(-180);
  //
  // // while(InPosition == false)
  // // {
  // //   delay(10);
  // // }
  //
  // // setTargetMove(12);
  //
  // // frontRollers.move_voltage(10000);
  // // backRoller.move_voltage(10000);
  // // setTargetMove(92.5,-180);
  //
  // // while(InPosition == false)
  // // {
  // //   delay(10);
  // // }
  //
  // // setTargetTurn(40);
  //
  // // setTargetTurn(-135);
  //
  // // while(InPosition == false)
  // // {
  // //   delay(10);
  // // }
  //
  // // setTargetMove(31);
  // // while(InPosition == false)
  // // {
  // //   delay(10);
  // // }
  //
  // // PIDStop = false;
  // // DriveForTime(375);
  // // delay(1000);
  // // PIDStop = true;
  // //
  // //
  //
  // // intakeL.move_voltage(10000);
  // // intakeR.move_voltage(10000);
  // // frontRollers.move_voltage(10000);
  // // backRoller.move_voltage(10000);
  // // DriveForTime(2000);
  // // intakeL.move_voltage(0);
  // // intakeR.move_voltage(0);
  // // delay(1000);
  // // frontRollers.move_voltage(0);
  // // backRoller.move_voltage(0);

//
//
// void SkillsAuton()
// {
//   AutonIntakeEnable = true;
//   frontRollers.move_voltage(10000);
//   intakeL.move_voltage(-10000);
//   intakeR.move_voltage(-10000);
//   delay(700);
//   frontRollers.move_voltage(0);
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//   delay(200);
//   PIDStop = false;
//   //setActionTarget(12.0, 48.0);
//   setTargetMove(52); //Straight to Grab First two Balls
//   intakeL.move_voltage(10000);
//   intakeR.move_voltage(10000);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   frontRollers.move_voltage(5000);
//   setTargetMove(-15.5); //Back Away from Goal
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//   frontRollers.move_voltage(0);
//   setTargetTurn(-68); //Turn Towards Goal
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
//   setTargetMove(20); //Movement to Goal
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
//   PIDStop = true;
//   DriveForTime(100);
//   DriveLeftFront.move_voltage(2000);
//   DriveLeftBack.move_voltage(2000);
//   delay(200);
//   DriveLeftFront.move_voltage(0);
//   DriveLeftBack.move_voltage(0);
//   DriveRightFront.move_voltage(2000);
//   DriveRightBack.move_voltage(2000);
//   delay(200);
//   DriveRightFront.move_voltage(0);
//   DriveRightBack.move_voltage(0);
//
//   DriveRightFront.move_voltage(1000);
//   DriveLeftFront.move_voltage(2000);
//   DriveRightBack.move_voltage(1000);
//   DriveLeftBack.move_voltage(2000);
//   delay(200);
//   frontRollers.move_voltage(10000);
//   backRoller.move_voltage(10000);
//   intakeL.move_voltage(10000);
//   intakeR.move_voltage(10000);
//   delay(1250);
//   frontRollers.move_voltage(0);
//   backRoller.move_voltage(0);
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//   DriveRightFront.move_voltage(0);
//   DriveLeftFront.move_voltage(0);
//   DriveRightBack.move_voltage(0);
//   DriveLeftBack.move_voltage(0);
//
//   // //PART ONE
//   // //*************************************************************************************************
//   PIDStop = false;
//   intakeL.move_voltage(-10000);
//   intakeR.move_voltage(-10000);
//   frontRollers.move_voltage(-8000);
//   setTargetMove(-23);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//   frontRollers.move_voltage(0);
//   setTargetMove(-25);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   intakeL.move_voltage(10000);
//   intakeR.move_voltage(10000);
//   setTargetTurn(-123); //Turn to middle ball
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   setTargetMove(27); //Straight to middle ball
//   //setActionTarget(0,25.0);
//   while(InPosition == false)
//   {
//   //  IntakeAuton();
//     delay(10);
//   }
//   frontRollers.move_voltage(7000);
//   setTargetTurn(41);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   frontRollers.move_voltage(0);
//   setTargetMove(50);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
//   setTargetTurn(-80);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//   setTargetMove(11);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
//   setTargetTurn(86);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
//   setTargetMove(18);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//   PIDStop = true;
//   DriveForTime(100);
//   DriveLeftFront.move_voltage(2000);
//   DriveLeftBack.move_voltage(2000);
//   delay(200);
//   DriveLeftFront.move_voltage(0);
//   DriveLeftBack.move_voltage(0);
//   DriveRightFront.move_voltage(2000);
//   DriveRightBack.move_voltage(2000);
//   delay(200);
//   DriveRightFront.move_voltage(0);
//   DriveRightBack.move_voltage(0);
//
//   DriveRightFront.move_voltage(1000);
//   DriveLeftFront.move_voltage(2000);
//   DriveRightBack.move_voltage(1000);
//   DriveLeftBack.move_voltage(2000);
//   delay(200);
//   frontRollers.move_voltage(10000);
//   backRoller.move_voltage(10000);
//   intakeL.move_voltage(10000);
//   intakeR.move_voltage(10000);
//   delay(2000);
//   frontRollers.move_voltage(0);
//   backRoller.move_voltage(0);
//
//   DriveRightFront.move_voltage(0);
//   DriveLeftFront.move_voltage(0);
//   DriveRightBack.move_voltage(0);
//   DriveLeftBack.move_voltage(0);
//   //  //PART TWO
//   //  //*************************************************************************************************
//    PIDStop = false;
//    setTargetMove(-25);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//   intakeL.move_voltage(0);
//   intakeR.move_voltage(0);
//
//    setTargetMove(-27);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    setTargetTurn(-123); //Turn to middle ball
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    setTargetMove(26);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    frontRollers.move_voltage(6000);
//    setTargetTurn(83); //Turn to middle ball
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    frontRollers.move_voltage(0);
//    setTargetMove(31);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//
//    PIDStop = true;
//    DriveForTime(100);
//    DriveLeftFront.move_voltage(2000);
//    DriveLeftBack.move_voltage(2000);
//    delay(200);
//    DriveLeftFront.move_voltage(0);
//    DriveLeftBack.move_voltage(0);
//    DriveRightFront.move_voltage(2000);
//    DriveRightBack.move_voltage(2000);
//    delay(200);
//    DriveRightFront.move_voltage(0);
//    DriveRightBack.move_voltage(0);
//
//    DriveRightFront.move_voltage(1000);
//    DriveLeftFront.move_voltage(2000);
//    DriveRightBack.move_voltage(1000);
//    DriveLeftBack.move_voltage(2000);
//    delay(200);
//    frontRollers.move_voltage(10000);
//    backRoller.move_voltage(10000);
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    delay(500);
//    frontRollers.move_voltage(0);
//    backRoller.move_voltage(0);
//
//    DriveRightFront.move_voltage(0);
//    DriveLeftFront.move_voltage(0);
//    DriveRightBack.move_voltage(0);
//    DriveLeftBack.move_voltage(0);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//   //  //PART 3
//   //  //********************************************************************************
//    delay(200);
//    PIDStop = false;
//
//    setTargetMove(-22);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//
//    setTargetTurn(-87);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    setTargetMove(46);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//
//    setTargetMove(-10.5);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//    frontRollers.move_voltage(5000);
//    setTargetTurn(85);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//    frontRollers.move_voltage(0);
//    setTargetMove(28);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//
//    //WALL SQUARE
//    setTargetMove(-28);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//    setTargetTurn(-47);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//
//    setTargetMove(36);
//    while(InPosition == false)
//    {
//     delay(10);
//    }
//
//    PIDStop = true;
//    DriveForTime(100);
//    DriveLeftFront.move_voltage(2000);
//    DriveLeftBack.move_voltage(2000);
//    delay(200);
//    DriveLeftFront.move_voltage(0);
//    DriveLeftBack.move_voltage(0);
//    DriveRightFront.move_voltage(2000);
//    DriveRightBack.move_voltage(2000);
//    delay(200);
//    DriveRightFront.move_voltage(0);
//    DriveRightBack.move_voltage(0);
//
//    DriveRightFront.move_voltage(1000);
//    DriveLeftFront.move_voltage(2000);
//    DriveRightBack.move_voltage(1000);
//    DriveLeftBack.move_voltage(2000);
//    delay(200);
//    frontRollers.move_voltage(10000);
//    backRoller.move_voltage(10000);
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    delay(2000);
//    frontRollers.move_voltage(0);
//    backRoller.move_voltage(0);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//    DriveRightFront.move_voltage(0);
//    DriveLeftFront.move_voltage(0);
//    DriveRightBack.move_voltage(0);
//    DriveLeftBack.move_voltage(0);
//    //PART 4
//    //********************************************************************************
//    PIDStop = false;
//    setTargetMove(-24);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    setTargetMove(-24);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//
//    setTargetTurn(-125); //Turn to middle ball
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    setTargetMove(29); //Straight to middle ball
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    frontRollers.move_voltage(6000);
//    setTargetTurn(-85);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    frontRollers.move_voltage(0);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//    intakeL.move_voltage(-10000);
//    intakeR.move_voltage(-10000);
//    setTargetMove(12); //Straight to middle ball
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    PIDStop = true;
//    DriveRightFront.move_voltage(6000);
//    DriveLeftFront.move_voltage(6000);
//    DriveRightBack.move_voltage(6000);
//    DriveLeftBack.move_voltage(6000);
//    delay(750);
//    DriveRightFront.move_voltage(1000);
//    DriveLeftFront.move_voltage(1000);
//    DriveRightBack.move_voltage(1000);
//    DriveLeftBack.move_voltage(1000);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//    delay(200);
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    delay(500);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//    frontRollers.move_voltage(10000);
//    backRoller.move_voltage(10000);
//    delay(500);
//    backRoller.move_voltage(-10000);
//    frontRollers.move_voltage(6000);
//    intakeL.move_voltage(10000);
//    intakeR.move_voltage(10000);
//    delay(1300);
//    backRoller.move_voltage(0);
//    frontRollers.move_voltage(0);
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
//
//    PIDStop = false;
//    intakeL.move_voltage(-10000);
//    intakeR.move_voltage(-10000);
//    setTargetMove(-12);
//    while(InPosition == false)
//    {
//      delay(10);
//    }
//    intakeL.move_voltage(0);
//    intakeR.move_voltage(0);
// }
//
//
//
//
// void Square()
// {
//   setTargetMove(50);
//   while(InPosition == false)
//   {
//     delay(10);
//   }
//
// }
