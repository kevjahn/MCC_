# Microcontroladores I
O projeto consiste em desenvolver uma aplicação prática utilizando:

*  Sensor: DHT11

* Microcontrolador ATmega328p

* Módulo WiFi ESP-01

* Atuador: Servo Motor

  

  O sensor DHT11, sensor de temperatura e umidade, enviará os dados para o microcontrolador, este armazenará os dados e através de um protocolo simplificado ModBus RTU fará a comunicação com o módulo WiFi ESP-01. Os dados tratados do sensor serão enviados à Internet através do protocolo MQTT.

  Com as informações de temperatura será controlado o ângulo do servo motor, o valor do ângulo será o mesmo da temperatura. 

  ![](figuras\0.PNG)

## DHT11

- O sensor utiliza One Wire para comunicação;

- Um ciclo de comunicação é de aproximadamente 4ms;

- Um dado completo de transmissão possui 40bits, dividido em 5 blocos de 8 bits cada, sendo o bit mais significativo enviado primeiro;

- Utiliza o pino PB0 para receber os dados;

  

  Visão geral do processo de comunicação:

  ![](figuras\1.PNG)


## Servo Motor

* Utiliza os Pinos PB1 como saída;
* O servo motor utilizado possui ângulo de 0º até +180º;
* O puls0 de controle é de 1m a 2m;
* O ângulo do servo motor é determinado pelo valor da temperatura. Exemplo: 25ºC = 25º;

## Modbus

O módulo WiFi ESO-01 possui um firmware customizado. A comunicação entre
o módulo WiFi e o ATmega328P deverá ser feita utilizando a porta serial (UART) de ambos
os microcontrolador e com uma simplicação do protocolo Modbus RTU.A comunicação entre
o módulo WiFi e o ATmega328P deverá ser feita utilizando a porta serial (UART) de ambos
os microcontrolador e com uma simplicação do protocolo Modbus RTU.  

O frame Modbus RTU é constituído de 9 bytes, sendo o primeiro o endereço do dispositivo que deseja se comunicar. O segundo byte é o comando de escrita e leitura. O terceiro e o quarto, são os registradores do dispositivos que deseja-se ler ou escrever e o quarto é o dado em si. Ainda, no ultimo byte, temos o CRC. 

