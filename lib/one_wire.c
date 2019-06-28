#include <avr/io.h>
#include <util/delay.h>

#include "one_wire.h"

#define DQ_OUTPUT()		SET_BIT(DDRx,DQ)
#define DQ_INPUT()		CLR_BIT(DDRx,DQ); SET_BIT(PORTx,DQ)
#define CLR_DQ()		CLR_BIT(PORTx,DQ)
#define SET_DQ()		SET_BIT(PORTx,DQ)
#define TST_DQ()		TST_BIT(PINx,DQ)

//uint8_t read_bit_1w();

void write_bit_1w(uint8_t bit_1w);

uint8_t reset_1w()
{
	DQ_OUTPUT();
	CLR_DQ();
	_delay_ms(18);

	DQ_INPUT();
	_delay_us(40);

	if (TST_DQ())
		return 1;

	_delay_us(80);

	if (!TST_DQ())
		return 2;
	_delay_us(80);

	return 0;
}

//uint8_t read_bit_1w()
//{
//	uint8_t data = 0;
//
//	while(!TST_DQ());
//	_delay_us(30);
//
//	return data;
//}

uint8_t read_byte_1w()
{
	uint8_t i, dado = 0;

	for (i=0; i < 8; i++) {

		while (!TST_DQ());
		_delay_us(30);

		if (TST_DQ())
			SET_BIT(dado, (7-i));

		while (TST_DQ());
	}

	return (dado);
}

void power_1w()			//força o barramento em nível alto.
{							//utilizado com dispositivos alimentados no modo parasita
	DQ_OUTPUT();
	SET_DQ();
	_delay_ms(750);
	DQ_INPUT();			//pull-up externo
}

void write_bit_1w(uint8_t bit_1w)//escreve um bit no barramento
{
	DQ_OUTPUT();
	CLR_DQ();
	_delay_us(2);

	if(bit_1w) 
		SET_DQ(); 

	_delay_us(120);
	DQ_INPUT();
}

void write_byte_1w(uint8_t dado)	//escreve um byte no barramento
{
	uint8_t i;

	for (i=0; i<8; i++)		//envia o byte iniciando do bit menos significativo
		write_bit_1w(TST_BIT(dado,i));//escreve o bit no barramento
}

