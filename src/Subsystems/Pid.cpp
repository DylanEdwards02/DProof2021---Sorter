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
<<<<<<< Updated upstream
=======
	TargetGyro = Heading;
	int StartTime = GlobalTime;
>>>>>>> Stashed changes
	//Clear Timer
	Timeout = ((fabsf(inches) / 15.0) * 1000) + 1000;
}


//Function that is called to set the target value of the PID to make turns.
void setTargetTurn(float heading)
{
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
<<<<<<< Updated upstream
	TargetTurnL= DegstoTicksL(degrees);
	TargetTurnR= DegstoTicksR(degrees);
=======
	double TargetTurnMaster;

	TargetTurnMaster = heading;


	TargetTurnL = TargetTurnMaster;
	TargetTurnR = TargetTurnMaster;
	//TargetTurnL= DegstoTicksL(degrees);
	//TargetTurnR= DegstoTicksR(degrees);
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void MovePID(void*)
{
	float PGain = 29;
	float PGainTurn = 30;
=======
// double getIMURotation
// {
// 	return Imu.get_rotation();
// }

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
void MovePID(void*)
{
	float PGain = 29;
	float PGainTurn = 145; //150
	int StraighteningGain = 500;
>>>>>>> Stashed changes
	float LMError;
	float last_LMError;
	float RMError;
	float last_RMError;
	float RFValue;
	float LFValue;
	float RIError;
	float LIError;
	float IGain = 0;
<<<<<<< Updated upstream
	float IGainTurn = 0;
	float DGain = 25;
	float DGainTurn = 25;
=======
	float IGainTurn = 15;
	float DGain = 25;
	float DGainTurn = 20;
>>>>>>> Stashed changes
	float DRError;
	float DLError;
	DriveLeftBack.tare_position();
	DriveRightBack.tare_position();
	float Tolerance = InchtoTicks(2);
<<<<<<< Updated upstream
	int IntergralZone = InchtoTicks(3);
	int IntergralZoneTurnL = DegstoTicksL(7);
	int IntergralZoneTurnR = DegstoTicksR(7);
=======
	//float ToleranceTurnL = DegstoTicksL(3);
	//float ToleranceTurnR = DegstoTicksR(3);
	float ToleranceTurnL = 1;
	float ToleranceTurnR = 1;
	float ToleranceIMU = 2;
	int IntergralZone = InchtoTicks(3);
	//int IntergralZoneTurnL = DegstoTicksL(7);
	//int IntergralZoneTurnR = DegstoTicksR(7);
	int IntergralZoneTurnL = 15;
	int IntergralZoneTurnR = 15;
>>>>>>> Stashed changes
  extern bool ActionFlag;
	extern bool PIDStop;
	//int RampDist = InchtoTicks(9);
	//int Accel = 500;
<<<<<<< Updated upstream
	int VoltCap = 12000;
=======
	int VoltCap = 11000;
	int VoltCapTurn = 12000;
>>>>>>> Stashed changes

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

			DLError = LMError - last_LMError;
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

			DRError = RMError - last_RMError;
			last_RMError = RMError;

			RFValue = (RMError * PGain) + (RIError * IGain) + (DRError * DGain); //Determines Power Given to the motors
			RFValue = (RFValue * .30);
			 if(RFValue > VoltCap)
			 {
			 	RFValue = VoltCap;
			 }
<<<<<<< Updated upstream
			// pros::lcd::print(1, "Power: %f", RFValue);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));
			DriveRightBack.move_voltage(RFValue);
			DriveRightFront.move_voltage(RFValue);

			if (((fabsf(LMError)) < Tolerance) && ((fabsf(RMError)) < Tolerance))
=======
			 if(RFValue < -(VoltCap))
			 {
				 RFValue = -(VoltCap);
			 }
			 pros::lcd::print(1, "PowerR: %f", RMError);
			 pros::lcd::print(2, "PowerL: %f", LMError);
			// pros::lcd::print(2, "PGain: %f", (RMError * PGain));
			// pros::lcd::print(3, "IGain: %f", (RIError * IGain));
			// pros::lcd::print(4, "DGain: %f", (DRError * DGain));
			 curAngle = Gyro.get_rotation();
			 angleError = (TargetGyro - curAngle);
			 pros::lcd::print(3, "Angle: %f", curAngle);
			 if(LFValue > 0)
			 {
				 Dir = 1;
			 }
			 else
			 {
				 Dir = -1;
			 }
			 if(angleError < 0)
			 {
				 CorrectedLFValue = LFValue;
				 CorrectedRFValue = (RFValue + (StraighteningGain * angleError));
			 }
			 else if(angleError > 0)
			 {
				 CorrectedLFValue = (LFValue + (StraighteningGain * angleError));
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
			//DriveLeftBack.move_voltage(CorrectedLFValue);
			//DriveLeftFront.move_voltage(CorrectedLFValue);
			 //leftSlew(CorrectedLFValue);
			 //rightSlew(CorrectedRFValue);
			//DriveRightBack.move_voltage(CorrectedRFValue);
		 	//DriveRightFront.move_voltage(CorrectedRFValue);
			 rightSlew(RFValue);
			 leftSlew(LFValue);


			if (((fabs(LMError)) < Tolerance) && ((fabs(RMError)) < Tolerance))
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream

		LMError = TargetTurnL - DriveLeftBack.get_position(); //Finds how far off the target we are
		if (fabsf(LMError) < IntergralZoneTurnL)
		{
			LIError = (LIError + LMError);
=======
		//LMError = TargetTurnL - DriveLeftBack.get_position(); //Finds how far off the target we are
		float curAngle = Gyro.get_rotation();
		LMError = (TargetTurnL - curAngle);
		//pros::lcd::print(1, "LeftError: %f", LFValue);
		pros::lcd::print(3, "CurAngle: %f", Gyro.get_rotation());
		if (fabsf(LMError) < IntergralZoneTurnL)
		{
			// if(LMError > 0)
			// {
			LIError = (LMError + LIError);
			//}
			// else
			// {
			// LIError = (LMError - LIError);
			// }
>>>>>>> Stashed changes
		}
		else
		{
			LIError = 0;
		}
		LFValue = (LMError * PGainTurn) + (LIError * IGainTurn); //Finds the power value

<<<<<<< Updated upstream
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
=======
		if((LMError * last_LMError) < 0)
		{
			LIError = 0;
		}
		// DLError = LMError - last_LMError;
		 last_LMError = LMError;

		LFValue = ((LMError * PGainTurn) + (LIError * IGainTurn) + (DLError * DGainTurn)); //Finds the power value
		//LFValue = (LFValue * 0.92);
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

		// //RMError = TargetTurnR - DriveRightBack.get_position();
		// RMError = (TargetTurnR - curAngle);
		// pros::lcd::print(2, "Right I: %f", (RIError * IGainTurn));
		// if (fabsf(RMError) < IntergralZoneTurnR)
		// {
		// 	// if(RMError > 0)
		// 	// {
		// 	RIError = (RMError + RIError);
		// 	//}
		// 	// else
		// 	// {
		// 	// RIError = (RMError - RIError);
		// 	// }
		// }
		// else
		// {
		// 	RIError = 0;
		// }
		// // DRError = RMError - last_RMError;
		// if((RMError * last_RMError) < 0)
		// {
		// 	RIError = 0;
		// }
		//  last_RMError = RMError;
		// // pros::lcd::print(1, "DRError: %f", DRError);
		// RFValue = ((RMError * PGainTurn) + (RIError * IGainTurn) + (DRError * DGainTurn));
		// //RFValue = (RFValue * 0.92);
		//
		// if (RFValue > VoltCapTurn)
		// {
		// 	RFValue = VoltCapTurn;
		// }
		// if (RFValue < -(VoltCapTurn))
		// {
		// 	RFValue = -VoltCapTurn;
		// }

		DriveRightBack.move_voltage(-LFValue);
		DriveRightFront.move_voltage(-LFValue);

		//pros::lcd::print(4, "Right P: %f", (RMError * PGainTurn));
		pros::lcd::print(5, "Left P: %f", (LMError * PGainTurn));
		pros::lcd::print(2, "Left I: %f", (LIError * IGainTurn));
		pros::lcd::print(1, "Counter: %f", counter);
		if ((fabsf(LMError)) < ToleranceIMU)
>>>>>>> Stashed changes
		{
			counter = counter + 1;
		}
		else
		{
			counter = 0;
		}
<<<<<<< Updated upstream
		if (counter > 20)
=======

		if (counter > 40)
>>>>>>> Stashed changes
		{
			InPosition = true;
			//pros::lcd::print(5,"Here");
		}

	}

	pros::delay(10);

}
}
