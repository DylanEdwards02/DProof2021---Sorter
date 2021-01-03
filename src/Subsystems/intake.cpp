#include "main.h"

//HelperFunctions
void setIntake (int IntakePower)
{
  intakeL = IntakePower;
  intakeR = IntakePower;
}

void setBack (int BackRollerPower)
{
  backRoller = BackRollerPower;
}

void setFront(int FrontRollerPower)
{
  frontRollers = FrontRollerPower;
}

//Opcontrol Functions
void Cycle()
{
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    setIntake(127);
    setFront(127);
    setBack(127);
    pros::lcd::set_text(2, "FLAG");
  }
  else
  {
    setIntake(0);
    setBack(0);
    setFront(0);
  }
}

float DistanceValue = 30;
int OpticalRedValue = 30;
int OpticalBlueValue = 0;
int OpticalBallValue = 0;
void Indexing()
{
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
  {

    if(pros::c::distance_get(8) < DistanceValue)
    {
      setIntake(127);
      setFront(30);
      setBack(-30);
    }
    else if(pros::c::optical_get_hue(7) < OpticalBallValue)
    {
      setIntake(127);
      setFront(0);
      setBack(0);
    }
    else
    {
      setIntake(127);
      setFront(60);
      setBack(30);
    }
    delay(15);
  }
}

void Outtake()
{
   if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
   {
    setIntake(-127);
   }
   else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
   {
     setIntake(-50);
   }
   else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
   {
     setFront(-50);
   }
   else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B))
   {
     setFront(50);
     setBack(-127);
   }
   else
   {
   }
}

void Field()
{

}
//Auton Functions
void CycleAuto(void*)
{
  if(1==1)//controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    setIntake(127);
    setFront(127);
    setBack(127);
    pros::lcd::set_text(2, "FLAG");
  }
  else
  {
    setIntake(0);
    setBack(0);
    setFront(0);
  }
}

bool AutonIntakeEnable;
bool IntakeFlag;
void IntakeAuton()
{
  if(AutonIntakeEnable == true)
  {
    if(IntakeFlag == true)
    {
      setIntake(-127);
    }
    else
    {
      setIntake(120);
    }
  }
}
