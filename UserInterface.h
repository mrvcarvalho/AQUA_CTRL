/*
 * UserInterface.h
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <OneButton.h>
#include <Encoder.h>
#include <LiquidMenu.h>
#include "MenuAQUA.h"

/*
#include "ScreenSaver.h"
#include "Alarm.h"

#include "ControladorMaster_def.h"
*/

extern class OneButton         *myEsc;
extern class OneButton         *myEnter;
extern class Encoder           *myEncoder;
extern class MenuAQUA          *myMenuAQUA;
extern class LiquidCrystal_I2C *myLCD;
extern class LiquidMenu        *myMenu;
extern class ScreenSaver       *myScreenSaver;
extern class RTC_DS1307        *myRTC;
extern class Alarm             *myAlarm;

extern class LiquidLine*    _CurrentMenuLine;
extern class LiquidLine*    _LastMenuLine;
extern class ConfigSetting* _CurrentConfigSettingVariable;
extern class ConfigSetting* _LastConfigSettingVariable;

// PUSH BUTTONS
void enterSingleClick(void);
//static void enterDoubleClick(void);
void escSingleClick  (void);
//static void escDoubleClick(void);

// ROTARY ENCODER
void rotary_check(void);
void alteraCurrentConfigSettingVariable(bool next);

class UserInterface {
public:
	//UserInterface();
	UserInterface(/*ControladorMaster *p_ControladorMaster,
			      RTC_DS1307        *p_RTC,
     			  LiquidCrystal_I2C *p_LCD,
			      LiquidMenu        *p_LiquidMenu,
				  MenuAQUA          *p_MenuAQUA,
				  ScreenSaver 	    *p_ScreenSaver,
          		  OneButton         *p_Esc,
	     		  OneButton         *p_Enter,
	     		  Encoder           *p_Encoder,
	     		  Alarm             *p_Alarm*/);
	virtual ~UserInterface();
	void setup (void);
	void loop (void);
	void lcdPrintWithLeftZero(uint16_t mNumber);
	void printDateTime(void);



private:
	DateTime 	  	  _dateTimeNow;


	//RTC_DS1307 	      *myRTC;
    //OneButton         *myEsc;
    //OneButton         *myEnter;
    //Encoder           *myEncoder;
    //MenuAQUA          *myMenuAQUA;
    //LiquidMenu        *myMenu;
    //LiquidCrystal_I2C *myLCD;
    //ScreenSaver 	  *myScreenSaver;
    //Alarm             *myAlarm;
    //ControladorMaster *myControladorMaster;
};

#endif /* USERINTERFACE_H_ */
