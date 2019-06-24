#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "dth.h"
#include "lib/bits.h"
#include "one_wire.h"
#include "lib/avr_usart.h"

#define DQ_OUTPUT()		SET_BIT(DDRx,DQ)
#define DQ_INPUT()		CLR_BIT(DDRx,DQ)
#define CLR_DQ()		CLR_BIT(PORTx,DQ)
#define SET_DQ()		SET_BIT(PORTx,DQ)
#define TST_DQ()		TST_BIT(PINx,DQ)


uint8_t data_read(){
	uint8_t data =0;

	for (int i = 0; i<8; i++)
		{
			while(!TST_DQ());  //start to transmit
			_delay_us(30); // 26-28 us voltage-lenght means data "0"
			if(TST_DQ()) // if pulse still high after 30us
			data = (data<<1)|(0x01);	// then its HIGH = '1'
			else			// otherwise its LOW = '1'
			data = (data<<1);
			while(TST_DQ()); //wait until next transmittion
		}
		return data;
}

void response_dht11(){
		DQ_INPUT();
		while(TST_DQ()); //dht sends out response signal & keep it for 80us
		_delay_us(80);
		while(!TST_DQ()); //dht pulls up voltage and keeps it for 80us
		_delay_us(80);
		while(TST_DQ()); //
}

void request_dht11(){

		DQ_OUTPUT();
		CLR_DQ();	// set to low pin
		_delay_ms(20);			// wait for 18ms AT LEAST
		SET_DQ();
		_delay_us(40);
}
