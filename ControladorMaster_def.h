/*
 * ControladorMaster_def.h
 *
 *  Created on: 15 de mai de 2019
 *      Author: Administrador
 */

#ifndef CONTROLADORMASTER_DEF_H_
#define CONTROLADORMASTER_DEF_H_

#define _ON      true
#define _OFF     false
#define _DONE    true
#define _LATE    false

#define _BUTTON_PIN_ENTER 10
#define _BUTTON_PIN_ESC   11
#define _ENCODER_PIN_DT    3
#define _ENCODER_PIN_CLK   2
#define _BUZZER_PIN       12

#define _LED_PIN_AM       5
#define _LED_PIN_VM       6

#define _SERVO_PIN        16     // Porta Digital 6 PWM

//TODO - rever todos os pinos abaixo
#define _RELAY_00_PIN      2
#define _RELAY_01_PIN      2
#define _RELAY_02_PIN      2
#define _RELAY_03_PIN      2
#define _THERMOMETER_PIN   2

#define _TOMADA_LZ   0	// LUZ
#define _TOMADA_FT   1	// FILTRO
#define _TOMADA_AR   2	// AERADOR
#define _TOMADA_AQ   3  // AQUECEDOR

#define _AGENDA_LZ   0	// LUZ
#define _AGENDA_FT   1	// FILTRO
#define _AGENDA_AR   2	// AERADOR
#define _AGENDA_TP   3  // TPA
#define _AGENDA_AL   4  // ALIMENTADOR

#define _LCD_COLS 16
#define _LCD_ROWS 2



#endif /* CONTROLADORMASTER_DEF_H_ */
