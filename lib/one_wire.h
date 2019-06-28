#ifndef _ONE_WIRE_H
#define _ONE_WIRE_H

#include <avr/io.h>
#include "bits.h"
#include "avr_gpio.h"

//Pinos de hardware
#define DDRx	DDRC	//define o DDR do pino DQ
#define PORTx	PORTC	//define o PORT do pino DQ
#define PINx	PINC	//define o PIN do pino DQ
#define DQ		PC0		//pino para a comunicacao

//funcoes publicas
uint8_t reset_1w();
void power_1w();
uint8_t read_byte_1w();
uint8_t read_bit_1w();
void write_byte_1w(uint8_t dado);

#endif
