/*
 * Relay.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef LIBRARIES_RELAY_H_
#define LIBRARIES_RELAY_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include "ControladorMaster_def.h"

class Relay {
 protected:
	 int _pin;
	 bool _state;
	 bool _normallyOpen;

 public:
	 Relay();
	 Relay(int p, bool isNormallyOpen);
	 virtual ~Relay();


	 void begin();
	 bool getState();
	 void turnOn();
	 void turnOff();
};

#endif /* LIBRARIES_RELAY_H_ */
