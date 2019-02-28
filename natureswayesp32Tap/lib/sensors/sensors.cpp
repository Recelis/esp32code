#include "sensors.h"
#include <Arduino.h>

Sensors::Sensors(){
    pinMode(HIGHPRESSURE_READ, INPUT);
    pinMode(LOWPRESSURE_READ, INPUT);
}

bool Sensors::getLowStatus(){ // if HIGH then ERROR!
    return digitalRead(LOWPRESSURE_READ); 
}

bool Sensors::getHighStatus(){
    return digitalRead(HIGHPRESSURE_READ);
}


// if readings HIGH, then ERROR.

// if (highpread == HIGH || lowpread == HIGH){
//         if (highpread == HIGH && lowpread == LOW) return ERRORH;
//         else if (highpread == LOW && lowpread == HIGH) return ERRORL;
//         else if (highpread == HIGH && lowpread == HIGH) return ERRORB;
//         else return ERRORU;
//     }
