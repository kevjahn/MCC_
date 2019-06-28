#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/dht11.h"
#include "lib/modbus.h"
#include "lib/avr_usart.h"

int main() {

//	FILE *debug = get_usart_stream();
	USART_Init(B9600);

	while (1) {
		if (dht_response()) {
//			fprintf(debug, "Humidity: %d.%d temp: %d.%d\r\n",	get_dht_humidityHigh(),
//										get_dht_humidityLow(),
//																			get_dht_tempHigh(),
//																			get_dht_tempLow());
			modbusConfig(1, 5, get_dht_tempHigh());
			modbus_tx();
			modbusConfig(1, 6, get_dht_humidityHigh());
			modbus_tx();
		}
		_delay_ms(500);
	}
}
