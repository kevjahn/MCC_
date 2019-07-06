#include "controle_servo_motor.h"

void init_servo()
{
	SET_BIT(SERVO_MOTOR->DDR, SERVO_MOTOR_PIN); //habilita o pino OC1A  (PB1) como saída

									//MAX = (F_CPU/(N*F_PWM))-1, com N = 8 e F_PWM = 50 Hz
	ICR1 = MAX; 					//configura o período do PWM (20 ms)

	// Configura o TC1 para o modo PWM rápido via ICR1, prescaler = 8
	TCCR1A = (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1<<WGM12) | (1 << CS11);

	SET_BIT(TCCR1A,COM1A1);			//ativa o PWM no OC1B, modo de comparação não-invertido

	SET_BIT(TCCR1A,COM1B1);			//ativa o PWM no OC1A, modo de comparação não-invertido

	 	//regra de três para determinar este valor: ICR1(MAX) = 20 ms, OCR1A (4000) = 2 ms)
}

void ativa_motor(int16_t x){
		uint16_t i = 0;
		//x = 22*x + 3015; //para servo motor de 0.5ms a 2.5ms
		i = 100*x/9 + 3000; //para servo motor de 1ms a 2ms
		//i = (22*x) + 1000;//(222*0.1*x) + 1000; //LEMBRAR DO PONTO FLUTUANTE //(MAX*0.1*x)/180 + 999.9 -> este 0.1 é que do todo queremos apenas variar de 0.5 ms a 2.5ms
		// ou seja, 10% de 20ms, consequentemente 10% do valor maximo da contagem multiplicado pela escala dividido por 180 e somado do valor
		// 0 do angulo
		OCR1A = i;
}
//-----------------------------------------------------------------------------------
