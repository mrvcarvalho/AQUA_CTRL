/*
 * ScreenSaver.cpp
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#include "ScreenSaver.h"

ScreenSaver::ScreenSaver() {
	_startMillis = millis();  //initial start time

	MRVDEBUGLN(F("Construtor do ScreenSaver done"));
}

//ScreenSaver::ScreenSaver(/*LiquidCrystal_I2C *p_LiquidCrystal_I2C, LiquidMenu *p_LiquidMenu):ScreenSaver(*/) {
	/*
	//myLCD  = p_LiquidCrystal_I2C;
	//myMenu = p_LiquidMenu;
	*/
//}

ScreenSaver::~ScreenSaver() {

}

//---------------------------------------------------------------------------------------------------------
// SCREENSAVER
//---------------------------------------------------------------------------------------------------------
bool ScreenSaver::actionToAvoidOrReturnFromIt(void) {
  // return TRUE  in case of could avoid screenSaver
  // return FALSE in case of returning from screenSaver
  _startMillis = millis();  //initial start time
  if (_bRunnedScreenSaver == true) {
	  myLCD->backlight();
	  myMenu->update();
    _bRunnedScreenSaver = false;
    return false;
  }
  return true;
}

void ScreenSaver::check(void) {
	MRVDEBUGLN(F("ScreenSaver::check INICOU"));				printMemoryUsage();
	if (millis() > (_startMillis + _SCREEN_SAVER_TIMEOUT)){
		run();
	}
	MRVDEBUGLN(F("ScreenSaver::check TERMINOU"));				printMemoryUsage();
}

void ScreenSaver::run(void) {

  _startMillis = millis();  //initial start time

  _bRunnedScreenSaver = true;
  myLCD->clear();
  myLCD->noBacklight();
}
