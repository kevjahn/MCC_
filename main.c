#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/dht11.h"
#include "lib/modbus.h"
#include "lib/avr_gpio.h"
#include "lib/avr_usart.h"
#include "lib/controle_servo_motor.h"

int main() {
	FILE *debug =  get_usart_stream();
	USART_Init(B9600);
	init_servo();

	while (1) {

		if (dht_response()) {
			modbus_tx(5, get_dht_tempHigh());
			modbus_tx(6, get_dht_humidityHigh());
		}

		modbus_rx(1);
		fprintf(debug, "%d", modbus_get_data());
		ativa_motor(modbus_get_data());

		_delay_ms(500);
	}
}
