#ifndef ChessClock_h
#define ChessClock_h
#include "Arduino.h"
#include "StopWatch.h"

class ChessClock{
  public:
  enum Mode {RESET,PLAY};
  Mode mode;
  ChessClock();
  StopWatch sw1;
  StopWatch sw2;
  StopWatch lockClock;
  bool canPress;
  bool gameFinished;
  
  //functions
  unsigned long getSecondsSW1();
  unsigned long getSecondsSW2();

  void leftPressed();
  void rightPressed();
  void srPressed();
  void swapModes();
  void printTimers();
  void resetLockClock();
  bool checkIfCanPress();
  void swapCanPress();
  void resetChessClock();
  
  private:
  int leftCount;
  int rightCount;
 
 
  
  
  
};

#endif
