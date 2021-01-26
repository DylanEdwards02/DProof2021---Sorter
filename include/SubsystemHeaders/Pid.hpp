#include "main.h"
//Header File


//Call Functions
void setTargetMove(float inches);
void setTargetTurn(float degrees);
void setActionTarget(float ActionTargetInches1, float ActionTargetInches2);

//PID Task
void MovePID(void*);

//Variables
extern bool InPosition;
extern bool PIDStop;
extern bool ActionFlag;
extern bool AutonIntakeEnable;
