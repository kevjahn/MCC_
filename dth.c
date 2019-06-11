#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "one_wire.h"

void read_dth(){
		uint8_t integral_rh, decimal_rh, integral_t, decimal_t, checksum;
		integral_rh = read_byte_1w();		
		decimal_rh = read_byte_1w();
		integral_t = read_byte_1w();		
		decimal_t = read_byte_1w();
		checksum = read_byte_1w();
}
