#include "main.h"

//Call Functions
void setTargetMove(float inches, float actiondistanceinches);
void setTargetTurn(float degrees);
void setActionTarget(float ActionTargetInches1, float ActionTargetInches2);

//PID Task
void MovePID(void*);

//Variables
extern bool InPosition;
