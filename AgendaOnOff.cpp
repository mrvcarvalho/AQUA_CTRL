/*
 * AgendaOnOff.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#include "AgendaOnOff.h"

AgendaOnOff::AgendaOnOff(/*RTC_DS1307 *p_myRTC,
						 Alarm *p_myAlarm,
						 Relay *p_Relay):Agenda(p_myRTC,p_myAlarm*/) {
	//myRelay = p_Relay;

	MRVDEBUGLN(F("Construtor do Agenda OnOff done"));
}

AgendaOnOff::~AgendaOnOff() {
}

