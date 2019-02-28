
#include "errors.h"
#include <Arduino.h>

Sensors Sens;

Errors::Errors(){
    error = NO_ERROR;
}

int Errors::returnError(){
    if (Sens.getLowStatus()){
        error = ERROR_LOW;
        return error;
    } else {
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