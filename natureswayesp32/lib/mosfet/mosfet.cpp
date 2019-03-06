#include "mosfet.h"

Mosfet::Mosfet()
{
  pinMode(PUMP, OUTPUT);
  pinMode(FORWARD1, OUTPUT);
  pinMode(FORWARD2, OUTPUT);
  pinMode(RINSE1, OUTPUT);
  pinMode(RINSE2, OUTPUT);
  pinMode(BACKWARD1, OUTPUT);
  pinMode(BACKWARD2, OUTPUT);
}

void Mosfet::run(int state) // controls the peripherals + others
{
  switch(state){
    case JUST_TURNED_ON:
      valveControl(OFF);
      runPump(OFF); 
      break;
    case CHECKING_SYSTEMS:
      valveControl(OFF);
      runPump(OFF); 
      break;
    case BACKWASH:
      valveControl(BACKWASH);
      runPump(ON);
      break;
    case RINSE:
      valveControl(RINSE);
      runPump(ON);
      break;
    case MINERAL_BALANCED:
      valveControl(MINERAL_BALANCED);
      runPump(ON);
      break;
    case TANK_FULL:
      valveControl(MINERAL_BALANCED);
      runPump(OFF);
      break;
    default: // error cases
      valveControl(MINERAL_BALANCED);
      runPump(OFF);
      break;
  }
} 

void Mosfet::valveControl(int state)
{
  if (state == MINERAL_BALANCED)
  {
    digitalWrite(BACKWARD1, LOW); // Backward Normally Closed 
    digitalWrite(BACKWARD2, LOW); 
    digitalWrite(RINSE1, LOW);
    digitalWrite(RINSE2, LOW); 
    digitalWrite(FORWARD1, HIGH);  // Forward Normally Closed
    digitalWrite(FORWARD2, HIGH);    
  }
  else if(state == BACKWASH)
  {
    digitalWrite(FORWARD2, LOW);  // Forward Normally Closed 
    digitalWrite(FORWARD1, LOW); 
    digitalWrite(RINSE1, LOW); 
    digitalWrite(RINSE2, LOW);
    digitalWrite(BACKWARD1, HIGH);  // Backward Normally Closed
    digitalWrite(BACKWARD2, HIGH); 
  }
  else if (state == RINSE)
  {
    digitalWrite(FORWARD1, LOW);  // Forward Normally Closed 
    digitalWrite(FORWARD2, LOW); 
    digitalWrite(BACKWARD1, LOW);  // Backward Normally Closed
    digitalWrite(BACKWARD2, LOW);
    digitalWrite(RINSE1, HIGH); 
    digitalWrite(RINSE2, HIGH);
  }
  else if(state == OFF){
    digitalWrite(FORWARD1, LOW);  // Forward Normally Closed 
    digitalWrite(FORWARD2, LOW); 
    digitalWrite(BACKWARD1, LOW);  // Backward Normally Closed
    digitalWrite(BACKWARD2, LOW);
    digitalWrite(RINSE1, LOW); 
    digitalWrite(RINSE2, LOW);
  }
  else { // close all valves if error
    digitalWrite(FORWARD1, LOW);  // Forward Normally Closed 
    digitalWrite(FORWARD2, LOW); 
    digitalWrite(BACKWARD1, LOW);  // Backward Normally Closed
    digitalWrite(BACKWARD2, LOW);
    digitalWrite(RINSE1, LOW); 
    digitalWrite(RINSE2, LOW);
  }
}

void Mosfet::runPump(int pumpStatus){
  if (pumpStatus == OFF){
    digitalWrite(PUMP, LOW);  
  } else {
    digitalWrite(PUMP, HIGH);
  }
}

void Mosfet::TEST(){
  digitalWrite(FORWARD1, HIGH);  // Forward Normally Closed 
  digitalWrite(FORWARD2, HIGH); 
  digitalWrite(BACKWARD1, HIGH);  // Backward Normally Closed
  digitalWrite(BACKWARD2, HIGH);
  digitalWrite(RINSE1, HIGH); 
  digitalWrite(RINSE2, HIGH);
  digitalWrite(PUMP, HIGH);
}
