#include "control.h"
State Stat;
Mosfet Mos;
LEDS POU_LEDS;
Errors Err;


void Control::run(){
    int state = Stat.getState(); // returns current state
    int error = Err.returnError(); // checks for error from sensor
    Stat.triggerNextState(error); // changes state from sensors or from time
    Err.printError(); // prints ERROR to console
    Mos.run(state);// set MOSFETS
    POU_LEDS.setLEDs(state);
    delay(1000); // rough but will be roughly right, hopefully no one is actively counting!
}

void Control::PCBTEST(){
    Mos.TEST();
    POU_LEDS.TEST();
    delay(500);
}






