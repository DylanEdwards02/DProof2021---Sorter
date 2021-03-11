#include "main.h"


//Local Variables
int TargetMove;
int MoveTarget;
int TargetTurnL;
int TargetTurnR;
int TypeMove = 0;
float TargetGyro;
bool InPosition;
int counter;
int Timeout;
bool taskStarted;


//This function allows us to convert inches to ticks which is then utilized by our movement function.
int InchtoTicks(float inches)
{
	return(inches * 542.16)/(3.14 * 3.25);
}
//This function allows us to convert degrees to ticks which is then utilized by our movement function.
int DegstoTicksL(float degrees)
{
	return((degrees/360)*(1.08*3.14)* (542.16));
}
//Seperate function for right side of the drive as they move the opposite direction of the left to make a turn.
int DegstoTicksR(float degrees)
{
	return-((degrees/360)*(1.08*3.14)* (542.16));
}

//Function that is called to set the target value of the PID to move the bot forwards and backwards.
void setTargetMove(float inches, int Heading)
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
	TargetGyro = Heading;
	int StartTime = GlobalTime;
	//Clear Timer
	Timeout = ((fabsf(inches) / 15.0) * 1000) + 1000;
}


//Function that is called to set the target value of the PID to make turns.
void setTargetTurn(float heading)
{
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	//TargetTurnL= DegstoTicksL(degrees);
	//TargetTurnR= DegstoTicksR(degrees);

	TargetTurnL = heading;
	InPosition = false;
	counter = 0;
	TypeMove = 1;
}

const int accel_step = 500;
const int deccel_step = 12000;
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

float ActionTarget[2];
void setActionTarget(float ActionTargetInches1, float ActionTargetInches2)
{
	ActionTarget[0] = InchtoTicks(ActionTargetInches1);
	ActionTarget[1] = InchtoTicks(ActionTargetInches2);
}

