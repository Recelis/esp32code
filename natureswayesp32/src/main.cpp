#include <Arduino.h>
#include "control.h"


Control Cont;

void setup(){
  Serial.begin(9600); // for printing to screen
}

void loop(){
  Cont.run();
}






