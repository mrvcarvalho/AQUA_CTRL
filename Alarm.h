/*
 * Alarm.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef ALARM_H_
#define ALARM_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include "ControladorMaster.h"
#include "pitches.h"

class Alarm {
public:
	Alarm(/*uint8_t p_ledPinAM, uint8_t p_ledPinVM, uint8_t p_buzzerPin*/);
	virtual ~Alarm();
	void setup(void);
	void loop(void);

	bool _state;

	// LED
	void doLED_AM_Blink(void);
	void doLED_VM_Blink(void);
	void doLED_Blink_Both(void);
	void doLED_AM_On();
	void doLED_VM_On();
	void doLED_AM_Off();
	void doLED_VM_Off();

	// BUZZER
	void doBuzzerRotarySpin(void);
	void doBuzzerEscClick(void);
	void doBuzzerDoubleClick(void);
	void doBuzzerOneClick(void);
	void doBuzzerTurnON_OFF(bool bStatus);

	//uint8_t _ledPinAM;
	//uint8_t _ledPinVM;
	//uint8_t _buzzerPin;
};

#endif /* ALARM_H_ */
