/*
 * MenuAQUACTRL.cpp
 *
 *  Created on: 7 de mai de 2019
 *      Author: Administrador
 */

#include "MenuAQUA.h"

/* TODO:
	1o uso = SETUP GUIADO =
	DATA e Hora (eprom)

	Tipo de Aquario    ?
	Doce / Salgada     ?

	Manual / Autmatico ?
	Bomba
	AR
	LUZ

	Temperatura Target
	c/ variacao +/- ex 1grau
	min / max

	Alimentacao Comida
	Programacoes

	etc
*/

// -----------------------------------------------------------------------------------------------------------------------------
// CLASSES DE CONFIGURACOES GERAIS PARA O SISTEMA
// -----------------------------------------------------------------------------------------------------------------------------
bool  bStatusLuzes;     // LUZES DO AQUARIO
bool  bStatusAr;        // BOMBA DE AERACAO
bool  bStatusFiltro;    // BOMBA DE FILTRAGEM
bool  bStatusAquecedor; // TERMOSTATO / AQUECEDOR
bool  bStatusTPA;       // TROCA PARCIAL DE AGUA
float fStatusTemp;      // TERMOMETRO / TEMPERATURA
//int   iStatusLastComida;


// -----------------------------------------------------------------------------------------------------------------------------
// GETTERS - STATUS
// -----------------------------------------------------------------------------------------------------------------------------
const char* getStatusLuzes      (void);
const char* getStatusAr         (void);
const char* getStatusFiltro     (void);
const char* getStatusAquecedor  (void);
const char* getStatusTPA        (void);
float       getStatusTemperatura(void);

// -----------------------------------------------------------------------------------------------------------------------------
// SETTERS - SWITCH STATUS
// -----------------------------------------------------------------------------------------------------------------------------
void switchStatusLuzes         (void);
void switchStatusAr            (void);
void switchStatusFiltro        (void);
void switchStatusAquecedor     (void);
void switchStatusTPA           (void);

// -----------------------------------------------------------------------------------------------------------------------------
// GOTO MENU SCREEN
// -----------------------------------------------------------------------------------------------------------------------------
void blankFunction             (void);
void gotoConfiguracaoScreen    (void);
void nextScreen                (void);
void gotoPrincipalScreen       (void);
void gotoDataHoraDetalheScreen (void);
void gotoXYZ                   (void);

// -----------------------------------------------------------------------------------------------------------------------------
// MENU DO SISTEMA
// -----------------------------------------------------------------------------------------------------------------------------
LiquidLine*    _CurrentMenuLine;
LiquidLine*    _LastMenuLine;
ConfigSetting* _CurrentConfigSettingVariable;
ConfigSetting* _LastConfigSettingVariable;

// SCREEN BEM-VINDO
LiquidScreen* welcome_screen;
LiquidLine*   welcome_line1;
LiquidLine*   welcome_line2;

// SCREEN MENU PRINCIPAL
LiquidScreen* principal_screen;//<----------------------------------------------
LiquidLine*   principal_line_LUZ;
LiquidLine*   principal_line_FILTRO;
LiquidLine*   principal_line_AR;
LiquidLine*   principal_line_AQUEC;
LiquidLine*   principal_line_TEMP;
LiquidLine*   principal_line_TPA;
LiquidLine*   principal_line_CONFIG;
LiquidScreen* configuracao_screen;//<----------------------------------------------
LiquidLine*   configuracao_line_DATAHORA;
LiquidLine*   configuracao_line_LUZ;
LiquidLine*   configuracao_line_FILTRO;
LiquidLine*   configuracao_line_AR;
LiquidLine*   configuracao_line_ALIMENTO;
LiquidLine*   configuracao_line_TEMP;
LiquidLine*   configuracao_line_TPA;

LiquidScreen* detalhe_DATAHORA_screen;//<----------------------------------------------
LiquidLine*   detalhe_DATAHORA_line_DATA;
LiquidLine*   detalhe_DATAHORA_line_HORA;
LiquidScreen* detalhe_LUZ_screen;//<----------------------------------------------
LiquidLine*   detalhe_LUZ_line_titulo;
LiquidLine*   detalhe_LUZ_line_detalhe;
LiquidScreen* detalhe_FILTRO_screen;  //<----------------------------------------------
LiquidLine*   detalhe_FILTRO_line_titulo;
LiquidLine*   detalhe_FILTRO_line_detalhe;
LiquidScreen* detalhe_AR_screen;  //<----------------------------------------------
LiquidLine*   detalhe_AR_line_titulo;
LiquidLine*   detalhe_AR_line_detalhe;
LiquidScreen* detalhe_ALIMENTO_screen;  //<----------------------------------------------
LiquidLine*   detalhe_ALIMENTO_line_titulo;
LiquidLine*   detalhe_ALIMENTO_line_detalhe1;
LiquidLine*   detalhe_ALIMENTO_line_detalhe2;
LiquidLine*   detalhe_ALIMENTO_line_detalhe3;
LiquidLine*   detalhe_ALIMENTO_line_detalhe4;
LiquidLine*   detalhe_ALIMENTO_line_detalhe5;
LiquidLine*   detalhe_ALIMENTO_line_detalhe6;
LiquidScreen* detalhe_TEMPERATURA_screen;  //<----------------------------------------------
LiquidLine*   detalhe_TEMPERATURA_line_titulo;
LiquidLine*   detalhe_TEMPERATURA_line_minimo;
LiquidLine*   detalhe_TEMPERATURA_line_maximo;
LiquidScreen* detalhe_TPA_screen;  //<----------------------------------------------
LiquidLine*   detalhe_TPA_line_titulo;
LiquidLine*   detalhe_TPA_line_periodicidade;
LiquidLine*   detalhe_TPA_line_ultimaVez;

