#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	MotorInitialize();
	pros::lcd::register_btn0_cb(lcd_left_button);
	pros::lcd::register_btn2_cb(lcd_right_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
 void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous()
 {
	 pros::Task MoveTask(MovePID);
<<<<<<< Updated upstream
	 PIDStop = true;

	 SkillsAuton();
=======
	switch (switchval)
	{
		case 0:
	//	SKILLS();
			break;
		case 1:
		Homerow();
	//	ThreePT();
			break;
		case 2:
		HomerowRight();
	//	TwoPTLeft();
			break;
		case 3:
		TwoPointLeft();
	//	ALTLeft();
			break;
		case 4:
		TwoPointRight();
	//	TwoPTRight();

			break;
		case 5:
		CenterAuton();
	//	ALTRight();

			break;
		case 6:
		//SKILLS();

			break;

		default:
		break;
	}
	 //SkillsAuton();

	 //PIDStop = false;

	 //SkillsAuton();
	 //Homerow();
	 //TwoPointRight();
	 //TwoPointLeft();
	 //ProofRunFast(); //Skills
//	 AutonTest();
	 //Square();

>>>>>>> Stashed changes
	 // setTargetTurn(-86);
	 // while(InPosition == false)
	 // {
		//  delay(10);
	 // }
 }

/**
 * Runs the operator conrol code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 bool PIDStop = false;

 void opcontrol()
 {
	 PIDStop = false;
	 while(true)
	 {
		 setDriveMotors();
		 Cycle();
		 Indexing();
		 Buttons();
		 delay(10);
<<<<<<< Updated upstream
=======
		 pros::lcd::print(5,"curAngle: %f",Gyro.get_rotation());
>>>>>>> Stashed changes
	 }
 }
