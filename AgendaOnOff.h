/*
 * AgendaOnOff.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef AGENDAONOFF_H_
#define AGENDAONOFF_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include "Agenda.h"

#include <RTClib.h>
#include "Alarm.h"
#include "Relay.h"

extern class RTC_DS1307 *myRTC;
extern class Alarm      *myAlarm;
extern class Relay      *myRelay[4];

class AgendaOnOff: public Agenda {
public:
	AgendaOnOff(/*RTC_DS1307 *p_myRTC,
			    Alarm *p_myAlarm,
				Relay *p_Relay*/);
	virtual ~AgendaOnOff();

	//Relay *myRelay;
};

#endif /* AGENDAONOFF_H_ */
