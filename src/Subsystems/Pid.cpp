#include "main.h"


//Local Variables
int TargetMove;
int MoveTarget;
int TargetTurnL;
int TargetTurnR;
int TypeMove = 0;
bool InPosition;
int counter;
int Timeout;
bool taskStarted;
int yaw;
float straighteningVar;
float TargetGyro;

//This function allows us to convert inches to ticks which is then utilized by our movement function.
int InchtoTicks(float inches)
{
	return(inches * 542.16)/(3.14 * 3.25);
}
//This function allows us to convert degrees to ticks which is then utilized by our movement function.
int DegstoTicksL(float degrees)
{
	return(((degrees/360)*(1.08*3.14)* (542.16))*0.98);
}
//Seperate function for right side of the drive as they move the opposite direction of the left to make a turn.
int DegstoTicksR(float degrees)
{
	return-(((degrees/360)*(1.08*3.14)* (542.16))*0.98);
}

int GlobalTime = pros::millis();

//Function that is called to set the target value of the PID to move the bot forwards and backwards.
void setTargetMove(float inches)
{
	//set motor encoders to 0
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	MoveTarget = InchtoTicks(inches);
	//Converts from inches to ticks
	taskStarted = false;
	InPosition = false;
	counter = 0;
	TypeMove = 0;
	TargetGyro = Gyro.get_heading();
	int StartTime = GlobalTime;
	//Clear Timer
	Timeout = ((fabsf(inches) / 15.0) * 1000) + 1000 + StartTime;
}


//Function that is called to set the target value of the PID to make turns.
void setTargetTurn(float degrees)
{
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	//double TargetTurnMaster = degrees + Gyro.get_rotation();

	//TargetTurnL = TargetTurnMaster;
	//TargetTurnR = -TargetTurnMaster;
	TargetTurnL= DegstoTicksL(degrees);
	TargetTurnR= DegstoTicksR(degrees);
	InPosition = false;
	counter = 0;
	TypeMove = 1;
}

float ActionTarget[2];
void setActionTarget(float ActionTargetInches1, float ActionTargetInches2)
{
	ActionTarget[0] = InchtoTicks(ActionTargetInches1);
	ActionTarget[1] = InchtoTicks(ActionTargetInches2);
}

// double getIMURotation
// {
// 	return Imu.get_rotation();
// }

const int accel_step = 500;
const int deccel_step = 11000;
static int leftSpeed = 0;
static int rightSpeed = 0;

