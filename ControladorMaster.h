/*
 * ControladorMaster.h
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#ifndef CONTROLADORMASTER_H_
#define CONTROLADORMASTER_H_

#include <Arduino.h>
#include "mrv_Debug.h"

#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>
#include <Wire.h>
#include <RTClib.h>
#include <OneButton.h>
#include <Encoder.h>
#include <Servo.h>
#include "Alarm.h"
#include "Agenda.h"
#include "AgendaFeed.h"
#include "AgendaOnOff.h"
#include "AgendaAlarm.h"
#include "UserInterface.h"
#include "Thermostat.h"
#include "Thermometer.h"
#include "FoodDispenser.h"
#include "Relay.h"
#include "MenuAQUA.h"
#include "ScreenSaver.h"
#include "EEPROMSettingsKeeper.h"

#include "ControladorMaster_def.h"

class Agenda;
class Thermostat;
class Thermometer;
class UserInterface;
class RTC_DS1307;
class Alarm;
class LiquidMenu;
class FoodDispenser;
class LiquidCrystal_I2C;
class Relay;
class OneButton;
class Encoder;
class MenuAQUA;
class ScreenSaver;
class Servo;
class EEPROMSettingsKeeper;

class ControladorMaster {
public:
	ControladorMaster();
	virtual ~ControladorMaster();
	void setup(void);
	void loop(void);
	void doSelfTest(void);

private:

	//DateTime 	  _dateTimeNow;

};

#endif /* CONTROLADORMASTER_H_ */
