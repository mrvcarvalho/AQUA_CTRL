################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\Agenda.cpp \
..\AgendaAlarm.cpp \
..\AgendaFeed.cpp \
..\AgendaOnOff.cpp \
..\Alarm.cpp \
..\ControladorMaster.cpp \
..\EEPROMSettingsKeeper.cpp \
..\FoodDispenser.cpp \
..\MenuAQUA.cpp \
..\Relay.cpp \
..\ScreenSaver.cpp \
..\Thermometer.cpp \
..\Thermostat.cpp \
..\UserInterface.cpp \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\Agenda.cpp.o \
.\AgendaAlarm.cpp.o \
.\AgendaFeed.cpp.o \
.\AgendaOnOff.cpp.o \
.\Alarm.cpp.o \
.\ControladorMaster.cpp.o \
.\EEPROMSettingsKeeper.cpp.o \
.\FoodDispenser.cpp.o \
.\MenuAQUA.cpp.o \
.\Relay.cpp.o \
.\ScreenSaver.cpp.o \
.\Thermometer.cpp.o \
.\Thermostat.cpp.o \
.\UserInterface.cpp.o \
.\sloeber.ino.cpp.o 

CPP_DEPS += \
.\Agenda.cpp.d \
.\AgendaAlarm.cpp.d \
.\AgendaFeed.cpp.d \
.\AgendaOnOff.cpp.d \
.\Alarm.cpp.d \
.\ControladorMaster.cpp.d \
.\EEPROMSettingsKeeper.cpp.d \
.\FoodDispenser.cpp.d \
.\MenuAQUA.cpp.d \
.\Relay.cpp.d \
.\ScreenSaver.cpp.d \
.\Thermometer.cpp.d \
.\Thermostat.cpp.d \
.\UserInterface.cpp.d \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Agenda.cpp.o: ..\Agenda.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

AgendaAlarm.cpp.o: ..\AgendaAlarm.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

AgendaFeed.cpp.o: ..\AgendaFeed.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

AgendaOnOff.cpp.o: ..\AgendaOnOff.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Alarm.cpp.o: ..\Alarm.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

ControladorMaster.cpp.o: ..\ControladorMaster.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

EEPROMSettingsKeeper.cpp.o: ..\EEPROMSettingsKeeper.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

FoodDispenser.cpp.o: ..\FoodDispenser.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

MenuAQUA.cpp.o: ..\MenuAQUA.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Relay.cpp.o: ..\Relay.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

ScreenSaver.cpp.o: ..\ScreenSaver.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Thermometer.cpp.o: ..\Thermometer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Thermostat.cpp.o: ..\Thermostat.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

UserInterface.cpp.o: ..\UserInterface.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidMenu_by_mrvcarvalho\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"

	@echo 'Finished building: $<'
	@echo ' '