void leftSlew(int leftTarget)
{
	int step;

	if(abs(leftSpeed) < abs(leftTarget))
	{
		step = accel_step;
	}
	else
	{
		step = deccel_step;
	}
	if(leftTarget > leftSpeed + step)
	{
		leftSpeed += step;
	}
	else if(leftTarget < leftSpeed - step)
	{
		leftSpeed -= step;
	}
	else
	{
		leftSpeed = leftTarget;
	}

	DriveLeftBack.move_voltage(leftSpeed);
	DriveLeftFront.move_voltage(leftSpeed);
}
void rightSlew(int rightTarget)
{
	int step;

	if(abs(rightSpeed) < abs(rightTarget))
	{
		step = accel_step;
	}
	else
	{
		step = deccel_step;
	}
	if(rightTarget > rightSpeed + step)
	{
		rightSpeed += step;
	}
	else if(rightTarget < rightSpeed - step)
	{
		rightSpeed -= step;
	}
	else
	{
		rightSpeed = rightTarget;
	}

	DriveRightBack.move_voltage(rightSpeed);
	DriveRightFront.move_voltage(rightSpeed);
}
void MovePID(void*)
{
	float PGain = 29;
	float PGainTurn = 25; //150
	float LMError;
	float last_LMError;
	float RMError;
	float last_RMError;
	float RFValue;
	float LFValue;
	float RIError;
	float LIError;
	float IGain = 0;
	float IGainTurn = 2;
	float DGain = 25;
	float DGainTurn = 0.5;
	float DRError;
	float DLError;
	float angleError;
	float Var;
	int Dir;
	float curAngle;
	float CorrectedLFValue;
	float CorrectedRFValue;
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	//Gyro.reset();
	//delay(2000);
	float Tolerance = InchtoTicks(2);
	float ToleranceTurnL = DegstoTicksL(3);
	float ToleranceTurnR = DegstoTicksR(3);
	float ToleranceIMU = 1.5;
	int IntergralZone = InchtoTicks(3);
	int IntergralZoneTurnL = DegstoTicksL(7);
	int IntergralZoneTurnR = DegstoTicksR(7);
	//int IntergralZoneTurnL = 5;
	//int IntergralZoneTurnR = 5;
  extern bool ActionFlag;
	extern bool PIDStop;
	//int RampDist = InchtoTicks(9);
	//int Accel = 500;
	int VoltCap = 11000;
	int VoltCapTurn = 8000;

	while(true)
	{
		while(PIDStop == true)
		{
			delay(15);
		}
		if(TypeMove == 0)
		{

			int yaw = 0;

			if (DriveRightFront.get_position()> (ActionTarget[0] - InchtoTicks(10)) && DriveRightFront.get_position() < (ActionTarget[0]+ InchtoTicks(2)))
			{
				ActionFlag = true;
				pros::lcd::print(5, "FlagTrue");
			}
			else if (DriveRightFront.get_position()> (ActionTarget[1] - InchtoTicks(10)) && DriveRightFront.get_position() < (ActionTarget[1]+ InchtoTicks(2)))
			{
				ActionFlag = true;
				pros::lcd::print(6, "FlagNUMBER2");
			}
			else
			{
				ActionFlag = false;

			}
			LMError = MoveTarget - DriveLeftBack.get_position();
			if((MoveTarget - DriveLeftBack.get_position()) < 0)
			{
				// Passed destination
				LIError = 0;
			}

			if (fabsf(LMError) < IntergralZone)
			{
				LIError = (LIError + LMError);
			}
			else
			{
				LIError = 0;
			}

			DLError = last_LMError - LMError;
			last_LMError = LMError;

			LFValue = (LMError * PGain) + (LIError * IGain) + (DLError * DGain);
			LFValue = (LFValue * .30);
			 if(LFValue > VoltCap)
			 {
			 	LFValue = VoltCap;
			 }
			 if(LFValue < -(VoltCap))
			 {
				 LFValue = -(VoltCap);
			 }
			 //straighteningVar = target - current;
			//LFValue = (PIDValLeft)
			 //Finds the P value
			//motor[dLeft] = LFValue;

			//DriveLeftBack.move_voltage(LFValue);
			//DriveLeftFront.move_voltage(LFValue);

			RMError = MoveTarget - DriveRightBack.get_position();

			// if((last_RMError * RMError) < 0)
			// {
			// 	// Passed destination
			// 	RIError = 0;
			// }

			if (fabsf(RMError) < IntergralZone)
			{
				RIError = (RIError + RMError);
			}
			else
			{
				RIError = 0;
			}

			DRError = last_RMError - RMError;
			last_RMError = RMError;

			RFValue = (RMError * PGain) + (RIError * IGain) + (DRError * DGain); //Determines Power Given to the motors
			RFValue = (RFValue * .30);
			 if(RFValue > VoltCap)
			 {
			 	RFValue = VoltCap;
			 }
			 if(RFValue < -(VoltCap))
			 {
				 RFValue = -(VoltCap);
			 }
			 pros::lcd::print(1, "Power: %f", RFValue);
			 pros::lcd::print(2, "PowerL: %f", LFValue);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));
			 curAngle = Gyro.get_heading();
			 angleError = (0 - curAngle);
			 pros::lcd::print(3, "Angle: %f", curAngle);
			 if(LFValue > 0)
			 {
				 Dir = 1;
			 }
			 else
			 {
				 Dir = -1;
			 }
			 if(angleError > 0.5)
			 {
				 CorrectedRFValue = (RFValue + (-10 * Dir * angleError));
				 CorrectedLFValue = LFValue;
			 }
			 else if(angleError < -0.5)
			 {
				 CorrectedLFValue = (LFValue + (-10 * Dir * angleError));
				 CorrectedRFValue = RFValue;
			 }
			 else
			 {
				 CorrectedLFValue = LFValue;
				 CorrectedRFValue = RFValue;
			 }
		  // Var = angleError * 100;
			// if(StraightR < 0)
			// {
			// 	StraightR = 0;
			// }
			// if (StraightL < 0)
			// {
			// 	StraightL = 0;
			// }
			//
			// LFValue = (LFValue - Var);
			// RFValue = (RFValue - Var);

			// if(LFValue > 0)
			// {
			// 	//Correct
			// }

		  //Kicks into Slew Controller
			 //leftSlew(CorrectedLFValue);
			 //rightSlew(CorrectedRFValue);
			 leftSlew(LFValue);
			 rightSlew(RFValue);

			if (((fabs(LMError)) < Tolerance) && ((fabs(RMError)) < Tolerance))
			{
				counter = counter + 1;
			}
			else
			{
				counter = 0;
			}

//Exiting the Loop or the movement is complete

		if (counter > 50)
		{
			InPosition = true;
		}
		else if(GlobalTime > Timeout) //Time Out Option *need to learn timers*
		{
		counter = 41;
		}
		else
		{
			//pros::lcd::print(3, "counter: %d", counter);
		}
	}


	if(TypeMove == 1)
	{


		LMError = TargetTurnL - DriveLeftBack.get_position(); //Finds how far off the target we are
		pros::lcd::print(4, "LMError: %f", LMError);
		pros::lcd::print(5, "RMError: %f", RMError);

		if (fabsf(LMError) < IntergralZoneTurnL)
		{
			if (LMError < 0)
			{
				LIError = (LIError + LMError);
			}
			else
			{
				LIError = (LMError - LIError);
			}
		}
		else
		{
			LIError = 0;
		}

		DLError = LMError - last_LMError;
		last_LMError = LMError;

		LFValue = (LMError * PGainTurn) + (LIError * IGainTurn) + (DLError * DGainTurn); //Finds the power value
		if(LFValue > VoltCapTurn)
		{
		 LFValue = VoltCapTurn;
		}
		if(LFValue < -(VoltCapTurn))
		{
			LFValue = -(VoltCapTurn);
		}

		//DriveLeftBack.move_voltage(LFValue);
		//DriveLeftFront.move_voltage(LFValue);

		RMError = TargetTurnR - DriveRightBack.get_position();
		if (fabsf(RMError) < IntergralZoneTurnR)
		{
			if (RMError > 0)
			{
			RIError =  (RIError - RMError);
			}
			else
			{
			RIError = (RIError + RMError);
			}
		}
		else
		{
			LIError = 0;
		}

		DRError = RMError - last_RMError;
		last_RMError = RMError;
		RFValue = (RMError * PGainTurn) + (RIError * IGainTurn) + (DRError * DGainTurn);

		if(RFValue > VoltCapTurn)
		{
		 RFValue = VoltCapTurn;
		}
		if(RFValue < -(VoltCapTurn))
		{
			RFValue = -(VoltCapTurn);
		}

		pros::lcd::print(3, "RPower: %f", RFValue);
		leftSlew(LFValue);
		rightSlew(RFValue);
		//DriveRightBack.move_voltage(RFValue);
		//DriveRightFront.move_voltage(RFValue);
		if (((fabs(LMError)) < ToleranceTurnL) && ((fabs(RMError)) < ToleranceTurnL))
		{
			counter = counter + 1;
		}
		else
		{
			counter = 0;
		}
		if (counter > 50)
		{
			InPosition = true;
		}

	}

	pros::delay(10);

}
}
