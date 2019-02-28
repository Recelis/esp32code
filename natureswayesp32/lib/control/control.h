#ifndef __control_h_
#define __control_h_
#include <Arduino.h>
#include "state.h"
#include "led_lights.h"
#include "mosfet.h"
#include "errors.h"



#define JUST_TURNED_ON 0
#define CHECKING_SYSTEMS 1
#define BACKWASH 2
#define RINSE 3
#define MINERAL_BALANCED 4
#define TANK_FULL 5


class Control{
    public:
        Control(){};
        ~Control(){};
        void run();
    private:
};

#endif