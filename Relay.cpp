/*
 * Relay.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#include "Relay.h"

Relay::Relay(int p_Pin, bool isNormallyOpen){
	_pin          = p_Pin;
	_normallyOpen = isNormallyOpen;
	_state        = isNormallyOpen;
	MRVDEBUGLN(F("Construtor do Relay done"));
}

Relay::~Relay() {
	// TODO Auto-generated destructor stub
}

void Relay::begin(){
	pinMode(_pin, OUTPUT);
}

bool Relay::getState(){
	if (_normallyOpen){
		return !_state;
	}
	else {
		return _state;
	}
}
void Relay::turnOn(){
	if (_normallyOpen){
		if (_state == !true) return;
		_state = !true;
	} else {
		if (_state == true) return;
		_state = true;
	}
	digitalWrite(_pin, _state);
}
void Relay::turnOff(){
	if (_normallyOpen){
		if (_state == !false) return;
		_state = !false;
	} else {
		if (_state == false) return;
		_state = false;
	}
	digitalWrite(_pin, _state);
}
