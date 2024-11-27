/*
 * MenuAQUACTRL.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef MENUAQUA_H_
#define MENUAQUA_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>
#include "Alarm.h"
#include "ControladorMaster_def.h"

extern class LiquidCrystal_I2C *myLCD;
extern class LiquidMenu        *myMenu;
extern class Alarm             *myAlarm;

class MenuAQUA {
public:
	MenuAQUA(/*LiquidCrystal_I2C *p_LCD, LiquidMenu *p_MenuLiquid, Alarm *p_Alarm*/);
	virtual ~MenuAQUA();
	void setup(void);

	void get_currentMenuLineVariable(void);

	//LiquidMenu * getMainLiquidMenu(void);

	//Alarm             *myAlarm;
	//LiquidCrystal_I2C *myLCD;
	//LiquidMenu        *myMenu;
};

#endif /* MENUAQUA_H_ */
