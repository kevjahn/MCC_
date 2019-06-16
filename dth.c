#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "one_wire.h"

uint8_t read_dth(){
	uint8_t buffer;
		buffer = read_byte_1w();
		return buffer;
}
