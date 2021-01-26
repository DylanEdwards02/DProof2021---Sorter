#include "main.h"
//Header File


//Helper Functions
//Motor percentage
void setIntake();
void setBack();
void setFront();

//Motor voltage
void setFrontVolt();
void setBackVolt();
void setIntakeVolt();

//Opcontrol Functions
void Cycle();
void Indexing();
void Buttons();
void IntakeAuton();

extern bool AutonIntakeEnable;
extern bool ActionFlag;
