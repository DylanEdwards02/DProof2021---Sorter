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

//This function allows us to cycle the balls that are in the goal to reaarange them in to an order that benefits us the most.
//It is a simple if else statement that waits for button L1 to be pressed.
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

//Ball Sensing Variables
float DistanceValue = 30;
int OpticalRedValue = 30;
int OpticalBlueValue = 0;
int OpticalBallValue = 0;
//This function utilizes the ball sensing variables to sense when the ball enters certain spots on out bot. This is mainly
//used when fielding balls on the field as this automatically puts two balls in predetermined positions.
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

//These are extra buttons that we use to complete certain functions.
void Buttons()
{
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) //Allows use to run the intakes backwards and seperate our intakes.
    {
     setIntake(-127);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) //This allows us to run only the front roller system backwards.
    {
     setFront(-50);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) //This allows us to kick balls out of the back of the bot by
    {                                                              //reversing the back roller.
     setFront(50);
     setBack(-127);
    }
    else
    {
    }
}



//Auton Functions

//This is a function that is similar to the op control cycle function that allows us to run the function as a seperate task.
//While the drive is moving, essentially multitasking.
void CycleAuto(void*)
{
  if(1==1)
  {
    setIntake(127);
    setFront(127);
    setBack(127);
  }
  else
  {
    setIntake(0);
    setBack(0);
    setFront(0);
  }
}

//Variables for the IntakeAuton function
bool AutonIntakeEnable;
bool ActionFlag;

//This function allows us to run the intakes while the drive is moving.
void IntakeAuton()
{
  if(AutonIntakeEnable == true)
  {
    if(ActionFlag == true)
    {
      setIntakeVolt(-12000);
    }
    else
    {
      setIntakeVolt(10000);
    }
  }
}
