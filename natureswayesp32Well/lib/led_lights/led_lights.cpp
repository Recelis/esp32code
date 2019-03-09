#include "led_lights.h"
#include "sensors.h"

Sensors SensTest;

LEDS::LEDS()
{
    pinMode(ON_LED, OUTPUT);
    pinMode(BACKWASH_LED, OUTPUT);
    pinMode(RINSE_LED, OUTPUT);
    pinMode(MINERAL_BALANCED_LED, OUTPUT);
    pinMode(TANK_FULL_LED, OUTPUT);
    pinMode(ERROR_LOW_LED, OUTPUT);
    testHighState = true;
    testLowState = false;
}

void LEDS::setLEDs(int state)
{
    switch (state)
    {
    case JUST_TURNED_ON:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, LOW);
        digitalWrite(RINSE_LED, LOW);
        digitalWrite(MINERAL_BALANCED_LED, LOW);
        digitalWrite(TANK_FULL_LED, LOW);
        digitalWrite(ERROR_LOW_LED, LOW);
        break;
    case BACKWASH:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, HIGH);
        digitalWrite(RINSE_LED, LOW);
        digitalWrite(MINERAL_BALANCED_LED, LOW);
        digitalWrite(TANK_FULL_LED, LOW);
        digitalWrite(ERROR_LOW_LED, LOW);
        break;
    case RINSE:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, LOW);
        digitalWrite(RINSE_LED, HIGH);
        digitalWrite(MINERAL_BALANCED_LED, LOW);
        digitalWrite(TANK_FULL_LED, LOW);
        digitalWrite(ERROR_LOW_LED, LOW);
        break;
    case MINERAL_BALANCED:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, LOW);
        digitalWrite(RINSE_LED, LOW);
        digitalWrite(MINERAL_BALANCED_LED, HIGH);
        digitalWrite(TANK_FULL_LED, LOW);
        digitalWrite(ERROR_LOW_LED, LOW);
        break;
    case TANK_FULL:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, LOW);
        digitalWrite(RINSE_LED, LOW);
        digitalWrite(MINERAL_BALANCED_LED, LOW);
        digitalWrite(TANK_FULL_LED, HIGH);
        digitalWrite(ERROR_LOW_LED, LOW);
        break;
    default:
        digitalWrite(ON_LED, HIGH);
        digitalWrite(BACKWASH_LED, LOW);
        digitalWrite(RINSE_LED, LOW);
        digitalWrite(MINERAL_BALANCED_LED, LOW);
        digitalWrite(TANK_FULL_LED, LOW);
        digitalWrite(ERROR_LOW_LED, HIGH);
        break;
    }
}

void LEDS::TEST()
{
    bool HIGH_PRESSURE = SensTest.getHighStatus();
    bool LOW_PRESSURE = SensTest.getLowStatus(); 
    digitalWrite(ON_LED, HIGH);
    digitalWrite(BACKWASH_LED, HIGH);
    digitalWrite(RINSE_LED, HIGH);
    digitalWrite(MINERAL_BALANCED_LED, HIGH);
    if (HIGH_PRESSURE) {
        if (testHighState) testHighState = false;
        else testHighState = true;
        digitalWrite(TANK_FULL_LED, testHighState);
    }  
    else digitalWrite(TANK_FULL_LED, HIGH);

    if (LOW_PRESSURE) {
        if (testLowState) testLowState = false;
        else testLowState = true;
        digitalWrite(ERROR_LOW_LED, testLowState);
    }  
    else
    digitalWrite(ERROR_LOW_LED, HIGH);
}