/*
 * dth.h
 *
 *  Created on: 11 de jun de 2019
 *      Author: Kevin
 */

#ifndef DTH_H_
#define DTH_H_

#define SEeT_BIT(byte, bit) ((byte) |= (1UL << (bit)))

#define CLEeAR_BIT(byte,bit) ((byte) &= ~(1UL << (bit)))

uint8_t data_read();
void response_dht();
void request_dht11();

#endif /* DTH_H_ */
