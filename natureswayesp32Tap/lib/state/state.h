#ifndef __state_h_
#define __state_h_
#include "sensors.h"
#include <Arduino.h>


#define JUST_TURNED_ON 0
#define CHECKING_SYSTEMS 1
#define BACKWASH 2
#define RINSE 3
#define MINERAL_BALANCED 4
#define TANK_FULL 5

// Trigger Times
#define JUST_TRIGGER 0
#define CHECKING_TRIGGER 1
#define BACK_TRIGGER 60
#define FORW_STAND_TRIGGER 43140

#define ERROR_LOW 3
#define NO_ERROR 0


class State
{
public:
	State();
  int getState();
  void convertStateToString();
  void triggerNextState(int error);
private:
  void changeState(bool triggering);
  void setTriggerVal();
  int newState;
  int currState;
  long currTime;
  long triggerVal;
  bool errorFlag;
};

#endif
