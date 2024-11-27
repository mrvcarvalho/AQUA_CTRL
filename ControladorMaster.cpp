/*
 * ControladorMaster.cpp
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#include "ControladorMaster.h"

// -----------------------------------------------------------------------------------------------------------------------------
// GLOBAL OBJECTS
// -----------------------------------------------------------------------------------------------------------------------------
Agenda *myAgenda[5];
FoodDispenser *myFoodDispenser;
Servo *myServo;
Thermostat *myTermostato;
Thermometer *myThermometer;
UserInterface *myUserInterface;
RTC_DS1307 *myRTC;
Alarm *myAlarm;
LiquidMenu *myMenu;
MenuAQUA *myMenuAQUA;
ScreenSaver *myScreenSaver;
LiquidCrystal_I2C *myLCD;
Relay *myRelay[4];
OneButton *myEsc;
OneButton *myEnter;
Encoder *myEncoder;
EEPROMSettingsKeeper *myEEPROMSettingsKeeper;


ControladorMaster::ControladorMaster() {

	myEEPROMSettingsKeeper = new EEPROMSettingsKeeper();								MRVDEBUGLN(F("NEW EEPROM done"));

	myRelay[_TOMADA_LZ] = new Relay(_RELAY_00_PIN, false); 								MRVDEBUGLN(F("NEW RELAY LZ done")); // (int port, bool isNormallyOpen)// LUZES
	myRelay[_TOMADA_FT] = new Relay(_RELAY_01_PIN, false);  							MRVDEBUGLN(F("NEW RELAY FT done"));// (int port, bool isNormallyOpen)  // FILTRO
	myRelay[_TOMADA_AR] = new Relay(_RELAY_02_PIN, false);  							MRVDEBUGLN(F("NEW RELAY AR done"));// (int port, bool isNormallyOpen)  // AR
	myRelay[_TOMADA_AQ] = new Relay(_RELAY_03_PIN, false);  							MRVDEBUGLN(F("NEW RELAY AQ done"));// (int port, bool isNormallyOpen)  // AQUECEDOR

	myEsc     = new OneButton  (_BUTTON_PIN_ESC,   true);								MRVDEBUGLN(F("NEW ESC done"));		printMemoryUsage();
	myEnter   = new OneButton  (_BUTTON_PIN_ENTER, true);								MRVDEBUGLN(F("NEW ENTER done"));	printMemoryUsage();
	myEncoder = new Encoder    (_ENCODER_PIN_DT, _ENCODER_PIN_CLK);						MRVDEBUGLN(F("NEW ENCODER done"));	printMemoryUsage();

	myLCD   = new LiquidCrystal_I2C (0x3F, _LCD_COLS, _LCD_ROWS);						MRVDEBUGLN(F("NEW LCD I2C done"));	printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myRTC   = new RTC_DS1307();															MRVDEBUGLN(F("NEW RTC done"));		printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myAlarm = new Alarm(/*_LED_PIN_AM, _LED_PIN_VM, _BUZZER_PIN*/);						MRVDEBUGLN(F("NEW ALARM done"));	printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myServo = new Servo();																MRVDEBUGLN(F("NEW SERVO done"));	printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myFoodDispenser      = new FoodDispenser(/*myServo, _SERVO_PIN*/);					MRVDEBUGLN(F("NEW FOOD_DISPENSER done"));				printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myAgenda[_AGENDA_LZ] = new AgendaOnOff(/*myRTC, myAlarm, myRelay[_TOMADA_LZ]*/);	MRVDEBUGLN(F("NEW AGENDA LUZES done")); 				printMemoryUsage(); // LUZES
	myAgenda[_AGENDA_FT] = new AgendaOnOff(/*myRTC, myAlarm, myRelay[_TOMADA_FT]*/);	MRVDEBUGLN(F("NEW AGENDA FILTRO done"));				printMemoryUsage(); // FILTRO
	myAgenda[_AGENDA_AR] = new AgendaOnOff(/*myRTC, myAlarm, myRelay[_TOMADA_AR]*/);	MRVDEBUGLN(F("NEW AGENDA AR done"));					printMemoryUsage(); // AR
	myAgenda[_AGENDA_TP] = new AgendaAlarm(/*myRTC, myAlarm*/);							MRVDEBUGLN(F("NEW AGENDA ALARM TPA done"));				printMemoryUsage(); // TPA
	myAgenda[_AGENDA_AL] = new AgendaFeed(/*myRTC, myAlarm, myFoodDispenser*/);			MRVDEBUGLN(F("NEW AGENDA FEED Alimentacao done"));		printMemoryUsage(); // ALIMENTADOR

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myThermometer = new Thermometer();													MRVDEBUGLN(F("NEW THERMOMETER done"));					printMemoryUsage();

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myTermostato = new Thermostat(/*myAlarm, myThermometer,
			(myRelay[_TOMADA_AQ])*/);													MRVDEBUGLN(F("NEW THERMOSTAT done"));					printMemoryUsage();

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myMenu = new LiquidMenu(*myLCD);													MRVDEBUGLN(F("NEW LIQUID MENU done"));					printMemoryUsage();

	myMenuAQUA = new MenuAQUA(/*myLCD, myMenu, myAlarm*/);								MRVDEBUGLN(F("NEW MENU AQUA done"));					printMemoryUsage();

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myScreenSaver = new ScreenSaver(/*myLCD, myMenu*/);									MRVDEBUGLN(F("NEW SCREEN SAVER done"));					printMemoryUsage();

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	myUserInterface = new UserInterface(/*this, myRTC, myLCD, myMenu,
			myMenuAQUA, myScreenSaver, myEsc, myEnter, myEncoder, myAlarm*/);			MRVDEBUGLN(F("NEW USER INTERFACE done"));				printMemoryUsage();
}

