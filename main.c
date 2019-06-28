/*
 * main.c
 *
 *  Created on: , 2019
 *      Author: kevin
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lib/bits.h"
#include "one_wire.h"
#include "dth.h"
#include "lib/avr_usart.h"
#include "lib/avr_gpio.h"
#include "Controle_servo_motor.h"

int main(){
	uint8_t RH, T, ND, checksum;
	init_servo();
	_delay_ms(100);
		FILE *debug = get_usart_stream();
	USART_Init(B9600);


	fprintf(debug,"any\n\r");
	while(1){

		request_dht11();
		response_dht11();
		RH = data_read();
		ND = data_read();
		T = data_read();
		ND = data_read();
		checksum = data_read();
		fprintf(debug, "\n\rRH: %d \n T: %d C\n\r", RH, T);
		ativa_motor(RH);
		fprintf(debug,"any\n\r");
		_delay_ms(3000);

	}
}