// -----------------------------------------------------------------------------------------------------------------------------
// MENU
// -----------------------------------------------------------------------------------------------------------------------------
const static char PROGMEM aCustomCharCELCIUS[8] = {0b01000, 0b10100, 0b01000, 0b00011, 0b00100, 0b00100, 0b00011, 0b00000,};
const static char PROGMEM aCCustomCharWATCH[8]  = {0b01110, 0b01110, 0b11011, 0b10001, 0b10001, 0b11011, 0b01110, 0b01110,};
const static char PROGMEM aCustomCharBELL[8]    = {0b00000, 0b00100, 0b01110, 0b01110, 0b11111, 0b11111, 0b00100, 0b00000,};
const static char PROGMEM aCustomCharDONE[8]    = {0b00000, 0b00000, 0b00000, 0b00001, 0b00010, 0b10100, 0b01000, 0b00000,};
const static char PROGMEM aCustomCharFF[8]      = {0b11011, 0b10010, 0b10010, 0b11011, 0b10010, 0b10010, 0b10010, 0b00000,};
const static char PROGMEM aCcustomCharGOOD[8]   = {0b00000, 0b01010, 0b01010, 0b01010, 0b00000, 0b10001, 0b01110, 0b00000,};
const static char PROGMEM aCustomCharBAD[8]     = {0b00000, 0b01010, 0b01010, 0b01010, 0b00000, 0b01110, 0b10001, 0b00000,};
const static char PROGMEM aCustomCharSTRANGE[8] = {0b01000, 0b01010, 0b01010, 0b00010, 0b10000, 0b01000, 0b00100, 0b00010,};

// CARACTERES CUSTOMIZADOS
#define CUSTOM_CARACTER_CELSIUS (uint8_t)0
#define CUSTOM_CARACTER_WATCH   (uint8_t)1
#define CUSTOM_CARACTER_BELL    (uint8_t)2
#define CUSTOM_CARACTER_DONE    (uint8_t)3
#define CUSTOM_CARACTER_FF      (uint8_t)4
#define CUSTOM_CARACTER_GOOD    (uint8_t)5
#define CUSTOM_CARACTER_BAD     (uint8_t)6
#define CUSTOM_CARACTER_STRANGE (uint8_t)7

//TODO: Colocar estas variaveis em PROGMEM assim que possivel
//const char _STR_ON      []  = "[ON] OFF ";
//const char _STR_OFF     []  = " ON [OFF]";
const char _STR_CELSIUS []  = {CUSTOM_CARACTER_CELSIUS,'\0'};
const char _STR_BELL    []  = {CUSTOM_CARACTER_BELL   ,'\0'};
const char _STR_ON      []  = {'O', 'N'               ,'\0'};
const char _STR_OFF     []  = {'O', CUSTOM_CARACTER_FF,'\0'};
const char _STR_DONE    []  = {CUSTOM_CARACTER_DONE,   '\0'};
const char _STR_LATE    []  = {CUSTOM_CARACTER_WATCH,  '\0'};
const char _STR_GOOD    []  = {CUSTOM_CARACTER_GOOD,   '\0'};
const char _STR_BAD     []  = {CUSTOM_CARACTER_BAD,    '\0'};
const char _STR_STRANGE []  = {CUSTOM_CARACTER_STRANGE,'\0'};

/*
  |OOOOOOOOOO111111|
  |0123456789012345|
  |>LUZES [ON][OFF]|
  |>FILTRO[ON][OFF]|
  |>AR    [ON][OFF]|
  |>ALIMENTAR AGORA|
  |>COMIDA   99:99h|
  |>AQUEC.[ON][OFF]|
  |>TEMP.   999.9oC|
  |>CONFIGURACAO   |
  |>DATA E HORA    |
  |DD/MM/AAAA HH:MM|
  |>LUZES          |
  |I 99:99  F 99:99|
  |>FILTRO         |
  |I 99:99  F 99:99|
  |>BOMBA DE AR    |
  |I 99:99  F 99:99|
  |>ALIMENTO COMIDA|
  |1 99:99  2 99:99|
  |3 99:99  4 99:99|
  |5 99:99  6 99:99|
  |>TEMPERATURA    |
  |MIN 99    MAX 99|
  |>T.P.AGUA       |
  | A CADA: 00 dias|
  | ULTM DD/MM/AAAA|
  |OOOOOOOOOO111111|
  |0123456789012345|

  dataHoraEntry_screen
  |OOOOOOOOOO111111|
  |0123456789012345|
 0|   DD/MM/AAAA   |
 1|    HH:MM:SS    |
*/

//#define _NOME_PRODUTO_ "AQUA-CTRL v"
//#define _NOME_AUTOR_   "by mrvcarvalho"
//#define _VERSION_      "1.6"

const static char PROGMEM _NOME_PRODUTO_[]= {"AQUA-CTRL v"};
const static char PROGMEM _NOME_AUTOR_  []= {"by mrvcarvalho"};
const static char PROGMEM _VERSION_     []= {"1.6"};

#define _ON      true
#define _OFF     false
#define _DONE    true
#define _LATE    false

/**/

