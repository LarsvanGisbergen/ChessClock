
#include "Controller.h"
//keeps track of all pin input
Controller::Controller(int L,int R,int SR):
  l(L),r(R),sr(SR)
 
{
  //set all buttons to input mode
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  pinMode(sr, INPUT);
 
}

//returns left button pin
int Controller::getL(){
  return l;
}

//returns right button pin
int Controller::getR(){
  return r;
}

//returns start/reset button pin
int Controller::getSR(){
  return sr;
}

//returns true if pressed
bool Controller::getInputL(){
  return digitalRead(l) == HIGH;
}
bool Controller::getInputR(){
  return digitalRead(r) == HIGH;
}
bool Controller::getInputSR(){
  return digitalRead(sr) == HIGH;
}
