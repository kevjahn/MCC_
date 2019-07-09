#ifndef LIB_MODBUS_H_
#define LIB_MODBUS_H_

#include <avr/io.h>
#include <stdint.h>

#include <util/delay.h>


#include "avr_usart.h"

uint16_t CRC16_2(uint8_t *buf, int len);

void modbus_tx(uint8_t reg, uint8_t data);
void modbus_rx(uint8_t reg);
uint8_t modbus_get_data();

#endif /* LIB_MODBUS_H_ */
