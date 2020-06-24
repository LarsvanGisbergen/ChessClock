#include "ChessClock.h"



//contains all functions for both Modes (PLAY/RESET)
ChessClock::ChessClock()
{
  sw1 = StopWatch(StopWatch::SECONDS);
  sw2 = StopWatch(StopWatch::SECONDS);
  lockClock = StopWatch(); //millis
  mode = RESET; //start on RESET to allow players to setup their preferred time
  rightCount = 0;
  leftCount = 0;
  canPress = true;
  gameFinished = false;
  lockClock.start();
}
//test
unsigned long ChessClock::getSecondsSW1(){
  return sw1.elapsed();
}
unsigned long ChessClock::getSecondsSW2(){
  return sw2.elapsed();
}

void ChessClock::rightPressed(){
  checkIfCanPress();
  if(mode == RESET && canPress){
    rightCount += 30; //add 30 secs to clock
    resetLockClock();
  }else if(mode == PLAY){
    sw2.stop();
    sw1.start();
  }
}
void ChessClock::leftPressed(){
  checkIfCanPress();
  if(mode == RESET && canPress){
    leftCount += 30; //add 30 secs to clock
    resetLockClock();
  }else if(mode == PLAY){
    sw1.stop();
    sw2.start();
  }
}
void ChessClock::srPressed(){
  checkIfCanPress();
  if(canPress){
    if(gameFinished){
      gameFinished = !gameFinished;
    }
  swapModes();
  if(mode == RESET){ 
    resetChessClock();
    }
  }
  resetLockClock();
}

//prints time that each player has left
void ChessClock::printTimers(){
  if(!gameFinished){
  if(mode == PLAY){
    if(leftCount - getSecondsSW1() <= 0){
      gameFinished = true;
      Serial.println("Time's up for left!!!");
      return;
    }else if(rightCount - getSecondsSW2() <= 0){
      gameFinished = true;
      Serial.println("Time's up for right!!!");
      return;
    }
  }
  Serial.print((leftCount - getSecondsSW1()));
  Serial.print(" : ");
  Serial.print((rightCount - getSecondsSW2()));
  Serial.println();
  }
}

//stop and reset both stopwatches
void ChessClock::resetChessClock(){
    sw1.stop();
    sw2.stop();
    sw1.reset();
    sw2.reset();
    leftCount = 0;
    rightCount = 0;
}

void ChessClock::swapModes(){
  (mode == RESET) ? mode = PLAY : mode = RESET;
}


bool ChessClock::checkIfCanPress(){
  canPress = lockClock.elapsed() >= 1000; 
}

void ChessClock::resetLockClock(){
  lockClock.reset();
  lockClock.start();
}
void ChessClock::swapCanPress(){
  canPress = !canPress;
}
