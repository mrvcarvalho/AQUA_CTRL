/*
 * Agenda.h
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <Arduino.h>
#include "mrv_Debug.h"

extern class RTC_DS1307 *myRTC;
extern class Alarm      *myAlarm;

class Agenda {
public:
	Agenda(/*RTC_DS1307 *p_myRTC, Alarm *p_myAlarm*/);
	virtual ~Agenda();

protected:
	//RTC_DS1307 *myRTC;
    //Alarm *myAlarm;

private:

};

#endif /* AGENDA_H_ */
