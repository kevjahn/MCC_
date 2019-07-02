################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/Controle_servo_motor.c \
../lib/avr_spi.c \
../lib/avr_twi_master.c \
../lib/avr_usart.c \
../lib/dth11.c \
../lib/modbus.c \
../lib/one_wire.c 

OBJS += \
./lib/Controle_servo_motor.o \
./lib/avr_spi.o \
./lib/avr_twi_master.o \
./lib/avr_usart.o \
./lib/dth11.o \
./lib/modbus.o \
./lib/one_wire.o 

C_DEPS += \
./lib/Controle_servo_motor.d \
./lib/avr_spi.d \
./lib/avr_twi_master.d \
./lib/avr_usart.d \
./lib/dth11.d \
./lib/modbus.d \
./lib/one_wire.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


