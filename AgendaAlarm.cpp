/*
 * AgendaAlarm.cpp
 *
 *  Created on: 8 de mai de 2019
 *      Author: Administrador
 */

#include "AgendaAlarm.h"

AgendaAlarm::AgendaAlarm(/*RTC_DS1307 *p_myRTC, Alarm *p_myAlarm):Agenda(p_myRTC,p_myAlarm*/) {
	MRVDEBUGLN(F("Construtor do Agenda Alarm done"));
}

AgendaAlarm::~AgendaAlarm() {
}

