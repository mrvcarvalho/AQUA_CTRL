/*
 * AgendaFeed.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */
#include "AgendaFeed.h"

// CONTROLE DATA E HORA
unsigned long previousMillis =     0;
const long interval          = 10000;
int indexOfTheNextFeedTime   =     0;

AgendaFeed::AgendaFeed(/*RTC_DS1307 *p_myRTC,
			 	 	   Alarm *p_myAlarm,
					   FoodDispenser *p_FoodDispenser
):Agenda(p_myRTC,p_myAlarm*/) {

	//myFoodDispenser = p_FoodDispenser;
	MRVDEBUGLN(F("Construtor do Agenda Feed done"));

}

AgendaFeed::~AgendaFeed() {
}

void AgendaFeed::setup(void){

	MRVDEBUGLN(F("SETUP AgendaFeed precisa implementar"));

  //inicializaControleFeedTime();

  /*
  if (! rtc.isrunning()) {
    MRVDEBUGLN("Ajustou Data e Hora 2");

    MRVDEBUGLN("\n#RTC esta parado, ajustando com a data e hora da compilacao...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  */
  //OU
  /*
  MRVDEBUGLN("Ajustou Data e Hora 3");
  DateTime *dttm = new DateTime(2019, 4, 17, 0, 25, 0);
  rtc.adjust(*dttm);
  */
}

// FUNCAO EM DESUSO
/*
void printnn(uint16_t mNumber) {
  if (mNumber < 10) Serial.print('0');
  Serial.print(mNumber);
}
*/



uint8_t AgendaFeed::validaHorarioProgramado (int g, uint8_t today, uint8_t lastDayFeeded, uint32_t timeNow, uint32_t feedProgram, bool bAplicaTolerancia){
  uint8_t ret_ = NOT_YET;

  // Horario atual < horario programado ?
  if (today > lastDayFeeded && timeNow < feedProgram ) {
    ret_ = NOT_YET;
  }

  // Horario atual >= horario programado ?
  if (today > lastDayFeeded && timeNow >= feedProgram) {
    if (!bAplicaTolerancia) {
      ret_ = ON_THE_TIME;
    }

    // Esta dentro do tempo de tolerancia ?
    // Horario programado vencido a menos de 1 HORA
    if ((timeNow - feedProgram) <= (1*_HORAS)) {
       ret_ = ON_THE_TIME;
    } else {
       ret_ = EXPIRED;
    }
  }

  #ifdef _DEBUG_
      Serial.print("\n#PROGRAMA : ");           Serial.print(g);
      Serial.print(", TODAY : ");               Serial.print(today);
      Serial.print(", LASTDAY FEED : ");        Serial.print(lastDayFeeded);
      Serial.print(", NOW MINUTES : ");         Serial.print(timeNow);
      Serial.print(", PROGRAMED MINUTES : ");   Serial.print(feedProgram);
      Serial.print(", TOLERANCE ACCEPTED : ");  Serial.print(bAplicaTolerancia);
      Serial.print(", RET : ");                 Serial.print(ret_);
  #endif

  return ret_;
}

uint32_t AgendaFeed::obtemDateTimeValidadoInt(void) {
   DateTime dateTimeNow = myRTC->now(); //obtemDateTimeValidadoDateTime();
   return ((dateTimeNow.hour()*_HORAS)+(dateTimeNow.minute()*_MINUTOS)+(dateTimeNow.second()*_SEGUNDOS));
}

void AgendaFeed::inicializaControleFeedTime(void) {
  DateTime dateTimeNow = myRTC->now();
  uint32_t dateTimeIntNow = obtemDateTimeValidadoInt();

  #ifdef _DEBUG_
  Serial.print("\n-----------------------------------------------------");
  Serial.print("\n# INICIALIZACAO DO SISTEMA - VALIDANDO PROGRAMACOES");
  Serial.print("\n-----------------------------------------------------");
  #endif

  // Inicializa Array de Controle
  for (int g=0; g<NUMBER_OF_PROGRAMS; g++){

    // Para os horarios NOT_YET     seta flag = 0
    // Para os horarios ON_THE_TIME seta flag = 0
    // Para os horarios EXPIRED     seta flag = DIA (hoje)

    switch (validaHorarioProgramado (g, dateTimeNow.day(), aLastFeedDayDone[g], dateTimeIntNow, aFeedTime1[g], true)) {
      case NOT_YET:
      case ON_THE_TIME:
        aLastFeedDayDone[g]=0;
        break;
      case EXPIRED:
        aLastFeedDayDone[g]=dateTimeNow.day();
        break;
    }
  }

  // Identifica o proximo horario programado (nesta inicializacao)
  for (int g=NUMBER_OF_PROGRAMS-1; g>=0; g--){
    if (aLastFeedDayDone[g]==0) {
       indexOfTheNextFeedTime=g;
    }
  }
}
