//tabs die niet onder eigen code vallen:
//StopWatch.cpp & StopWatch.h 
//Regels eigen code: 254 regels

/* 
  ALGEMENE INFORMATIE:
  deze code maakt het mogelijk om met 3 knoppen een schaak-klok te maken.
  de schaak-klok maakt het mogelijk om tijd per persoon in te stellen.
  deze tijd loopt af voor een speler wanneer de ander op zijn knop klikt en pauzeerd te tijd voor hem (doormiddel van de linkse en rechtse knoppen)
  de middelste knop (start/reset) wordt gebruikt om te starten wanneer de tijden zijn ingesteld of om de tijden te resetten.
  de functie printTimers() in Main is de enige functie die het printen regelt, hier is bewust voor gekozen om uitbreiding met een LCD gemakkelijk te maken.
  verder houdt de schaak-klok bij wanneer er een speler gewonnen heeft (wanneer er geen tijd meer is).
  de klok hoeft niet opnieuw worden opgestart om een nieuw potje te beginnen dit kan doormiddel van de reset knop.
  commentaar is aanwezig bij belangrijke functies in het Engels.
*/

#include "Controller.h"
#include "ChessClock.h"

Controller* control;
ChessClock* cc;

void setup() {
Serial.begin(9600);
control = new Controller(2,4,3); //l - r - sr
cc = new ChessClock();
}

void loop() {
  //checks which button is pressed and let ChessClock decide the current action to take
  if(control->getInputL()){
  cc->leftPressed();
  }
  
  if(control->getInputSR()) {
    cc->srPressed();
  }
  if(control->getInputR()) {
  cc->rightPressed();
  }  
  //always print timers (can be replaced by LCD print functions if hardware available)
  cc->printTimers();
}
