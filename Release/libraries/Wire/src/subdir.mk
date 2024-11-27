################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Program\ Files\ (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp 

LINK_OBJ += \
.\libraries\Wire\src\Wire.cpp.o 

CPP_DEPS += \
.\libraries\Wire\src\Wire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Wire\src\Wire.cpp.o: C:\Program\ Files\ (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder" -I"C:\Users\mrvca\Documents\Arduino\libraries\LiquidCrystal_I2C_by_mrvcarvalho" -I"C:\Users\mrvca\Documents\Arduino\libraries\RTClib" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src" -I"C:\sloeber\arduinoPlugin\libraries\Servo\1.1.3\src" -I"C:\sloeber\arduinoPlugin\libraries\LED\1.3.0\src" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\MemoryFree" -I"C:\sloeber\arduinoPlugin\libraries\MemoryUsage\2.20.0\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\OneButton\src" -I"C:\Users\mrvca\Documents\Arduino\libraries\Encoder\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


