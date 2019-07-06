#ifndef _CONTROLE_SERVO_MOTOR_H
#define _CONTROLE_SERVO_MOTOR_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "avr_gpio.h"
#include "bits.h"

#define MAX 39999					//valor para a máxima contagem
#define SERVO_MOTOR GPIO_B
#define SERVO_MOTOR_PIN PB1


//protótipo da função
void init_servo();
void ativa_motor(int16_t x);

#endif

