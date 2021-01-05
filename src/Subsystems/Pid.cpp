#include "main.h"

int TargetMove;
int MoveTarget;
int TargetTurnL;
int TargetTurnR;
int TypeMove = 0;
bool InPosition;
int counter;
int Timeout;
//int actiondistance;
//bool actionflag;
bool taskStarted;
int InchtoTicks(float inches)
{
	return(inches * 542.16)/(3.14 * 3.25); //Was 900
}

int DegstoTicksL(float degrees)
{
	return(degrees/360)*(1.08*3.14)* (542.16);
	//not sure what 1.08 means
}

int DegstoTicksR(float degrees)
{
	return-((degrees/360)*(1.08*3.14)* (542.16));
	//not sure what 1.08 means
}

void setTargetMove(float inches)
{
	//set motor encoders to 0
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	MoveTarget = InchtoTicks(inches);
	//Converts from inches to ticks
	//actiondistance = InchtoTicks(actiondistanceinches);
	taskStarted = false;
	InPosition = false;
	//actionflag = false;
	counter = 0;
	TypeMove = 0;
	//Clear Timer
	Timeout = ((fabsf(inches) / 15.0) * 1000) + 1000;
}

void setTargetTurn(float degrees)
{
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
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

void MovePID(void*)
{
	float PGain = 0.1;
	float PGainTurn = 1;
	float LMError;
	float last_LMError;
	float RMError;
	float last_RMError;
	float RFValue;
	float LFValue;
	float RIError;
	float LIError;
	float IGain = 0.01;
	float IGainTurn = 0.03;
	float DGain = 0.1;
	float DGainTurn = 0;
	float DRError;
	float DLError;
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	float Tolerance = InchtoTicks(1);
	int IntergralZone = InchtoTicks(3);
	int IntergralZoneTurnL = DegstoTicksL(7);
	int IntergralZoneTurnR = DegstoTicksR(7);
  bool ActionFlag;
	extern bool PIDStop;

	while(true)
	{
		while(PIDStop == false)
		{
			delay(15);
		}
		if(TypeMove == 0)
		{
			if (DriveRightFront.get_position()> (ActionTarget[0] - InchtoTicks(1)) && DriveRightFront.get_position() < (ActionTarget[0]+ InchtoTicks(1)))
			{
				ActionFlag = true;
			}
			else if (DriveRightFront.get_position()> (ActionTarget[0] - InchtoTicks(1)) && DriveRightFront.get_position() < (ActionTarget[0]+ InchtoTicks(1)))
			{
				ActionFlag = true;
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

			LFValue = (LMError * PGain) + (LIError * IGain) + (DLError * DGain); //Finds the P value
			//motor[dLeft] = LFValue;
			DriveLeftBack.move_velocity(LFValue);
			DriveLeftFront.move_velocity(LFValue);

			RMError = MoveTarget - DriveRightBack.get_position();

			if((last_RMError * RMError) < 0)
			{
				// Passed destination
				RIError = 0;
			}
			last_RMError = RMError;

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
			pros::lcd::print(1, "Power: %f", RFValue);
			pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			pros::lcd::print(4, "DGain: %f", (DRError * DGain));
			DriveRightBack.move_velocity(RFValue);
			DriveRightFront.move_velocity(RFValue);

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
			actionflag = true;
		}
		*/
		if (counter > 50)
		{
			InPosition = true;
		}
		else
		{
			//pros::lcd::print(3, "counter: %d", counter);
		}
	}

	if(TypeMove == 1)
	{


		LMError = TargetTurnL - DriveLeftBack.get_position(); //Finds how far off the target we are
		if (fabsf(LMError) < IntergralZoneTurnL)
		{
			LIError = (LIError + LMError);
		}
		else
		{
			LIError = 0;
		}
		LFValue = (LMError * PGainTurn) + (LIError * IGainTurn); //Finds the power value

		DriveLeftBack.move_velocity(LFValue);
		DriveLeftFront.move_velocity(LFValue);

		RMError = TargetTurnR - DriveRightBack.get_position();
		if (fabsf(LMError) < IntergralZoneTurnR)
		{
			LIError = (LIError + LMError);
		}
		else
		{
			LIError = 0;
		}
		RFValue = (RMError * PGainTurn) + (RIError * IGainTurn);

		DriveRightBack.move_velocity(RFValue);
		DriveRightFront.move_velocity(RFValue);
		if (((fabsf(LMError)) < Tolerance) && ((fabsf(RMError)) < Tolerance))
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
