/*
 * Termostato.h
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#ifndef THERMOSTAT_H_
#define THERMOSTAT_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include "Alarm.h"
#include "Relay.h"
#include "Thermometer.h"

extern class Relay        *myRelay[4];
extern class Thermometer  *myThermometer;
extern class Alarm		  *myAlarm;

class Thermostat {
public:
	Thermostat(/*Alarm *p_myAlarm, Thermometer *p_Thermometer, Relay *p_Relay*/);
	virtual ~Thermostat();

	/*
	Relay       *myRelay;
	Thermometer *myThermometer;
	Alarm       *myAlarm;
	*/
};

#endif /* THERMOSTAT_H_ */
