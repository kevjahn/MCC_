/*
 * main.c
 *
 *  Created on: , 2019
 *      Author: kevin
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "one_wire.h"
#include "dth.h"
#include "avr_usart.h"
#include "avr_gpio.h"

int main(){

	uint8_t integral_rh,i;

	/* Obtem o stream de depura��o */
		FILE *debug = get_usart_stream();
	USART_Init(B9600);

	fprintf(debug,"any\n\r");
	_delay_ms(1100);
	while(1){
		reset_1w();						//reset do sensor (a resposta de presença é retornada mas não avaliada).
		write_byte_1w(0xCC);			//comando para pular ROM (só 1 dispositivo no barramento).
		write_byte_1w(0x44);			//manda iniciar a conversão

		reset_1w();
		write_byte_1w(0xCC);
		write_byte_1w(0xBE);			//avisa que quer ler a memoria

		
		integral_rh = read_byte_1w();
				fprintf(debug,"resul:%d\n\r", integral_rh);
				integral_rh = read_byte_1w();
						fprintf(debug,"resul:%d\n\r", integral_rh);
						integral_rh = read_byte_1w();
								fprintf(debug,"resul:%d\n\r", integral_rh);
								integral_rh = read_byte_1w();
										fprintf(debug,"resul:%d\n\r", integral_rh);
										integral_rh = read_byte_1w();
												fprintf(debug,"resul:%d\n\r", integral_rh);
		if(i>4){
					i=0;
				}
		//fprintf(debug,"resul:%d\n\r", integral_rh);
		_delay_ms(500);
	}
}
