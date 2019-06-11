/*
 * main.c
 *
 *  Created on: Nov 10, 2016
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "one_wire.h"


int main(){


	uint8_t integral_rh, decimal_rh, integral_t, decimal_t, checksum;


	while(1){

		reset_1w();						//reset do sensor (a resposta de presença é retornada mas não avaliada).
		write_byte_1w(0xCC);			//comando para pular ROM (só 1 dispositivo no barramento).
		write_byte_1w(0x44);			//manda iniciar a conversão

		reset_1w();
		write_byte_1w(0xCC);
		write_byte_1w(0xBE);			//avisa que quer ler a memória

		
		integral_rh = read_byte_1w();		
		decimal_rh = read_byte_1w();
		integral_t = read_byte_1w();		
		decimal_t = read_byte_1w();
		checksum = read_byte_1w();
		
		_delay_ms(500);
	}



	return 0;
}
