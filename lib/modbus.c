#include "modbus.h"

volatile uint8_t pkg[8] = {0x15, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t rx_pkg[16];

uint16_t CRC16_2(uint8_t *buf, int len)
{
	uint32_t crc = 0xFFFF;
	int i;

	for (i = 0; i < len; i++)
	{
		crc ^= (uint16_t)buf[i];          // XOR byte into least sig. byte of crc

		for (int i = 8; i != 0; i--) {    // Loop over each bit
			if ((crc & 0x0001) != 0) {      // If the LSB is set
				crc >>= 1;                    // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else                            // Else LSB is not set
				crc >>= 1;                    // Just shift right
		}
	}
	// Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
	return crc;
}

void modbus_tx(uint8_t reg, uint8_t data) {

	uint16_t crc;
	uint8_t i;

	pkg[1] = 0x01;
	pkg[2] = reg >> 8;
	pkg[3] = reg & 0xff;
	pkg[4] = data >> 8;
	pkg[5] = data & 0xff;

	crc = CRC16_2(pkg,6);

	pkg[6] = crc >> 8;
	pkg[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg[i]);

	for (i=0; i < 8;i++)
		rx_pkg[i] = USART_rx();

	_delay_ms(500);
}

void modbus_rx(uint8_t reg) {

	uint16_t crc;
	uint8_t i;

	pkg[1] = 0x02;
	pkg[2] = reg >> 8;
	pkg[3] = reg & 0xff;
	pkg[4] = 0x00;
	pkg[5] = 0x01;

	crc = CRC16_2(pkg,6);

	pkg[6] = crc >> 8;
	pkg[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg[i]);

	for (i=0; i < 8;i++)
		rx_pkg[i] = USART_rx();

	_delay_ms(500);
}

uint8_t modbus_get_data() {
	return (rx_pkg[5]);
}
