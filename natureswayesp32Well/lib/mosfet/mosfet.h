#ifndef __mosfet_h_
#define __mosfet_h_

#include "Arduino.h"

#define JUST_TURNED_ON 0
#define CHECKING_SYSTEMS 1
#define BACKWASH 2
#define RINSE 3
#define MINERAL_BALANCED 4
#define TANK_FULL 5

// for the pump
#define OFF 0
#define ON 1

// MOSFET pin placement new
#define BACKWARD1 32 // Backward valve
#define BACKWARD2 33 // Backward valve
#define RINSE1 25 // Rinse valve
#define RINSE2 26 // Rinse valve
#define FORWARD1 27 // Forward valve
#define FORWARD2 14 // Forward valve
#define PUMP 13 // Continuously on

class Mosfet
{
public:
  //Methods
	Mosfet();
	void run(int state);
  void TEST();
private:
  void valveControl(int state);
  void runPump(int pumpStatus);
};

#endif 