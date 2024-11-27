/*
 * UserInterface.cpp
 *
 *  Created on: 6 de mai de 2019
 *      Author: Administrador
 */

#include "UserInterface.h"

//UserInterface::UserInterface() {}

static long _encoderOldPosition = 0;

UserInterface::UserInterface(/*ControladorMaster *p_ControladorMaster,
		RTC_DS1307 *p_RTC, LiquidCrystal_I2C *p_LCD, LiquidMenu *p_Menu,
		MenuAQUA *p_MenuAQUA, ScreenSaver *p_ScreenSaver, OneButton *p_Esc,
		OneButton *p_Enter, Encoder *p_Encoder, Alarm *p_Alarm*/) {

	//myControladorMaster = p_ControladorMaster;
	//myAlarm = p_Alarm;
	//myRTC = p_RTC;
	//myLCD = p_LCD;
	//myEsc = p_Esc;
	//myEnter = p_Enter;
	//myEncoder = p_Encoder;
	//myMenuLiquid = p_Menu;
	//myMenuAQUA = p_MenuAQUA;
	//myScreenSaver = p_ScreenSaver;


	MRVDEBUGLN(F("Construtor do UserInterface done"));
}

UserInterface::~UserInterface() {

}

void UserInterface::setup(void) {
	MRVDEBUGLN(F("UserInterface::setup INICIOU"));	printMemoryUsage();

	myLCD->init();
	MRVDEBUGLN(F("SETUP LCD INIT done"));
	myLCD->backlight();
	MRVDEBUGLN(F("SETUP LCD BACKLIGHT done"));

	// Map rotary button to actions single and doubleclick.
	myEsc->attachClick(escSingleClick);
	MRVDEBUGLN(F("SETUP ESC ATTACHED done"));
	myEnter->attachClick(enterSingleClick);
	MRVDEBUGLN(F("SETUP ENTER ATTACHED done"));
	//myEnter->attachDoubleClick (???);
	//myEsc->attachDoubleClick (???);

	// TODO: Inicializar o encoder
	// myEncoder->

	MRVDEBUGLN(F("ANTES  do myMenuAQUA->setup()"));	printMemoryUsage();
	myMenuAQUA->setup();
	MRVDEBUGLN(F("DEPOIS do myMenuAQUA->setup()"));	printMemoryUsage();

	// TODO: Inicializar o LiquidMenu
	//myMenu->setup();

	// TODO: Inicializar o ScreenSaver
	// myScreenSaver->setup();

	MRVDEBUGLN(F("UserInterface::setup TERMINO"));	printMemoryUsage();
}

void UserInterface::loop(void) {
	MRVDEBUGLN(F("UserInterface::loop INICIOU"));	printMemoryUsage();

	myScreenSaver->check();

	// BUTTON - Listen to button presses.

	MRVDEBUGLN(F("myEnter->tick() ANTES"));	printMemoryUsage();

	myEnter->tick();

	MRVDEBUGLN(F("PRONTO O 1o"));	printMemoryUsage();

	myEsc->tick();

	MRVDEBUGLN(F("PRONTO O 2o"));	printMemoryUsage();

	// ROTARY - Listen if the rotary encoder moves.
	rotary_check();

	MRVDEBUGLN(F("rotary_check() DEPOIS"));	printMemoryUsage();

	MRVDEBUGLN(F("UserInterface::loop TERMINOU"));	printMemoryUsage();
}

void UserInterface::lcdPrintWithLeftZero(uint16_t mNumber) {
	if (mNumber < 10) {
		myLCD->print('0');
	}
	myLCD->print(mNumber);
}

void UserInterface::printDateTime(void) {
	MRVDEBUGLN(F("UserInterface::printDateTime INICIOU"));	printMemoryUsage();

	_dateTimeNow = myRTC->now();

	myLCD->clear();
	myLCD->setCursor(0, 0);
	myLCD->print("Data: ");
	lcdPrintWithLeftZero(_dateTimeNow.day());
	myLCD->print("/");
	lcdPrintWithLeftZero(_dateTimeNow.month());
	myLCD->print("/");
	lcdPrintWithLeftZero(_dateTimeNow.year());
	myLCD->setCursor(0, 1);
	myLCD->print("Hora: ");
	lcdPrintWithLeftZero(_dateTimeNow.hour());
	myLCD->print(":");
	lcdPrintWithLeftZero(_dateTimeNow.minute());
	myLCD->print(":");
	lcdPrintWithLeftZero(_dateTimeNow.second());

	MRVDEBUGLN(F("UserInterface::printDateTime TERMINO"));	printMemoryUsage();
}

