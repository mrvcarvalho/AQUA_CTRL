/*
 * EEPROMSettingsKeeper.h
 *
 *  Created on: 9 de mai de 2019
 *      Author: Administrador
 */

#ifndef EEPROMSETTINGSKEEPER_H_
#define EEPROMSETTINGSKEEPER_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include <EEPROM.h>


class EEPROMSettingsKeeper {
public:
	EEPROMSettingsKeeper();
	virtual ~EEPROMSettingsKeeper();
	void save(void);
	void retrieve(void);
};

#endif /* EEPROMSETTINGSKEEPER_H_ */
