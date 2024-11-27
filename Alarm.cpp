/*
 * Alarm.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#include "Alarm.h"

Alarm::Alarm(/*uint8_t p_ledPinAM, uint8_t p_ledPinVM, uint8_t p_buzzerPin*/) {
	_state = false; // OFF

	//_ledPinAM = _LED_PIN_AM; //p_ledPinAM;
	//_ledPinVM = _LED_PIN_VM; //p_ledPinVM;
	//_buzzerPin = _BUZZER_PIN; //p_buzzerPin;

	MRVDEBUGLN(F("Construtor do Alarm done")); 				printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);
}

Alarm::~Alarm() {
}

void Alarm::setup(void) {
	MRVDEBUGLN(F("SETUP Alarm done"));
	pinMode(_BUZZER_PIN, OUTPUT);
	pinMode(_LED_PIN_AM, OUTPUT);
	pinMode(_LED_PIN_VM, OUTPUT);
}

void Alarm::doLED_AM_Blink(void) {
	// TODO fazer o blink de verdade com o mills / loop finction
	digitalWrite(_LED_PIN_AM, HIGH);
	delay(200);
	digitalWrite(_LED_PIN_AM, LOW);
	return;
}

void Alarm::doLED_VM_Blink(void) {
	// TODO fazer o blink de verdade com o mills / loop finction
	digitalWrite(_LED_PIN_VM, HIGH);
	delay(200);
	digitalWrite(_LED_PIN_VM, LOW);
	return;
}

void Alarm::doLED_Blink_Both(void) {
	doLED_AM_Blink();
	doLED_VM_Blink();
	return;
}

void Alarm::doLED_AM_On() {
	digitalWrite(_LED_PIN_AM, HIGH); // turn the LED on (HIGH is the voltage level)
}

void Alarm::doLED_VM_On() {
	digitalWrite(_LED_PIN_VM, HIGH); // turn the LED on (HIGH is the voltage level)
}

void Alarm::doLED_AM_Off() {
	digitalWrite(_LED_PIN_AM, LOW); // turn the LED off by making the voltage LOW
}
void Alarm::doLED_VM_Off() {
	digitalWrite(_LED_PIN_VM, LOW); // turn the LED off by making the voltage LOW
}

void Alarm::doBuzzerRotarySpin(void) {
	digitalWrite(_BUZZER_PIN, HIGH);
	delay(1);
	digitalWrite(_BUZZER_PIN, LOW);
	return;
}

void Alarm::doBuzzerEscClick(void) {
	tone(_BUZZER_PIN, NOTE_A5, 20);
	doBuzzerRotarySpin();
	return;
}

void Alarm::doBuzzerDoubleClick(void) {
	tone(_BUZZER_PIN, NOTE_D3, 20);
	doBuzzerRotarySpin();
	return;
}

void Alarm::doBuzzerOneClick(void) {
	doBuzzerRotarySpin();
	tone(_BUZZER_PIN, NOTE_D3, 20);
	doBuzzerRotarySpin();

	return;
}

void Alarm::doBuzzerTurnON_OFF(bool bStatus) {
	if (bStatus) {
		// ON = true
		tone(_BUZZER_PIN, NOTE_D6, 20);
	} else {
		// OFF = false
		tone(_BUZZER_PIN, NOTE_D4, 20);
	}
	doBuzzerRotarySpin();
	return;
}
