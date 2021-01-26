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
	//Clear Timer
	Timeout = ((fabsf(inches) / 15.0) * 1000) + 1000;
}


//Function that is called to set the target value of the PID to make turns.
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
	float PGain = 29;
	float PGainTurn = 30;
	float LMError;
	float last_LMError;
	float RMError;
	float last_RMError;
	float RFValue;
	float LFValue;
	float RIError;
	float LIError;
	float IGain = 0;
	float IGainTurn = 0;
	float DGain = 25;
	float DGainTurn = 25;
	float DRError;
	float DLError;
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	float Tolerance = InchtoTicks(2);
	int IntergralZone = InchtoTicks(3);
	int IntergralZoneTurnL = DegstoTicksL(7);
	int IntergralZoneTurnR = DegstoTicksR(7);
  extern bool ActionFlag;
	extern bool PIDStop;
	//int RampDist = InchtoTicks(9);
	//int Accel = 500;
	int VoltCap = 12000;

	while(true)
	{
		while(PIDStop == false)
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
			//LFValue = (PIDValLeft)
			 //Finds the P value
			//motor[dLeft] = LFValue;
			DriveLeftBack.move_voltage(LFValue);
			DriveLeftFront.move_voltage(LFValue);

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
			RFValue = (RFValue * .30);
			 if(RFValue > VoltCap)
			 {
			 	RFValue = VoltCap;
			 }
			// pros::lcd::print(1, "Power: %f", RFValue);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));
			DriveRightBack.move_voltage(RFValue);
			DriveRightFront.move_voltage(RFValue);

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

		DriveLeftBack.move_voltage(LFValue);
		DriveLeftFront.move_voltage(LFValue);

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

		DriveRightBack.move_voltage(RFValue);
		DriveRightFront.move_voltage(RFValue);
		if (((fabsf(LMError)) < Tolerance) && ((fabsf(RMError)) < Tolerance))
		{
			counter = counter + 1;
		}
		else
		{
			counter = 0;
		}
		if (counter > 20)
		{
			InPosition = true;
		}

	}

	pros::delay(10);

}
}
