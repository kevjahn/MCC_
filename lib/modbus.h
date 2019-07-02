#ifndef LIB_MODBUS_H_
#define LIB_MODBUS_H_

#include <avr/io.h>
#include <stdint.h>

#include "avr_usart.h"

uint16_t CRC16_2(uint8_t *buf, int len);

void modbusConfig(uint8_t cmd, uint8_t reg, uint8_t data);
void modbus_tx();
void modbus_rx();

#endif /* LIB_MODBUS_H_ */
