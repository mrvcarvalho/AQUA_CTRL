/*
 * FoodDispenser.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */
#include "FoodDispenser.h"

FoodDispenser::FoodDispenser(/*Servo *p_Servo, uint8_t p_servoPin*/) {
	/*
	myServo = p_Servo;
	myServoPin = p_servoPin;
	*/
	MRVDEBUGLN(F("Construtor do FoodDispenser done"));


}

FoodDispenser::~FoodDispenser() {
	// TODO Auto-generated destructor stub
}

void FoodDispenser::setup(void) {
	Serial.println(F("SETUP FoodDispenser done"));
	// SERVO MOTOR ------------------------------------------------------
	myServo->attach(_SERVO_PIN /*myServoPin*/);
	myServo->write(_motorFeederPosition); // Inicia motor posição zero
	//myServo.detach();
	delay(1000);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER GO PARKING
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGoParking(void) {
	//servoFeeder.attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif

	int pos;
	if (_motorFeederPosition < 50) {
		for (pos = _motorFeederPosition; pos <= 50; pos += MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30+: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}
	if (_motorFeederPosition > 50) {
		for (pos = _motorFeederPosition; pos >= 40; pos -= MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30-: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}

	_motorFeederPosition = pos;
	//servoFeeder.detach();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER UP
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGoUp(void) {
	//servoFeeder.attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif

	int pos;
	for (pos = _motorFeederPosition; pos >= 0; pos -= MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
		myLCD->setCursor(0, 0); myLCD->print("ServoFeederGoUp: ");
		myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
		myServo->write(pos);
		delay(MOTOR_SPEED_DELAY);
	}

	_motorFeederPosition = pos;
	//servoFeeder.detach();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER GO 150
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGo150(void) {
	//servoFeeder.attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif

	int pos;
	if (_motorFeederPosition < 130) {
		for (pos = _motorFeederPosition; pos <= 130; pos += MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo150+: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}
	if (_motorFeederPosition > 130) {
		for (pos = _motorFeederPosition; pos >= 130; pos -= MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo150-: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}

	_motorFeederPosition = pos;
	//servoFeeder.detach();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER GO HALF
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGoHalf(void) {
	//servoFeeder.attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif
	//int n = 0;

	int pos;
	if (_motorFeederPosition < 90) {
		for (pos = _motorFeederPosition; pos <= 90; pos += MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30+: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
			//n += MOTOR_SPEED_DELAY;
			//if (n%50 ==0) servoFeeder.refresh();
		}
	}
	if (_motorFeederPosition > 90) {
		for (pos = _motorFeederPosition; pos >= 90; pos -= MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30-: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}

	_motorFeederPosition = pos;
	//servoFeeder.detach();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER GO 30
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGo30(void) {
	//myServo->attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif

	int pos;
	if (_motorFeederPosition < 50) {
		for (pos = _motorFeederPosition; pos <= 50; pos += MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30+: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}
	if (_motorFeederPosition > 50) {
		for (pos = _motorFeederPosition; pos >= 40; pos -= MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
			myLCD->setCursor(0, 0); myLCD->print("ServoFeederGo30-: ");
			myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
			myServo->write(pos);
			delay(MOTOR_SPEED_DELAY);
		}
	}

	_motorFeederPosition = pos;
	//servoFeeder.detach();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - FEEDER DOWN
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoFeederGoDown(void) {
	//servoFeeder.attach(SERVO);
#ifdef _DEBUG_
	myLCD->clear();
#endif

	int pos;
	for (pos = _motorFeederPosition; pos <= 180; pos += MOTOR_SPEED_STEP) {
#ifdef _DEBUG_
		myLCD->setCursor(0, 0); myLCD->print("ServoFeederGoDown: ");
		myLCD->setCursor(0, 1); myLCD->print(pos);myLCD->print("   ");
#endif
		myServo->write(pos);
		delay(MOTOR_SPEED_DELAY);
	}
	_motorFeederPosition = pos;
	//servoFeeder.detach();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::feedNow(void) {

	//servoFeeder.attach(SERVO);

	for (int c = 0; c < MOTOR_SHAKE_QTD_PORTIONS; c++) {

		// SHAKE IT UP
		ServoFeederGoUp();

		for (int m = 0; m < MOTOR_SHAKE_TIMES; m++) {
			ServoFeederGoHalf();
			ServoFeederGoUp();
		}
		delay(MOTOR_STOP_UP_TIME);

		for (int m = 0; m < MOTOR_SHAKE_TIMES; m++) {
			ServoFeederGoHalf();
			ServoFeederGoUp();
		}
		delay(MOTOR_STOP_UP_TIME);

		// SHAKE IT DOWN
		ServoFeederGoDown();
		delay(MOTOR_STOP_DOWN_TIME);

		for (int j = 0; j < MOTOR_SHAKE_TIMES; j++) {
			ServoFeederGoDown();
			ServoFeederGoHalf();
		}
		ServoFeederGoDown();
		delay(MOTOR_STOP_DOWN_TIME);

		for (int j = 0; j < MOTOR_SHAKE_TIMES; j++) {
			ServoFeederGoDown();
			ServoFeederGoHalf();
		}
		ServoFeederGoDown();
		delay(MOTOR_STOP_DOWN_TIME);
	}

	// PARKINK PLACE
	ServoFeederGoUp();
	delay(MOTOR_STOP_UP_TIME);
	ServoFeederGoParking();

	//servoFeeder.detach();

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOTOR - IM ALIVE
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FoodDispenser::ServoIAmAlive(int nTimes) {
	//servoFeeder.attach(SERVO);

	for (int c = 0; c < nTimes; c++) {
		ServoFeederGoUp();
		ServoFeederGo30();
	}

	//servoFeeder.detach();
}
