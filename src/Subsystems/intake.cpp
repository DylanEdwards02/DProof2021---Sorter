#include "main.h"

//HelperFunctions

//Intake Functions
void setIntake (int IntakePower) //Motor percentage
{
  intakeL = IntakePower;
  intakeR = IntakePower;
}
void setIntakeVolt (int IntakeVolt) //Motor voltage
{
  intakeL.move_voltage(IntakeVolt);
  intakeR.move_voltage(IntakeVolt);
}

//Back Roller Function
void setBack (int BackRollerPower) //Motor percentage
{
  backRoller = BackRollerPower;
}
void setBackVolt (int BackRollerVolt) //Motor voltage
{
  backRoller.move_voltage(BackRollerVolt);
}

//Front Rollers Function
void setFront(int FrontRollerPower) //Motor percentage
{
  frontRollers = FrontRollerPower;
}
void setFrontVolt(int FrontRollerVolt) //Motor voltage
{
  frontRollers.move_voltage(FrontRollerVolt);
}

//Opcontrol Functions
void Cycle()
{
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    setIntakeVolt(12000);
    setFrontVolt(12000);
    setBackVolt(12000);
    //pros::lcd::set_text(2, "FLAG");
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
    if(pros::c::distance_get(8) < DistanceValue) //Top ball in
    {
    setIntake(127);
    setFront(30);
    setBack(-30);
    }
    else
    {
    setIntake(127);
    setFront(60);
    setBack(10);
    }
    delay(10);
  }
}

void Buttons()
{
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
     setIntake(-127);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
     setFront(-50);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
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
    }
  }
}
