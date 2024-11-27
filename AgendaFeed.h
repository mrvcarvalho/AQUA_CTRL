/*
 * AgendaFeed.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef AGENDAFEED_H_
#define AGENDAFEED_H_

#include <Arduino.h>
#include "mrv_Debug.h"

#include <RTClib.h>
#include "Agenda.h"

/*
#include "Alarm.h"
#include "FoodDispenser.h"
*/


extern class RTC_DS1307    *myRTC;
extern class Alarm         *myAlarm;
extern class FoodDispenser *myFoodDispenser;


// ALIMENTADOR - CONFIGURACAO E CONTROLE DO AGENDAMENTO
#define NUMBER_OF_PROGRAMS 6 // Quantidade de Programacao de Alimentacao

static uint8_t aLastFeedDayDone[NUMBER_OF_PROGRAMS];    // Last Day Done This Time

#define NOT_YET     0
#define ON_THE_TIME 1
#define EXPIRED     2

// CONTROLE DATA E HORA
#define _HORAS    3600L
#define _MINUTOS    60L
#define _SEGUNDOS    1L

#ifdef _DEBUG_
static uint32_t aFeedTime1[NUMBER_OF_PROGRAMS]=
                         { (  0L*_HORAS)+(35L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(  6L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,( 12L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,( 17L*_HORAS)+(45L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(18L*_HORAS)+(20L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(21L*_HORAS)+(20L*_MINUTOS)+(0L*_SEGUNDOS)
                          //,(20L*_HORAS)+(20L*_MINUTOS)+(0L*_SEGUNDOS)
                          //,(23L*_HORAS)+(20L*_MINUTOS)+(0L*_SEGUNDOS)
                          };
#else
static uint32_t aFeedTime1[NUMBER_OF_PROGRAMS]=
                         { ( 0L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,( 6L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,( 9L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(12L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(15L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          ,(18L*_HORAS)+( 0L*_MINUTOS)+(0L*_SEGUNDOS)
                          //,( 8L*_HORAS)+(13L*_MINUTOS)+(0L*_SEGUNDOS)
                          //,( 8L*_HORAS)+(14L*_MINUTOS)+(0L*_SEGUNDOS)
                          //,( 8L*_HORAS)+(15L*_MINUTOS)+(0L*_SEGUNDOS)
                          };
#endif

//--------------------------------------------------------------------------------

class AgendaFeed: public Agenda {
public:
	AgendaFeed(/*RTC_DS1307 *p_myRTC,
			   Alarm *p_myAlarm,
			   FoodDispenser *p_FoodDispenser*/);
	virtual ~AgendaFeed();

	void setup(void);
	uint8_t validaHorarioProgramado (int g, uint8_t today, uint8_t lastDayFeeded, uint32_t timeNow, uint32_t feedProgram, bool bAplicaTolerancia);
	uint32_t obtemDateTimeValidadoInt(void);
	void inicializaControleFeedTime(void);

    //FoodDispenser *myFoodDispenser;
};

#endif /* AGENDAFEED_H_ */
