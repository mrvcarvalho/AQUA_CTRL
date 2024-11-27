/*
 * FoodDispenser.h
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#ifndef FOODDISPENSER_H_
#define FOODDISPENSER_H_

#include <Arduino.h>
#include "mrv_Debug.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "ControladorMaster_def.h"

extern class Servo *myServo;

#define MOTOR_SPEED_STEP   5          // angle STEP
#define MOTOR_SPEED_DELAY 15          // delay betwwen STEPs
#define MOTOR_STOP_DOWN_TIME 1000     // delay DOWN
#define MOTOR_STOP_UP_TIME 1000       // delay UP BETWEEN
#define MOTOR_SHAKE_TIMES 5           // N TIMES SHAKING
#define MOTOR_SHAKE_QTD_PORTIONS 1    // N PORTIONS

class FoodDispenser {
public:
	FoodDispenser(/*Servo *p_Servo, uint8_t p_servoPin*/);
	virtual ~FoodDispenser();
	void setup(void);
	void ServoFeederGoParking(void);
	void ServoFeederGoUp(void);
	void ServoFeederGo150(void);
	void ServoFeederGoHalf(void);
	void ServoFeederGo30(void);
	void ServoFeederGoDown(void);
	void feedNow(void);
	void ServoIAmAlive(int nTimes);

	Servo *myServo;
	//uint8_t myServoPin;
	int _motorFeederPosition = 0;

};

#endif /* FOODDISPENSER_H_ */
