/*
 * EEPROMSettingsKeeper.cpp
 *
 *  Created on: 9 de mai de 2019
 *      Author: Administrador
 */

#include "EEPROMSettingsKeeper.h"

EEPROMSettingsKeeper::EEPROMSettingsKeeper() {
	MRVDEBUGLN(F("Construtor do EEPROMSettingsKeeper done"));
}
EEPROMSettingsKeeper::~EEPROMSettingsKeeper() {

}
void EEPROMSettingsKeeper::save(void) {
	struct MyObject {
		float field1;
		byte field2;
		char name[10];
	};

	float f = 123.456f;  //Variable to store in EEPROM.
	int eeAddress = 0;   //Location we want the data to be put.

	//One simple call, with the address first and the object second.
	EEPROM.put(eeAddress, f);

	MRVDEBUGLN("Written float data type!");

	/** Put is designed for use with custom structures also. **/

	//Data to store.
	MyObject customVar = { 3.14f, 65, "Working!" };

	eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

	EEPROM.put(eeAddress, customVar);
	Serial.print(
			"Written custom data type! \n\nView the example sketch eeprom_get to see how you can retrieve the values!");
}
void EEPROMSettingsKeeper::retrieve(void) {

	float f = 0.00f;   //Variable to store data read from EEPROM.
	int eeAddress = 0; //EEPROM address to start reading from

	Serial.print("Read float from EEPROM: ");

	//Get the float data from the EEPROM at position 'eeAddress'
	EEPROM.get(eeAddress, f);
	MRVDEBUGLN_FORMAT(f, 3); //This may print 'ovf, nan' if the data inside the EEPROM is not a valid float.

	/***
	 As get also returns a reference to 'f', you can use it inline.
	 E.g: Serial.print( EEPROM.get( eeAddress, f ) );
	 ***/

	/***
	 Get can be used with custom structures too.
	 I have separated this into an extra function.
	 ***/

	struct MyObject {
		float field1;
		byte field2;
		char name[10];
	};

	eeAddress = sizeof(float); //Move address to the next byte after float 'f'.

	MyObject customVar; //Variable to store custom object read from EEPROM.
	EEPROM.get(eeAddress, customVar);

	MRVDEBUGLN("Read custom object from EEPROM: ");
	MRVDEBUGLN(customVar.field1);
	MRVDEBUGLN(customVar.field2);
	MRVDEBUGLN(customVar.name);

}
