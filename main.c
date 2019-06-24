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

int main(){
	uint8_t RH, T, ND;
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
		//data = init_dht();
	//	data = init_dht();
		fprintf(debug, "\n\rRH: %d \n T: %d\n\r", RH, T);
		_delay_ms(500);

	}
}