MenuAQUA::MenuAQUA(/*LiquidCrystal_I2C *p_LCD, LiquidMenu *p_MenuLiquid, Alarm *p_Alarm*/) {



	MRVDEBUGLN(F("Construtor do MenuAQUA Iniciou done"));	printMemoryUsage();
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	//-----------------------------------------------------------------------------------
	// MENU DO SISTEMA
	//-----------------------------------------------------------------------------------
	//myLCD    = p_LCD;
	//myAlarm  = p_Alarm;
	//myMenu   = p_MenuLiquid;

	MRVDEBUGLN(F("STEP 01"));

	bStatusLuzes      = _OFF;   // LUZES DO AQUARIO
	bStatusAr         = _OFF;   // BOMBA DE AERACAO
	bStatusFiltro     = _OFF;   // BOMBA DE FILTRAGEM
	bStatusAquecedor  = _OFF;   // TERMOSTATO / AQUECEDOR
	bStatusTPA        = _DONE;  // TROCA PARCIAL DE AGUA
	fStatusTemp       = 29.78;  // TERMOMETRO / TEMPERATURA
	//iStatusLastComida = 0;

	// MENU DO SISTEMA
	_CurrentMenuLine              = nullptr;
	_LastMenuLine                 = nullptr;
	_CurrentConfigSettingVariable = nullptr;
	_LastConfigSettingVariable    = nullptr;

	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);
	MRVDEBUGLN(F("STEP 02"));
	MRVDEBUGLN(F("->myLCD="));	MRVDEBUGLN((int)myLCD);

	// ARRAY DE CONFIGURACOES GERAIS DO SISTEMA
	MRVDEBUGLN(F("STEP 02.01i"));

	// SCREEN BEM-VINDO - defining lines
	welcome_line1 = new LiquidLine (1, 0, _NOME_PRODUTO_, _VERSION_);
	welcome_line2 = new LiquidLine (1, 1, _NOME_AUTOR_);

	MRVDEBUGLN(F("STEP 02.02"));

	// progmem settings
	welcome_line1->set_variableAsProgmem(1);
	welcome_line1->set_variableAsProgmem(2);
	welcome_line2->set_variableAsProgmem(1);

	MRVDEBUGLN(F("STEP 02.03"));

	// adding callback functions settings
	//welcome_line1->attach_function   (1, gotoPrincipalScreen);
	//welcome_line2->attach_function   (1, gotoPrincipalScreen);

	welcome_line1->attach_function   (1, nextScreen);
	welcome_line2->attach_function   (1, nextScreen);

	MRVDEBUGLN(F("STEP 02.04"));

	// adding lines to screen
	welcome_screen = new LiquidScreen (*welcome_line1, *welcome_line2);

	MRVDEBUGLN(F("STEP 02.05"));

	MRVDEBUGLN(F("STEP 03"));

	//-----------------------------------------------------------------------------------
	// SCREEN PRINCIPAL - defining lines
	//-----------------------------------------------------------------------------------
	const static char textPrincipalLUZ   [] PROGMEM = {"LUZES        "};
	const static char textPrincipalFILTRO[] PROGMEM = {"FILTRAGEM    "};
	const static char textPrincipalAR    [] PROGMEM = {"BOMBA DE AR  "};
	const static char textPrincipalAQUEC [] PROGMEM = {"AQUECEDOR    "};
	const static char textPrincipalTEMP  [] PROGMEM = {"TEMP.    "    };
	const static char textPrincipalTPA   [] PROGMEM = {"T.P.AGUA      "};
	const static char textPrincipalCONFIG[] PROGMEM = {"CONFIGURAR---->"};
	principal_line_LUZ    = new LiquidLine (1, 0, textPrincipalLUZ   , getStatusLuzes);
	principal_line_FILTRO = new LiquidLine (1, 0, textPrincipalFILTRO, getStatusAr);
	principal_line_AR     = new LiquidLine (1, 0, textPrincipalAR    , getStatusFiltro);
	principal_line_AQUEC  = new LiquidLine (1, 0, textPrincipalAQUEC , getStatusAquecedor);
	principal_line_TEMP   = new LiquidLine (1, 0, textPrincipalTEMP  , getStatusTemperatura, _STR_CELSIUS);
	principal_line_TPA    = new LiquidLine (1, 0, textPrincipalTPA   , getStatusTPA);
	principal_line_CONFIG = new LiquidLine (1, 0, textPrincipalCONFIG);

	MRVDEBUGLN(F("STEP 04"));

	// progmem settings
	principal_line_LUZ->set_variableAsProgmem(1);					MRVDEBUGLN(F("STEP 04.1"));
	principal_line_FILTRO->set_variableAsProgmem(1);				MRVDEBUGLN(F("STEP 04.2"));
	principal_line_AR->set_variableAsProgmem(1);					MRVDEBUGLN(F("STEP 04.3"));
	principal_line_AQUEC->set_variableAsProgmem(1);					MRVDEBUGLN(F("STEP 04.4"));
	principal_line_TEMP->set_variableAsProgmem(1);					MRVDEBUGLN(F("STEP 04.5"));
	principal_line_TPA->set_variableAsProgmem(1);					MRVDEBUGLN(F("STEP 04.6"));
	principal_line_CONFIG->set_variableAsProgmem(1);				MRVDEBUGLN(F("STEP 04.7"));

	// callback functions settings
	principal_line_LUZ->attach_function   (1, switchStatusLuzes);		MRVDEBUGLN(F("STEP 04.8"));
	principal_line_FILTRO->attach_function(1, switchStatusAr);			MRVDEBUGLN(F("STEP 04.9"));
	principal_line_AR->attach_function    (1, switchStatusFiltro);		MRVDEBUGLN(F("STEP 04.10"));
	principal_line_AQUEC->attach_function (1, switchStatusAquecedor);	MRVDEBUGLN(F("STEP 04.11"));
	principal_line_TEMP->attach_function  (1, blankFunction);			MRVDEBUGLN(F("STEP 04.12"));
	principal_line_TEMP->set_decimalPlaces(1);							MRVDEBUGLN(F("STEP 04.13"));
	principal_line_TPA->attach_function   (1, switchStatusTPA);			MRVDEBUGLN(F("STEP 04.14"));
	principal_line_CONFIG->attach_function(1, gotoConfiguracaoScreen);	MRVDEBUGLN(F("STEP 04.15")); 	printMemoryUsage();

	// adding lines to screen
	principal_screen = new LiquidScreen (*principal_line_LUZ);		MRVDEBUGLN(F("STEP 04.16"));
	principal_screen->add_line(*principal_line_FILTRO);				MRVDEBUGLN(F("STEP 04.17"));
	principal_screen->add_line(*principal_line_AR);					MRVDEBUGLN(F("STEP 04.18"));
	principal_screen->add_line(*principal_line_AQUEC);				MRVDEBUGLN(F("STEP 04.19"));		printMemoryUsage();
	principal_screen->add_line(*principal_line_TEMP);				MRVDEBUGLN(F("STEP 04.20"));
	principal_screen->add_line(*principal_line_TPA);				MRVDEBUGLN(F("STEP 04.21"));		printMemoryUsage();
	principal_screen->add_line(*principal_line_CONFIG);				MRVDEBUGLN(F("STEP 04.22"));		printMemoryUsage();
	principal_screen->set_displayLineCount(2);						MRVDEBUGLN(F("STEP 04.23"));		printMemoryUsage();

	MRVDEBUGLN(F("STEP 05"));																			printMemoryUsage();

	//-----------------------------------------------------------------------------------
	// SCREEN MENU CONFIGURACAO - defining lines
	//-----------------------------------------------------------------------------------
	const static char textConfiguracaoDATAHORA[] PROGMEM = {"DATA E HORA"    };		MRVDEBUGLN(F("STEP 05.01"));		printMemoryUsage();
	const static char textConfiguracaoLUZ     [] PROGMEM = {"LUZES"          };		MRVDEBUGLN(F("STEP 05.02"));		printMemoryUsage();
	const static char textConfiguracaoFILTRO  [] PROGMEM = {"FILTRO"         };		MRVDEBUGLN(F("STEP 05.03"));		printMemoryUsage();
	const static char textConfiguracaoAR      [] PROGMEM = {"BOMBA DE AR"    };		MRVDEBUGLN(F("STEP 05.04"));		printMemoryUsage();
	const static char textConfiguracaoALIMENTO[] PROGMEM = {"ALIMENTO COMIDA"};		MRVDEBUGLN(F("STEP 05.05"));		printMemoryUsage();
	const static char textConfiguracaoTEMP    [] PROGMEM = {"TEMPERATURA"    };		MRVDEBUGLN(F("STEP 05.06"));		printMemoryUsage();
	const static char textConfiguracaoTPA     [] PROGMEM = {"T.P.AGUA"       };		MRVDEBUGLN(F("STEP 05.07"));		printMemoryUsage();
	configuracao_line_DATAHORA  = new LiquidLine (1, 0, textConfiguracaoDATAHORA);	MRVDEBUGLN(F("STEP 05.08"));		printMemoryUsage();
	configuracao_line_LUZ       = new LiquidLine (1, 0, textConfiguracaoLUZ     );	MRVDEBUGLN(F("STEP 05.09"));		printMemoryUsage();
	configuracao_line_FILTRO    = new LiquidLine (1, 0, textConfiguracaoFILTRO  );	MRVDEBUGLN(F("STEP 05.10"));		printMemoryUsage();
	configuracao_line_AR        = new LiquidLine (1, 0, textConfiguracaoAR      );	MRVDEBUGLN(F("STEP 05.11"));		printMemoryUsage();
	configuracao_line_ALIMENTO  = new LiquidLine (1, 0, textConfiguracaoALIMENTO);	MRVDEBUGLN(F("STEP 05.12"));		printMemoryUsage();
	configuracao_line_TEMP      = new LiquidLine (1, 0, textConfiguracaoTEMP    );	MRVDEBUGLN(F("STEP 05.13"));		printMemoryUsage();
	configuracao_line_TPA       = new LiquidLine (1, 0, textConfiguracaoTPA     );	MRVDEBUGLN(F("STEP 05.14"));		printMemoryUsage();

	// progmem settings
	configuracao_line_DATAHORA->set_variableAsProgmem(1);							MRVDEBUGLN(F("STEP 05.15"));		printMemoryUsage();
	configuracao_line_LUZ->set_variableAsProgmem     (1);							MRVDEBUGLN(F("STEP 05.16"));		printMemoryUsage();
	configuracao_line_FILTRO->set_variableAsProgmem  (1);							MRVDEBUGLN(F("STEP 05.17"));		printMemoryUsage();
	configuracao_line_AR->set_variableAsProgmem      (1);							MRVDEBUGLN(F("STEP 05.18"));		printMemoryUsage();
	configuracao_line_ALIMENTO->set_variableAsProgmem(1);							MRVDEBUGLN(F("STEP 05.19"));		printMemoryUsage();
	configuracao_line_TEMP->set_variableAsProgmem    (1);							MRVDEBUGLN(F("STEP 05.20"));		printMemoryUsage();
	configuracao_line_TPA->set_variableAsProgmem     (1);							MRVDEBUGLN(F("STEP 05.21"));		printMemoryUsage();

	// callback functions settings
	configuracao_line_DATAHORA->attach_function(1, gotoDataHoraDetalheScreen);		MRVDEBUGLN(F("STEP 05.22"));		printMemoryUsage();
	configuracao_line_LUZ->attach_function     (1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.23"));		printMemoryUsage();
	configuracao_line_FILTRO->attach_function  (1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.24"));		printMemoryUsage();
	configuracao_line_AR->attach_function      (1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.25"));		printMemoryUsage();
	configuracao_line_ALIMENTO->attach_function(1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.26"));		printMemoryUsage();
	configuracao_line_TEMP->attach_function    (1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.27"));		printMemoryUsage();
	configuracao_line_TPA->attach_function     (1, gotoXYZ);						MRVDEBUGLN(F("STEP 05.28"));		printMemoryUsage();

	// adding lines to screen
	configuracao_screen = new LiquidScreen (*configuracao_line_DATAHORA);			MRVDEBUGLN(F("STEP 05.29"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_LUZ);							MRVDEBUGLN(F("STEP 05.30"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_FILTRO);						MRVDEBUGLN(F("STEP 05.31"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_AR);							MRVDEBUGLN(F("STEP 05.32"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_ALIMENTO);						MRVDEBUGLN(F("STEP 05.33"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_TEMP);							MRVDEBUGLN(F("STEP 05.34"));		printMemoryUsage();
	configuracao_screen->add_line(*configuracao_line_TPA);							MRVDEBUGLN(F("STEP 05.35"));		printMemoryUsage();
	configuracao_screen->set_displayLineCount(2);									MRVDEBUGLN(F("STEP 05.36"));		printMemoryUsage();

	MRVDEBUGLN(F("STEP 06"));

	//-----------------------------------------------------------------------------------
	// VARIAVEIS DE CONFIGURACAO - DETALHES
	//-----------------------------------------------------------------------------------

	ConfigSetting* arrayConfig[36];													MRVDEBUGLN(F("STEP 06.01"));		printMemoryUsage();
	#define _CONFIG_DATE_YEAR              0
	#define _CONFIG_DATE_MONTH             1
	#define _CONFIG_DATE_DAY               2
	#define _CONFIG_DATE_HOUR              3
	#define _CONFIG_DATE_MINUTE            4
	#define _CONFIG_DATE_SECOND            5

	#define _CONFIG_LUZ_INICIO_HORA        6
	#define _CONFIG_LUZ_INICIO_MINUTO      7
	#define _CONFIG_LUZ_FIM_HORA           8
	#define _CONFIG_LUZ_FIM_MINUTO         9

	#define _CONFIG_FILTRO_INICIO_HORA     10
	#define _CONFIG_FILTRO_INICIO_MINUTO   11
	#define _CONFIG_FILTRO_FIM_HORA        12
	#define _CONFIG_FILTRO_FIM_MINUTO      13

	#define _CONFIG_AR_INICIO_HORA         14
	#define _CONFIG_AR_INICIO_MINUTO       15
	#define _CONFIG_AR_FIM_HORA            16
	#define _CONFIG_AR_FIM_MINUTO          17

	#define _CONFIG_ALIMENTO1_HORA         18
	#define _CONFIG_ALIMENTO1_MINUTO       19
	#define _CONFIG_ALIMENTO2_HORA         20
	#define _CONFIG_ALIMENTO2_MINUTO       21
	#define _CONFIG_ALIMENTO3_HORA         22
	#define _CONFIG_ALIMENTO3_MINUTO       23
	#define _CONFIG_ALIMENTO4_HORA         24
	#define _CONFIG_ALIMENTO4_MINUTO       25
	#define _CONFIG_ALIMENTO5_HORA         26
	#define _CONFIG_ALIMENTO5_MINUTO       27
	#define _CONFIG_ALIMENTO6_HORA         28
	#define _CONFIG_ALIMENTO6_MINUTO       29

	#define _CONFIG_TEMPERATURA_MINIMA     30
	#define _CONFIG_TEMPERATURA_MAXIMA     31

	#define _CONFIG_TPA_PERIODICIDADE_DIAS 32
	#define _CONFIG_TPA_ULTIMA_YEAR        33
	#define _CONFIG_TPA_ULTIMA_MONTH       34
	#define _CONFIG_TPA_ULTIMA_DAY         35

	MRVDEBUGLN(F("STEP 07"));

	/*
	//---------------------------------------------------------------------
	//                                                   INIT | Min | Max |
	//                                                    VAL | Min | Max |
	//---------------------------------------------------------------------
	arrayConfig[_CONFIG_DATE_YEAR]   = new ConfigSetting(2019, 1970, 9999);
	arrayConfig[_CONFIG_DATE_MONTH]  = new ConfigSetting(  10,    1,   12);
	arrayConfig[_CONFIG_DATE_DAY]    = new ConfigSetting(  23,    1,   31);

	arrayConfig[_CONFIG_DATE_HOUR]   = new ConfigSetting(  20,    0,   23);
	arrayConfig[_CONFIG_DATE_MINUTE] = new ConfigSetting(  15,    0,   59);
	arrayConfig[_CONFIG_DATE_SECOND] = new ConfigSetting(  75,    0,   59);
	//----------------------------------------------------------------------------------
	// | mounth = 1..12 | year = 2019..9999 | day = 1..31 | hour = 0..23 | minute = 0..59 | second = 0..59 |
	//----------------------------------------------------------------------------------
	*/

	//---------------------------------------------------------------------------------------------------------------------
	//                                                              INIT | Min | Max | Formato | Larg. | Precisao | Divide |
	//                                                               VAL | Min | Max | Saida   | Saida | QtdDec   | p/10?  |
	//---------------------------------------------------------------------------------------------------------------------
	arrayConfig[_CONFIG_DATE_YEAR  ]            = new ConfigSetting(2019, 1970, 9999,   "%04d",        4,      0,    false); MRVDEBUGLN(F("STEP 07.01"));		printMemoryUsage();
	arrayConfig[_CONFIG_DATE_MONTH ]            = new ConfigSetting(   5,    1,   12,   "%02d",        2,      0,    false); MRVDEBUGLN(F("STEP 07.02"));		printMemoryUsage();
	arrayConfig[_CONFIG_DATE_DAY   ]            = new ConfigSetting(  23,    1,   31,   "%02d",        2,      0,    false); MRVDEBUGLN(F("STEP 07.03"));		printMemoryUsage();

	MRVDEBUGLN(F("STEP 08"));

	arrayConfig[_CONFIG_DATE_HOUR  ]            = new ConfigSetting(  15,    0,   23,   "%02d",        2,      0,    false); MRVDEBUGLN(F("STEP 08.01"));		printMemoryUsage();
	arrayConfig[_CONFIG_DATE_MINUTE]            = new ConfigSetting(  18,    0,   59,   "%02d",        2,      0,    false); MRVDEBUGLN(F("STEP 08.02"));		printMemoryUsage();
	arrayConfig[_CONFIG_DATE_SECOND]            = new ConfigSetting(  75,    0,   59,   "%02d",        2,      0,    false); MRVDEBUGLN(F("STEP 08.03"));		printMemoryUsage();

	MRVDEBUGLN(F("STEP 09"));
	/*
	arrayConfig[_CONFIG_LUZ_INICIO_HORA  ]      = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_LUZ_INICIO_MINUTO]      = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_LUZ_FIM_HORA  ]         = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_LUZ_FIM_MINUTO]         = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);

	arrayConfig[_CONFIG_FILTRO_INICIO_HORA  ]   = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_FILTRO_INICIO_MINUTO]   = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_FILTRO_FIM_HORA  ]      = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_FILTRO_FIM_MINUTO]      = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);

	arrayConfig[_CONFIG_AR_INICIO_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_AR_INICIO_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_AR_FIM_HORA  ]          = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_AR_FIM_MINUTO]          = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);

	arrayConfig[_CONFIG_ALIMENTO1_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO1_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO2_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO2_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO3_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO3_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO4_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO4_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO5_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO5_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO6_HORA  ]       = new ConfigSetting(   0,    0,   23,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_ALIMENTO6_MINUTO]       = new ConfigSetting(   0,    0,   59,   "%02d",        2,      0,    false);

	arrayConfig[_CONFIG_TEMPERATURA_MINIMA]     = new ConfigSetting(  75,    0,   59, nullptr,        5,      2,    true );
	arrayConfig[_CONFIG_TEMPERATURA_MAXIMA]     = new ConfigSetting(  75,    0,   59, nullptr,        5,      2,    true );

	arrayConfig[_CONFIG_TPA_PERIODICIDADE_DIAS] = new ConfigSetting(   0,    0,   99,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_TPA_ULTIMA_YEAR  ]      = new ConfigSetting(2018, 1970, 9999,   "%04d",        4,      0,    false);
	arrayConfig[_CONFIG_TPA_ULTIMA_MONTH ]      = new ConfigSetting(  12,    1,   12,   "%02d",        2,      0,    false);
	arrayConfig[_CONFIG_TPA_ULTIMA_DAY   ]      = new ConfigSetting(  31,    1,   31,   "%02d",        2,      0,    false);
	*/



	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: DATA E HORA - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_DATAHORA_screen;//<----------------------------------------------
	//static LiquidLine*   detalhe_DATAHORA_line_DATA;
	//static LiquidLine*   detalhe_DATAHORA_line_HORA;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| DATA:DD/MM/AAAA|
	//1| HORA:HH:MM:SS  |

	const static char textDetalheDATA[]    PROGMEM = {"DATA:"};
	const static char textDetalheHORA[]    PROGMEM = {"HORA:"};
	const static char textDATA_Slash[]     PROGMEM = {"/"};
	const static char textHORA_TwoPoints[] PROGMEM = {":"};

	MRVDEBUGLN(F("STEP 10"));

	detalhe_DATAHORA_line_DATA  = new LiquidLine (1, 0, textDetalheDATA, *arrayConfig[_CONFIG_DATE_DAY], textDATA_Slash, *arrayConfig[_CONFIG_DATE_MONTH]);			MRVDEBUGLN(F("STEP 10.01"));		printMemoryUsage();
	detalhe_DATAHORA_line_DATA->add_variable("/");
	detalhe_DATAHORA_line_DATA->add_variable(*arrayConfig[_CONFIG_DATE_YEAR]);

	detalhe_DATAHORA_line_HORA  = new LiquidLine (1, 1, textDetalheHORA, *arrayConfig[_CONFIG_DATE_HOUR], textHORA_TwoPoints, *arrayConfig[_CONFIG_DATE_MINUTE]); 	MRVDEBUGLN(F("STEP 10.02"));		printMemoryUsage();
	detalhe_DATAHORA_line_HORA->add_variable(":");
	detalhe_DATAHORA_line_HORA->add_variable(*arrayConfig[_CONFIG_DATE_SECOND]);

	// progmem settings
	detalhe_DATAHORA_line_DATA->set_variableAsProgmem(1); MRVDEBUGLN(F("STEP 10.03"));		printMemoryUsage(); // "DATA:"
	detalhe_DATAHORA_line_DATA->set_variableAsProgmem(3); MRVDEBUGLN(F("STEP 10.04"));		printMemoryUsage(); // "/"
	detalhe_DATAHORA_line_HORA->set_variableAsProgmem(1); MRVDEBUGLN(F("STEP 10.05"));		printMemoryUsage(); // "HORA:"
	detalhe_DATAHORA_line_HORA->set_variableAsProgmem(3); MRVDEBUGLN(F("STEP 10.06"));		printMemoryUsage(); // ":"

	// callback functions settings
	detalhe_DATAHORA_line_DATA->attach_function (1, gotoXYZ); MRVDEBUGLN(F("STEP 10.07"));		printMemoryUsage();
	detalhe_DATAHORA_line_HORA->attach_function (1, gotoXYZ); MRVDEBUGLN(F("STEP 10.08"));		printMemoryUsage();

	// adding lines to screen
	detalhe_DATAHORA_screen = new LiquidScreen (*detalhe_DATAHORA_line_DATA); MRVDEBUGLN(F("STEP 10.09"));		printMemoryUsage();
	detalhe_DATAHORA_screen->add_line(*detalhe_DATAHORA_line_HORA);			  MRVDEBUGLN(F("STEP 10.10"));		printMemoryUsage();
	detalhe_DATAHORA_screen->set_displayLineCount(2);						  MRVDEBUGLN(F("STEP 10.11"));		printMemoryUsage();

	MRVDEBUGLN(F("STEP 11"));

	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: LUZ - INICIO - FIM - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_LUZ_screen;//<----------------------------------------------
	//static LiquidLine*   detalhe_LUZ_line_titulo;
	//static LiquidLine*   detalhe_LUZ_line_detalhe;
	//arrayConfig[_CONFIG_LUZ_INICIO_HORA  ]      = new ConfigSetting(   0,    0,   23,   _02d,        2,      0,    false);
	//arrayConfig[_CONFIG_LUZ_INICIO_MINUTO]      = new ConfigSetting(   0,    0,   59,   _02d,        2,      0,    false);
	//arrayConfig[_CONFIG_LUZ_FIM_HORA  ]         = new ConfigSetting(   0,    0,   23,   _02d,        2,      0,    false);
	//arrayConfig[_CONFIG_LUZ_FIM_MINUTO]         = new ConfigSetting(   0,    0,   59,   _02d,        2,      0,    false);
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| LUZ  ON:   OFF:|
	//1|   99:99h 99:99h|
	/*
	detalhe_LUZ_line_titulo  = new LiquidLine (1, 0, "LUZ  ON:   OFF:");

	detalhe_LUZ_line_detalhe  = new LiquidLine (1, 1, "HORA:", *arrayConfig[_CONFIG_DATE_HOUR], ":", *arrayConfig[_CONFIG_DATE_MINUTE]);
	detalhe_LUZ_line_detalhe->add_variable(":");
	detalhe_LUZ_line_detalhe->add_variable(*arrayConfig[_CONFIG_DATE_SECOND]);

	// callback functions settings
	detalhe_DATAHORA_line_DATA->attach_function (1, gotoXYZ);
	detalhe_DATAHORA_line_HORA->attach_function (1, gotoXYZ);

	// adding lines to screen
	detalhe_DATAHORA_screen = new LiquidScreen (*detalhe_DATAHORA_line_DATA);
	detalhe_DATAHORA_screen->add_line(*detalhe_DATAHORA_line_HORA);
	detalhe_DATAHORA_screen->set_displayLineCount(2);

	*/
	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: FILTRO - INICIO - FIM - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_FILTRO_screen;  //<----------------------------------------------
	//static LiquidLine*   detalhe_FILTRO_line_titulo;
	//static LiquidLine*   detalhe_FILTRO_line_detalhe;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| FILTRO   ON/OFF|
	//1| +99:99h/-99:99h|

	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: AR - INICIO - FIM - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_AR_screen;  //<----------------------------------------------
	//static LiquidLine*   detalhe_AR_line_titulo;
	//static LiquidLine*   detalhe_AR_line_detalhe;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| BOMBA AR ON/OFF|
	//1| +99:99h/-99:99h|

	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: ALIMENTO - INICIO - FIM - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_ALIMENTO_screen;  //<----------------------------------------------
	//static LiquidLine*   detalhe_ALIMENTO_line_titulo;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe1;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe2;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe3;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe4;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe5;
	//static LiquidLine*   detalhe_ALIMENTO_line_detalhe6;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| ALIMENTO COMIDA|
	//1| PROG 01) 99:99h|
	//0| PROG 02) 99:99h|
	//1| PROG 03) 99:99h|
	//0| PROG 04) 99:99h|
	//1| PROG 05) 99:99h|
	//0| PROG 06) 99:99h|

	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: TEMPERATURA - MINIMO - MAXIMO - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_TEMPERATURA_screen;  //<----------------------------------------------
	//static LiquidLine*   detalhe_TEMPERATURA_line_titulo;
	//static LiquidLine*   detalhe_TEMPERATURA_line_minimo;
	//static LiquidLine*   detalhe_TEMPERATURA_line_maximo;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| TEMPERATURA    |
	//1| MINIMO    99.9c|
	//0| MAXIMO    99.9c|

	//-----------------------------------------------------------------------------------
	// SCREEN CONFIGURACAO DETALHE: TPA - PERIODICIDADE - ULTIMA VEZ - defining lines
	//-----------------------------------------------------------------------------------
	//static LiquidScreen* detalhe_TPA_screen;  //<----------------------------------------------
	//static LiquidLine*   detalhe_TPA_line_titulo;
	//static LiquidLine*   detalhe_TPA_line_periodicidade;
	//static LiquidLine*   detalhe_TPA_line_ultimaVez;
	// |OOOOOOOOOO111111|
	// |0123456789012345|
	//0| TROCA PARC.AGUA|
	//1| A CADA: 00 dias|
	//0| ULTM DD/MM/AAAA|

	MRVDEBUGLN(F("STEP 12"));

	MRVDEBUGLN(F("Construtor do MenuAQUA Finalizou done"));
}


void MenuAQUA::setup(void) {

	// LCD CARACTERES CUSTOMIZADOS
	myLCD->createChar_P (CUSTOM_CARACTER_CELSIUS, aCustomCharCELCIUS);	MRVDEBUGLN(F("STEP 02.01a "));
	myLCD->createChar_P (CUSTOM_CARACTER_WATCH  , aCCustomCharWATCH );  MRVDEBUGLN(F("STEP 02.01b "));
	myLCD->createChar_P (CUSTOM_CARACTER_BELL   , aCustomCharBELL   );  MRVDEBUGLN(F("STEP 02.01c "));
	myLCD->createChar_P (CUSTOM_CARACTER_DONE   , aCustomCharDONE   );  MRVDEBUGLN(F("STEP 02.01d "));
	myLCD->createChar_P (CUSTOM_CARACTER_FF     , aCustomCharFF     );  MRVDEBUGLN(F("STEP 02.01e "));
	myLCD->createChar_P (CUSTOM_CARACTER_GOOD   , aCcustomCharGOOD  );  MRVDEBUGLN(F("STEP 02.01f "));
	myLCD->createChar_P (CUSTOM_CARACTER_BAD    , aCustomCharBAD    );  MRVDEBUGLN(F("STEP 02.01g "));
	myLCD->createChar_P (CUSTOM_CARACTER_STRANGE, aCustomCharSTRANGE);  MRVDEBUGLN(F("STEP 02.01h "));

	MRVDEBUGLN(F("MenuAQUA::setup INICIOU"));				printMemoryUsage();

	Serial.print(F("->	welcome_screen             :"));	  MRVDEBUGLN((int)welcome_screen            );
	Serial.print(F("->	principal_screen           :"));	  MRVDEBUGLN((int)principal_screen          );
	Serial.print(F("->	configuracao_screen        :"));	  MRVDEBUGLN((int)configuracao_screen       );
	Serial.print(F("->	detalhe_DATAHORA_screen    :"));	  MRVDEBUGLN((int)detalhe_DATAHORA_screen   );
	Serial.print(F("->	detalhe_LUZ_screen         :"));	  MRVDEBUGLN((int)detalhe_LUZ_screen        );
	Serial.print(F("->	detalhe_FILTRO_screen      :"));	  MRVDEBUGLN((int)detalhe_FILTRO_screen     );
	Serial.print(F("->	detalhe_AR_screen          :"));	  MRVDEBUGLN((int)detalhe_AR_screen         );
	Serial.print(F("->	detalhe_ALIMENTO_screen    :"));	  MRVDEBUGLN((int)detalhe_ALIMENTO_screen   );
	Serial.print(F("->	detalhe_TEMPERATURA_screen :"));	  MRVDEBUGLN((int)detalhe_TEMPERATURA_screen);
	Serial.print(F("->	detalhe_TPA_screen         :"));	  MRVDEBUGLN((int)detalhe_TPA_screen        );

	//-------------------------------
	// adding screen to menu
	//-------------------------------
	myMenu->add_screen(*welcome_screen);
	myMenu->add_screen(*principal_screen);
	myMenu->add_screen(*configuracao_screen);
	myMenu->add_screen(*detalhe_DATAHORA_screen);

	//myMenu->add_screen(*detalhe_LUZ_screen);
	//myMenu->add_screen(*detalhe_FILTRO_screen);
	//myMenu->add_screen(*detalhe_AR_screen);
	//myMenu->add_screen(*detalhe_ALIMENTO_screen);
	//myMenu->add_screen(*detalhe_TEMPERATURA_screen);
	//myMenu->add_screen(*detalhe_TPA_screen);

	myMenu->set_focusPosition(Position::LEFT);
	myMenu->init();
	myMenu->update();

	MRVDEBUGLN(F("MenuAQUA::setup TERMINO"));				printMemoryUsage();
}

MenuAQUA::~MenuAQUA() {
	// TODO Auto-generated destructor stub
}

// -----------------------------------------------------------------------------------------------------------------------------
// GETTERS -  STATUS
// -----------------------------------------------------------------------------------------------------------------------------
const char* getStatusLuzes      (void) {
  return (bStatusLuzes    ? _STR_ON   : _STR_OFF);
}
const char* getStatusAr         (void) {
  return (bStatusAr       ? _STR_ON   : _STR_OFF);
}
const char* getStatusFiltro     (void) {
  return (bStatusFiltro   ? _STR_ON   : _STR_OFF);
}
const char* getStatusAquecedor  (void) {
  return (bStatusAquecedor ? _STR_ON   : _STR_OFF);
}
const char* getStatusTPA        (void) {
  return (bStatusTPA      ? _STR_DONE : _STR_LATE);
}
float       getStatusTemperatura(void) {
  return fStatusTemp;
}

// -----------------------------------------------------------------------------------------------------------------------------
// SETTERS - SWITCH STATUS
// -----------------------------------------------------------------------------------------------------------------------------
void switchStatusLuzes    (void) {
  bStatusLuzes     = !bStatusLuzes;
  myAlarm->doBuzzerTurnON_OFF(bStatusLuzes);
}
void switchStatusAr       (void) {
  bStatusAr        = !bStatusAr;
  myAlarm->doBuzzerTurnON_OFF(bStatusAr);
}
void switchStatusFiltro   (void) {
  bStatusFiltro    = !bStatusFiltro;
  myAlarm->doBuzzerTurnON_OFF(bStatusFiltro);
}
void switchStatusAquecedor(void) {
  bStatusAquecedor = !bStatusAquecedor;
  myAlarm->doBuzzerTurnON_OFF(bStatusAquecedor);
}
void switchStatusTPA      (void) {
  bStatusTPA       = !bStatusTPA;
  myAlarm->doBuzzerTurnON_OFF(bStatusTPA);
}
void blankFunction() {
  // Used for attaching something to the lines, to make them focusable.
  return;
}
void gotoConfiguracaoScreen (void) {
  // CLICK OPTION
  myAlarm->doBuzzerTurnON_OFF(true);
  myMenu->change_screen(*configuracao_screen);
}
void nextScreen(void) {
  myMenu->next_screen();
  return;
}
void gotoPrincipalScreen (void) {
  // CLICK OPTION
  myMenu->change_screen(*principal_screen);
}
void gotoDataHoraDetalheScreen (void) {
  // CLICK OPTION
  myMenu->change_screen(*detalhe_DATAHORA_screen);
}
void gotoXYZ (void) {
  // CLICK OPTION
  //menu->change_screen(*principal_screen);
  return;
}
//LiquidMenu * MenuAQUA::getMainLiquidMenu(void) {
//	return myMenu;
//}

//---------------------------------------------------------------------------------------------------------
// CLICKs e BOTOES
//---------------------------------------------------------------------------------------------------------
void MenuAQUA::get_currentMenuLineVariable(void) {
  MYDEBUGLN(F("\nINO->--------------------------------"));

  _LastMenuLine                 = _CurrentMenuLine;
  _CurrentMenuLine              = myMenu->get_currentLine();
  _LastConfigSettingVariable    = _CurrentConfigSettingVariable;
  _CurrentConfigSettingVariable = nullptr;

  if (_CurrentMenuLine) {  // Se encontrou MenuLine selecionada (corrente/atual)

    if (_CurrentMenuLine != _LastMenuLine) {                    // se É a 1a vez que está clicando nesta linha
      MYDEBUGLN(F("INO->pegou uma NOVA - LINHA de MENU"));
      _LastMenuLine->set_ConfigSettingVariable_current_to_none(); // SAI DO MODO DE ALTERAcaO DA LINHA ANTERIOR
    } else {
      MYDEBUGLN(F("INO->manteve-se na MESMA - LINHA de MENU"));
      _CurrentConfigSettingVariable = _CurrentMenuLine->get_ConfigSettingVariable_next();  // entao pega primeira ou a proxima variavel
    }

    if (!_CurrentConfigSettingVariable) {
      _CurrentMenuLine->set_ConfigSettingVariable_current_to_none(); // SAI DO MODO DE ALTERAÇAO DA LINHA
    }

    if (_CurrentConfigSettingVariable) { // se encontrou uma variavel do tipo ConfigSetting no MenuLine
      MYDEBUGLN(F("INO->pegou currentConfigSettingVariable"));
    } else {
      MYDEBUGLN(F("INO->vazia currentConfigSettingVariable"));
    }
  } else {
    MYDEBUGLN(F("INO->vazia currentLine"));
  }
  return;
}
