#ifndef Controller_h
#define Controller_h
#include "Arduino.h"

class Controller{
  public:
  Controller(int L,int R,int SR);
  int l,r,sr; // l = left button , r = right button , sr = start/reset button
  int getL();
  int getR();
  int getSR();
  bool getInputL();
  bool getInputR();
  bool getInputSR();
  private:
  
};

#endif
