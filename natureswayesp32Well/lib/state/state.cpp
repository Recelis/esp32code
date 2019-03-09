#include "state.h"

Sensors HighSens;

State::State()
{
    currState = JUST_TURNED_ON;
    currTime = 0;
    triggerVal = JUST_TRIGGER;
    errorFlag = false;
}

void State::triggerNextState(int error)
{
    currTime++;
    Serial.println(currTime);
    convertStateToString();
    // get errors
    if (error != NO_ERROR) // from no error, to low pressure
    {
        currState = error; // sets start time to beginning if error detected
        currTime = 0;
        errorFlag = true;
        return;
    } // if from error to non-error, will change state to checking systems?
    // if no error
    else
    {
        if (errorFlag == true)
        { // if low pressure to good pressure
            changeState(false);
            currTime = 0;
            errorFlag = false;
            setTriggerVal();   // new trigger times to wait for
            return;
        }
        // check for trigger times
        if (currTime > triggerVal)
        {
            changeState(true); // change to new state
            setTriggerVal();   // new trigger times to wait for
            // Tim.setStartTime(); // new start time
            currTime = 0;
        }
        else
        { // if in forward clean, toggle between forwardclean and standby depending on high press reading
            if (currState == MINERAL_BALANCED)
            {
                if (HighSens.getHighStatus())
                    currState = TANK_FULL;
                return;
            }
            if (currState == TANK_FULL)
            {
                if (HighSens.getHighStatus() == LOW)
                {
                    currState = MINERAL_BALANCED;
                    return;
                }
            }
        }
    }
}

void State::setTriggerVal()
{
    switch (currState)
    {
    case JUST_TURNED_ON:
        triggerVal = JUST_TRIGGER;
        break;
    // case CHECKING_SYSTEMS:
    //     triggerVal = CHECKING_TRIGGER;
    //     break;
    case BACKWASH:
        triggerVal = BACK_TRIGGER;
        break;
    case RINSE:
        triggerVal = RINSE_TRIGGER;
        break;
    case MINERAL_BALANCED:
        triggerVal = FORW_STAND_TRIGGER;
        break;
    default:
        triggerVal = 0;
        break;
    }
}

void State::changeState(bool triggering)
{
    switch (currState)
    {
    case JUST_TURNED_ON:
        currState = BACKWASH;
        break;
    // case CHECKING_SYSTEMS:
    //     currState = BACKWASH;
    //     break;
    case BACKWASH:
        currState = RINSE;
        break;
    case RINSE:
        currState = MINERAL_BALANCED;
        break;
    case MINERAL_BALANCED:
        currState = BACKWASH;
        break;
    case TANK_FULL:
        if (triggering)
            currState = BACKWASH;
        else
            currState = MINERAL_BALANCED;
        break;
    default:
        // for any errors
        currState = BACKWASH;
        break;
    }
}

int State::getState()
{
    return currState;
}

void State::convertStateToString()
{
    switch (currState)
    {
    case JUST_TURNED_ON:
        Serial.println("JUST_TURNED_ON");
        break;
    // case CHECKING_SYSTEMS:
    //     Serial.println("CHECKING_SYSTEMS");
    //     break;
    case BACKWASH:
        Serial.println("BACKWASH");
        break;
    case RINSE:
        Serial.println("RINSE");
        break;
    case MINERAL_BALANCED:
        Serial.println("MINERAL_BALANCED");
        break;
    case TANK_FULL:
        Serial.println("TANK_FULL");
        break;
    default:
        Serial.println("ERROR!");
        break;
    }
}