void ControladorMaster::doSelfTest(void) {
	int x=0,y=0;
	for (y=0;y<2;y++){
		for (x=0;x<16;x++){
			myLCD->clear();	myLCD->setCursor(0, 0);	myLCD->print(F("Testing LCD!"));
			if (x%4==0){ 				myLCD->noBacklight();		} else {				myLCD->backlight();			}
			if (x%3==0){				myLCD->blink_on();			} else {				myLCD->blink_off();			}
			if (x%2==0){				myLCD->cursor_on();			} else {				myLCD->cursor_off();		}
			myLCD->setCursor(x, y);
			myLCD->print(F("#"));

			myAlarm->doBuzzerRotarySpin();
			delay(100);
		}
	}
	myLCD->backlight();
	myLCD->blink_off();
	myLCD->cursor_off();



	myLCD->clear();
	myLCD->setCursor(0, 0);
	myLCD->print(F("Testing Buzzer!"));
	myAlarm->doBuzzerEscClick();delay(500);
	myAlarm->doBuzzerDoubleClick();delay(500);
	myAlarm->doBuzzerOneClick();delay(500);
	myAlarm->doBuzzerRotarySpin();delay(500);
	myAlarm->doBuzzerTurnON_OFF(true);delay(500);
	myAlarm->doBuzzerTurnON_OFF(false);delay(500);

	myLCD->clear();
	myLCD->setCursor(0, 0);
	myLCD->print(F("Testing LEDs!"));

	myAlarm->doLED_AM_Blink();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_VM_Blink();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_Blink_Both();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_AM_On();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_VM_On();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_AM_Off();delay(500);myAlarm->doBuzzerRotarySpin();
	myAlarm->doLED_VM_Off();delay(500);myAlarm->doBuzzerRotarySpin();

	myLCD->clear();
	myLCD->setCursor(0, 0);
	myLCD->print(F("END OF TESTS!"));
	delay(1000);

}


ControladorMaster::~ControladorMaster() {
	MRVDEBUGLN(F("#### DESTRUTOR GERAL DONE ####"));				printMemoryUsage();
	delete myUserInterface;
	delete myScreenSaver;
	delete myMenuAQUA;
	delete myMenu;
	delete myTermostato;
	delete myThermometer;
	delete myAgenda[4];
	delete myAgenda[3];
	delete myAgenda[2];
	delete myAgenda[1];
	delete myAgenda[0];
	delete myFoodDispenser;
	delete myServo;
	delete myAlarm;
	delete myRTC;
	delete myLCD;
	delete myEncoder;
	delete myEnter;
	delete myEsc;
	delete myRelay[3];
	delete myRelay[2];
	delete myRelay[1];
	delete myRelay[0];
	delete myEEPROMSettingsKeeper;
}

void ControladorMaster::setup(void) {

	MRVDEBUGLN(F("ANTES DO WIRE BEGIN done")); printMemoryUsage();
	Wire.begin();
	MRVDEBUGLN(F("DEPOIS DO WIRE BEGIN done")); printMemoryUsage();

	/* RTC */
	MRVDEBUGLN(F("ANTES  DO SETUP RTC BEGIN done")); printMemoryUsage();
	myRTC->begin();
	MRVDEBUGLN(F("DEPOIS DO SETUP RTC BEGIN done")); printMemoryUsage();

	MRVDEBUGLN(F("ANTES  DO myUserInterface->setup() done")); printMemoryUsage();
	myUserInterface->setup();
	MRVDEBUGLN(F("DEPOIS DO myUserInterface->setup() done")); printMemoryUsage();

	//#ifdef _DEBUG_
	//MRVDEBUGLN("RTC ajustando com a data e hora da compilacao (do sistema)...");

	MRVDEBUGLN(F("ANTES  DO myRTC->adjust done")); printMemoryUsage();
	myRTC->adjust(DateTime(F(__DATE__), F(__TIME__)));
	MRVDEBUGLN(F("DEPOIS DO myRTC->adjust done")); printMemoryUsage();
	//#endif

	MRVDEBUGLN(F("ANTES  DO myAlarm->setup() done")); printMemoryUsage();
	myAlarm->setup();
	MRVDEBUGLN(F("DEPOIS DO myAlarm->setup() done")); printMemoryUsage();

	// Apresenta da e hora na tela de abertura
	//DateTime _dateTimeNow = myRTC->now();

	doSelfTest();


	MRVDEBUGLN(F("ANTES  DO myUserInterface->printDateTime() done")); printMemoryUsage();
	myUserInterface->printDateTime();
	MRVDEBUGLN(F("DEPOIS DO myUserInterface->printDateTime() done")); printMemoryUsage();


	return;
}

void ControladorMaster::loop(void) {
	MRVDEBUGLN(F("ControladorMaster::loop INICIOU"));				printMemoryUsage();
	myUserInterface->loop();
	MRVDEBUGLN(F("ControladorMaster::loop TERMINOU"));				printMemoryUsage();
}