void enterSingleClick(void) {
	if (!myScreenSaver->actionToAvoidOrReturnFromIt()) {
		return; //voltando do screenSaver
	}
	//MRVDEBUGLN(F("ENTER button pressed ONCE"));
	myAlarm->doBuzzerOneClick();
	myMenu->call_function(1);
	myMenuAQUA->get_currentMenuLineVariable();

	if (_LastConfigSettingVariable && !_CurrentConfigSettingVariable) {
		// SAIU DA ALTERACAO
		myAlarm->doBuzzerEscClick();
		myMenu->update();
	} else {
		myMenu->softUpdate();
	}

	return;
}
/*
 void enterDoubleClick(void) {
 if (!screenSaverActionToAvoidOrReturnFromIt()) {
 return; //voltando do screenSaver
 }
 MRVDEBUGLN(F("ENTER button pressed TWICE"));
 doBuzzerDoubleClick();
 menu->change_screen(*welcome_screen);
 get_currentMenuLineVariable();

 menu->softUpdate();

 return;
 }
 */

void escSingleClick(void) {
	if (!myScreenSaver->actionToAvoidOrReturnFromIt()) {
		return; //voltando do screenSaver
	}
	//DEBUG(F("ESC button pressed ONCE - |"));
	//DEBUG(F("currentScreen  0x")); DEBUG_FORMAT((uintptr_t)menu->get_currentScreen() , HEX);
	//DEBUG(F("|"));
	//DEBUG(F("welcome_screen 0x")); DEBUG_FORMAT((uintptr_t)welcome_screen, HEX);
	//MRVDEBUGLN(F("|"));
	//if (myMenu->get_currentScreen() == welcome_screen) {
	//  MRVDEBUGLN(F("Chegou no Topo dos Menus"));
	//  return;
	//}
	myAlarm->doBuzzerEscClick();
	myMenu->previous_screen();
	myMenuAQUA->get_currentMenuLineVariable();
	return;
}

void rotary_check(void) {
	MRVDEBUGLN(F("rotary_check() INICIOU"));	printMemoryUsage();

	/*
	if (_encoderOldPosition==0)	{		// TODO nao faz nada caso seja o início do sistema (??? verificar
		_encoderOldPosition = myEncoder->read();
		return;
	}
	*/

	long newPosition = myEncoder->read() / 4; // Constantly read the position of the rotary encoder
	if (newPosition != _encoderOldPosition) { // IF the new position of the encoder is different then the old position

		MRVDEBUGLN(F("PONTO 01"));

		if (!myScreenSaver->actionToAvoidOrReturnFromIt()) {
			return;
		} //voltando do screenSaver

		MRVDEBUGLN(F("PONTO 02"));

		myAlarm->doBuzzerRotarySpin();

		MRVDEBUGLN(F("PONTO 03"));

		if (newPosition < _encoderOldPosition) {

			MRVDEBUGLN(F("PONTO 04"));
			// BACKWARD
			if (_CurrentConfigSettingVariable) {
				alteraCurrentConfigSettingVariable(false);
				MRVDEBUGLN(F("PONTO 05"));
			} else {
				myMenu->switch_focus(false);
				MRVDEBUGLN(F("PONTO 06"));
			}
		} else {
			MRVDEBUGLN(F("PONTO 07"));
			// FORWARD
			if (_CurrentConfigSettingVariable) {
				alteraCurrentConfigSettingVariable(true);
				MRVDEBUGLN(F("PONTO 08"));
			} else {
				MRVDEBUGLN(F("PONTO 09"));
				myMenu->switch_focus(true);
			}
			MRVDEBUGLN(F("PONTO 10"));
		}
		_encoderOldPosition = newPosition;
		MRVDEBUGLN(F("PONTO 11"));
		if (!_CurrentConfigSettingVariable) { // Se nao estiver editando variaveis
			MRVDEBUGLN(F("PONTO 12"));
			myMenuAQUA->get_currentMenuLineVariable(); // atualiza a variavel que guarda a linha atual do MENU
		}
		//MYDEBUGx2LN( F("Rotary newPosition = "), newPosition);
		//int g = principal_screen->getFocus();
		//DEBUGx2LN( F("principal_screen.getFocus() = "), g );
	}

	MRVDEBUGLN(F("rotary_check() TERMINOU"));	printMemoryUsage();
}

void alteraCurrentConfigSettingVariable(bool next) {
	if (!_CurrentConfigSettingVariable) {
		return;
	}
	//MRVDEBUGLN(F("\nINO->p_CurrentConfigSettingVariable->getState()"));
	//MRVDEBUGLN( p_CurrentConfigSettingVariable->getState() );

	if (next) {
		_CurrentConfigSettingVariable->stateAdd();
	} else {
		_CurrentConfigSettingVariable->stateSub();
	}

	myMenu->softUpdate();
}
