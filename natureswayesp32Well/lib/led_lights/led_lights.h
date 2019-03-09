#ifndef LEDS_H_
#define LEDS_H_

#include "Arduino.h"

#define JUST_TURNED_ON 0
#define CHECKING_SYSTEMS 1
#define BACKWASH 2
#define RINSE 3
#define MINERAL_BALANCED 4
#define TANK_FULL 5

#define ON_LED 18
#define BACKWASH_LED 19
#define RINSE_LED 21
#define MINERAL_BALANCED_LED 22
#define TANK_FULL_LED 23
#define ERROR_LOW_LED 5 

class LEDS {
    public:
        LEDS();
        ~LEDS(){};
        void setLEDs(int state);
        void TEST();
    private:
        bool testHighState;
        bool testLowState;
};

#endif