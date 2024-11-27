 /*
 * CONTROLADOR DE AQUARIO 
 *
 * Contribuitions:
 * --------------
 * LiquidiMenu: https://github.com/VaSe7u/LiquidMenu
 * 
 * The CIRCUIT:
 * -----------
 * - LCD I2C MODULE SCL pin to Arduino pin A5
 * - LCD I2C MODULE SDA pin to Arduino pin A4
 * - LCD I2C MODULE GND pin to Arduino ground
 * - LCD I2C MODULE VCC pin to Arduino VCC (5V)
 * 
 * - ROTARY MODULE GND pin to Arduino ground
 * - ROTARY MODULE +   pin to Arduino VCC (5V)
 * - ROTARY MODULE SW  pin to Arduino pin 10 (button click = ENTER)
 * - ROTARY MODULE DT  pin to Arduino pin 2
 * - ROTARY MODULE CLK pin to Arduino pin 3
 * 
 * - ONE BUTTON MODULE + pin to Arduino ground
 * - ONE BUTTON MODULE - pin to Arduino VCC (5V)
 * - ONE BUTTON MODULE S pin to Arduino pin 9 (button click = ESC)
 * 
 * - RTC MODULE DS1307 SQ  pin (disconected)
 * - RTC MODULE DS1307 DS  pin (disconected)
 * - RTC MODULE DS1307 SCL pin to Arduino pin A5
 * - RTC MODULE DS1307 SDA pin to Arduino pin A4
 * - RTC MODULE DS1307 VCC pin to Arduino VCC (5V)
 * - RTC MODULE DS1307 GND pin to Arduino ground
 * - RTC MODULE DS1307 BAT pin (disconected)
 *
 *
 * LIBRARIES: 
 * ------------------------------------------------------------------------------------------------
 * name          = <Arduino.h>
 * ------------------------------------------------------------------------------------------------
 * name          = LiquidCrystal I2C (*CUSTOMIZED by mrvcarvalho)
 * version       = 1.1.2
 * author        = Frank de Brabander
 * maintainer    = Marco Schwartz <marcolivier.schwartz@gmail.com>
 * sentence      = A library for I2C LCD displays.
 * paragraph     = The library allows to control I2C displays with functions extremely similar to LiquidCrystal library. THIS LIBRARY MIGHT NOT BE COMPATIBLE WITH EXISTING SKETCHES.
 * category      = Display
 * url           = https://github.com/marcoschwartz/LiquidCrystal_I2C
 * architectures = avr
 * includes      =  <LiquidCrystal_I2C.h>
 * ------------------------------------------------------------------------------------------------
 * name          = LiquidMenu (*CUSTOMIZED by mrvcarvalho)
 * version       = 1.5.0
 * author        = Vasil Kalchev <vase7u@gmail.com>
 * maintainer    = Vasil Kalchev <vase7u@gmail.com>
 * sentence      = Menu creation Arduino library for LCDs, wraps LiquidCrystal.
 * paragraph     = LiquidMenu wraps the Arduino's LiquidCrystal library with the ability to create menus. It simplifies the menu creation process by abstracting the elements of a menu into hierarchically organized classes.
 * category      = Display
 * url           = https://github.com/VaSe7u/LiquidMenu
 * architectures = avr
 * dot_a_linkage = false
 * includes      = <LiquidMenu.h>
 * ------------------------------------------------------------------------------------------------
 * name          = Encoder (ROTARY ENCODER)
 * version       = 1.4.1
 * author        = Paul Stoffregen
 * maintainer    = Paul Stoffregen
 * sentence      = Counts quadrature pulses from rotary & linear position encoders.
 * paragraph     = Encoder counts pulses from quadrature encoded signals, which are commonly available from rotary knobs, motor or shaft sensors and other position sensors.
 * category      = Signal Input/Output
 * url           = http://www.pjrc.com/teensy/td_libs_Encoder.html
 * url           = https://github.com/PaulStoffregen/Encoder.git
 * architectures = *
 * ------------------------------------------------------------------------------------------------
 * name          = OneButton
 * version       = 1.3.0
 * author        = Matthias Hertel, mathertel@hotmail.com
 * maintainer    = Matthias Hertel <http://www.mathertel.de>
 * sentence      = Arduino libary for improving the usage of a singe input button.
 * paragraph     = It supports detecting events like single clicks, double clicks and long-time pressing. This enables you to reuse the same button for multiple functions and lowers the hardware invests.
 * category      = Signal Input/Output
 * url           = https://github.com/mathertel/OneButton
 * architectures = *
 * includes      = <OneButton.h>
 * license       = BSD-3-Clause
 * ------------------------------------------------------------------------------------------------
 * name          = RTClib - class RTC_DS1307
 * version       = 1.2.0
 * author        = Adafruit
 * maintainer    = Adafruit <info@adafruit.com>
 * sentence      = A fork of Jeelab's fantastic RTC library
 * paragraph     = A fork of Jeelab's fantastic RTC library
 * category      = Timing
 * url           = https://github.com/adafruit/RTClib
 * architectures = *
 * ------------------------------------------------------------------------------------------------
 * name          = <EEPROM.h>
 * version       = 2.0
 * author        = Arduino, Christopher Andrews
 * maintainer    = Arduino <info@arduino.cc>
 * sentence      = Enables reading and writing to the permanent board storage.
 * paragraph     = This library allows to read and write data in a memory type, the EEPROM, that keeps its content also when the board is powered off. The amount of EEPROM available depends on the microcontroller type.
 * category      = Data Storage
 * url           = http://www.arduino.cc/en/Reference/EEPROM
 * architectures = avr
 * ------------------------------------------------------------------------------------------------
 * name          = <Servo.h>
 * version       = 1.1.3
 * author        = Michael Margolis, Arduino
 * maintainer    = Arduino <info@arduino.cc>
 * sentence      = Allows Arduino/Genuino boards to control a variety of servo motors.
 * paragraph     = This library can control a great number of servos.<br />It makes careful use of timers: the library can control 12 servos using only 1 timer.<br />On the Arduino Due you can control up to 60 servos.<br />
 * category      = Device Control
 * url           = http://www.arduino.cc/en/Reference/Servo
 * architectures = avr,megaAVR,sam,samd,nrf52,stm32f4
 * ------------------------------------------------------------------------------------------------
 * name          = <Wire.h>
 * version       = 1.0
 * author        = Arduino
 * maintainer    = Arduino <info@arduino.cc>
 * sentence      = This library allows you to communicate with I2C and Two Wire Interface devices.
 * paragraph     = It allows the communication with I2C devices like temperature sensors, realtime clocks and many others using SDA (Data Line) and SCL (Clock Line).
 * category      = Communication
 * url           = http://www.arduino.cc/en/Reference/Wire
 * architectures = avr
  * ------------------------------------------------------------------------------------------------
 */
#include <MemoryFree.h>
#include <Arduino.h>
#include "mrv_Debug.h"

#include "ControladorMaster.h"

ControladorMaster* myControladorMaster;

void setup() {
	Serial.begin(115200);

  Serial.print(F("---ANTES DE ALOCAR TUDO O QUE PRECISA:-----------\nfreeMemory()="));
  Serial.println(freeMemory());
  Serial.println(F("--------------"));
  delay(5000);

	MRVDEBUGLN(F("-----RESET/INICIALIZACAO--AA---------------------------"));	printMemoryUsage();

	myControladorMaster = new ControladorMaster();

	MRVDEBUGLN(F("---CONTROLADOR MASTER INSTANCIADO OK---"));				printMemoryUsage();

	myControladorMaster->setup();
   
  Serial.print(F("---DEPOIS DE ALOCAR TUDO O QUE PRECISA:-----------\nfreeMemory()="));
  Serial.println(freeMemory());
  Serial.println(F("--------------"));

	MRVDEBUGLN(F("---CONTROLADOR setup () EXECUTOU OK---"));				printMemoryUsage();
}

void loop() {
	myControladorMaster->loop();
}
