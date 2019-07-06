#include "dht11.h"

uint8_t dht11_data[4];

uint8_t dht_response() {

	uint8_t i;
	uint8_t sum = 0;

	if (reset_1w())
		return 7;

	for(i=0; i < 4; i++) {
		dht11_data[i]  = read_byte_1w();
		sum += dht11_data[i];
	}
	return ((sum == read_byte_1w()));
}

uint8_t get_dht_humidityHigh() {
	return dht11_data[0];
}

uint8_t get_dht_humidityLow() {
	return dht11_data[1];
}

uint8_t get_dht_tempHigh() {
	return dht11_data[2];
}

uint8_t get_dht_tempLow() {
	return dht11_data[3];
}