void MovePID(void*)
{
	float PGain = 29;
	float PGainTurn = 180;
	int StraighteningGain = 550;
	float LMError;
	float last_LMError;
	float RMError;
	float last_RMError;
	float RFValue;
	float LFValue;
	float RIError;
	float LIError;
	float IGain = 0;
	float IGainTurn = 5;
	float DGain = 600;
	float DGainTurn = 650;
	float DRError;
	float DLError;
	int Dir;
	float curAngle;
	float angleError;
	float CorrectedLFValue;
	float CorrectedRFValue;
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	float Tolerance = InchtoTicks(2);
	float ToleranceIMU = 2;
	int IntergralZone = InchtoTicks(3);
	int IntergralZoneTurnL = 15;
	int IntergralZoneTurnR = 15;
  extern bool ActionFlag;
	extern bool PIDStop;
	//int RampDist = InchtoTicks(9);
	//int Accel = 500;
	int VoltCap = 12000;
	int VoltCapTurn = 12000;
	int VoltCapB = 6000;

	while(true)
	{
		while(PIDStop == true)
		{
			delay(15);
		}
		if(TypeMove == 0)
		{
			if (DriveRightFront.get_position()> (ActionTarget[0] - InchtoTicks(8)) && DriveRightFront.get_position() < (ActionTarget[0]+ InchtoTicks(6)))
			{
				ActionFlag = true;
				pros::lcd::print(5, "FlagTrue");
			}
			else if (DriveRightFront.get_position()> (ActionTarget[1] - InchtoTicks(8)) && DriveRightFront.get_position() < (ActionTarget[1]+ InchtoTicks(6)))
			{
				ActionFlag = true;
				pros::lcd::print(6, "FlagNUMBER2");
			}
			else
			{
				ActionFlag = false;

			}
			LMError = MoveTarget - DriveLeftBack.get_position();
			if((last_LMError * LMError) < 0)
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

			if((LMError * last_LMError) < 0)
			{
				LIError = 0;
			}

			DLError = LMError - last_LMError;
			last_LMError = LMError;

			LFValue = (LMError * PGain) + (LIError * IGain) + (DLError * DGain);
			 if(LFValue > VoltCap)
			 {
			 	LFValue = VoltCap;
			 }
			 if(LFValue < -(VoltCapB))
			 {
				 LFValue = -6000;
			 }
			//LFValue = (PIDValLeft)
			 //Finds the P value
			//motor[dLeft] = LFValue;
			// DriveLeftBack.move_voltage(LFValue);
			// DriveLeftFront.move_voltage(LFValue);

			RMError = MoveTarget - DriveRightBack.get_position();

			if((last_RMError * RMError) < 0)
			{
				// Passed destination
				RIError = 0;
			}

			if (fabsf(RMError) < IntergralZone)
			{
				RIError = (RIError + RMError);
			}
			else
			{
				RIError = 0;
			}

			if((RMError * last_RMError) < 0)
			{
				RIError = 0;
			}

			DRError = RMError - last_RMError;
			last_RMError = RMError;

			RFValue = (RMError * PGain) + (RIError * IGain) + (DRError * DGain); //Determines Power Given to the motors
			 if(RFValue > VoltCap)
			 {
			 	RFValue = VoltCap;
			 }
			 if(RFValue < -(VoltCapB))
 			 {
 				 RFValue = -6000;
 			 }

			 curAngle = Gyro.get_rotation();
			 angleError = (TargetGyro - curAngle);
			 pros::lcd::print(3, "Angle: %f", curAngle);
			 if(LFValue < 0)
			 {
				//angleError=-(angleError);
				CorrectedLFValue = LFValue;
				CorrectedRFValue = RFValue;
			 }
			 else
			 {
				 if(angleError < 0)
				 {
					 CorrectedLFValue = ((LFValue - (StraighteningGain * fabs(angleError))));
					 CorrectedRFValue = RFValue;
				 }
				 else if(angleError > 0)
				 {
					 CorrectedLFValue = LFValue;
					 CorrectedRFValue = ((RFValue - (StraighteningGain * fabs(angleError))));
				 }
				 else
				 {
					 CorrectedLFValue = LFValue;
					 CorrectedRFValue = RFValue;
				 }
			 }


			// pros::lcd::print(1, "Power: %f", RFValue);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));
		//	rightSlew(RFValue);
		//	leftSlew(LFValue);
			 //rightSlew(CorrectedRFValue);
			 //leftSlew(CorrectedLFValue);
			 DriveRightFront.move_voltage(CorrectedRFValue);
			 DriveLeftFront.move_voltage(CorrectedLFValue);
			 DriveRightBack.move_voltage(CorrectedRFValue);
			 DriveLeftBack.move_voltage(CorrectedLFValue);

			 pros::lcd::print(1, "PowerR: %f", RFValue);
			 pros::lcd::print(2, "PowerL: %f", LFValue);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));


			if (((fabsf(LMError)) < Tolerance) && ((fabsf(RMError)) < Tolerance))
			{
				counter = counter + 1;
			}
			else
			{
				counter = 0;
			}
			/*
			else if(time1[T1] > Timeout) //Time Out Option *need to learn timers*
			{
			counter = 51;
		}
		*/
		if (counter > 35)
		{
			InPosition = true;
			counter = 36;
			LFValue = 0;
			RFValue = 0;
		}
		else
		{
			//pros::lcd::print(3, "counter: %d", counter);
		}
	}

	if(TypeMove == 1)
	{

		float curAngle = Gyro.get_rotation();
		pros::lcd::print(3, "curAngle: %f", curAngle);
		//LMError = TargetTurnL - DriveLeftBack.get_position(); //Finds how far off the target we are
		LMError = (TargetTurnL - curAngle);

		if (fabsf(LMError) < IntergralZoneTurnL)
		{

			LIError = (LMError + LIError);
			if(fabs(LIError * IGainTurn) < 1000)
			{
				if(LMError > 0)
				{
				LIError = 1000/IGainTurn;
				}
				else
				{
					LIError = -1000/IGainTurn;
				}
			}
		}
		else
		{
			LIError = 0;
		}

		if((LMError * last_LMError) < 0)
		{
			LIError = 0;
		}

		DLError = LMError - last_LMError;
		last_LMError = LMError;

		LFValue = (LMError * PGainTurn) + (LIError * IGainTurn) + (DLError * DGainTurn); //Finds the power value
		pros::lcd::print(1, "PGain: %f", (LMError * PGainTurn));
		pros::lcd::print(2, "IGain: %f", (LIError * IGainTurn));
		pros::lcd::print(5, "DGain: %f", (DLError * DGainTurn));

		if (LFValue > VoltCapTurn)
		{
			LFValue = VoltCapTurn;
		}
		if (LFValue < -VoltCapTurn)
		{
			LFValue = -VoltCapTurn;
		}
		DriveLeftBack.move_voltage(LFValue);
		DriveLeftFront.move_voltage(LFValue);
		DriveRightBack.move_voltage(-LFValue);
		DriveRightFront.move_voltage(-LFValue);
		// RMError = TargetTurnR - DriveRightBack.get_position();
		// if (fabsf(LMError) < IntergralZoneTurnR)
		// {
		// 	LIError = (LIError + LMError);
		// }
		// else
		// {
		// 	LIError = 0;
		// }
		// RFValue = (RMError * PGainTurn) + (RIError * IGainTurn);

		//DriveRightBack.move_voltage(RFValue);
		//DriveRightFront.move_voltage(RFValue);
		if (((fabsf(LMError)) < ToleranceIMU))
		{
			counter = counter + 1;
		}
		else
		{
			counter = 0;
		}
		if (counter > 35)
		{
			InPosition = true;
			counter = 36;
		}

	}

	pros::delay(10);

}
}
