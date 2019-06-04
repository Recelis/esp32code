
#include "errors.h"
#include <Arduino.h>

Sensors Sens;

Errors::Errors(){
    error = NO_ERROR;
    debounceCount = 0;
}

int Errors::returnError(){
    if (Sens.getLowStatus()){
        debounceCount++;
        if (debounceCount >= 30){
            error = ERROR_LOW;
            return error;
        } else {
            error = NO_ERROR;
            Serial.println("DEBOUNCING");
            return error;
        }
    } else {
        debounceCount = 0;
        error = NO_ERROR;
        return error;
    }
}

void Errors::printError(){
    switch(error){
        case ERROR_LOW:
            Serial.println("LOW PRESSURE ERROR");
            break;
        default:
            Serial.println("NO ERROR");
            break;
    }
}