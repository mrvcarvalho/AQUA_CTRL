/*
 * AgendaAlarm.h
 *
 *  Created on: 8 de mai de 2019
 *      Author: Administrador
 */

#ifndef AGENDAALARM_H_
#define AGENDAALARM_H_

#include <Arduino.h>
#include "mrv_Debug.h"

#include "Agenda.h"

class Alarm;

class AgendaAlarm: public Agenda {
public:
	AgendaAlarm(/*RTC_DS1307 *p_myRTC, Alarm *p_myAlarm*/);
	virtual ~AgendaAlarm();
};

#endif /* AGENDAALARM_H_ */
