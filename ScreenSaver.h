/*
 * ScreenSaver.h
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#ifndef SCREENSAVER_H_
#define SCREENSAVER_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>
#include "ControladorMaster_def.h"

#define _SCREEN_SAVER_TIMEOUT 180000   // the value is a number of milliseconds

extern class LiquidCrystal_I2C *myLCD;
extern class LiquidMenu        *myMenu;

class ScreenSaver {
public:
	//ScreenSaver();
	ScreenSaver(/*LiquidCrystal_I2C *p_LiquidCrystal_I2C, LiquidMenu *p_LiquidMenu*/);
	virtual ~ScreenSaver();
	bool actionToAvoidOrReturnFromIt(void);
	void run(void);
	void check(void);
private:

	//LiquidCrystal_I2C *myLCD              = nullptr;
	//LiquidMenu        *myMenu             = nullptr;

	unsigned long 	  _startMillis        = 0;
	bool              _bRunnedScreenSaver = false;

};

#endif /* SCREENSAVER_H_ */
