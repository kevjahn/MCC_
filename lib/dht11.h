#ifndef DTH11_C_
#define DTH11_C_

#include <stdint.h>

#include "avr_gpio.h"
#include "one_wire.h"
#include "bits.h"

uint8_t dht_response();

uint8_t get_dht_humidityHigh();
uint8_t get_dht_humidityLow();
uint8_t get_dht_tempHigh();
uint8_t get_dht_tempLow();

#endif /* DTH11_C_ */
