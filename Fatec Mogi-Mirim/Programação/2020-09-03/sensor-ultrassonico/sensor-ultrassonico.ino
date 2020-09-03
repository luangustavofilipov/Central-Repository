//Declaração das variáveis inteiras

int pinoTrig = 3;

int pinoEcho = 2;

//Declaração das variáveis dos Leds

int ledVermelho = 4;

int ledVerde = 5;

//Declaração das variáveis de distância

long distancia = 0;

long duracao = 0;

//Declaração da variável do "buzzer"

int buzz = 6;

//Início do "Setup"

void setup()
{
	
	Serial.begin(9600);
	pinMode(pinoEcho, INPUT);
	pinMode(pinoTrig, OUTPUT);
	pinMode(ledVerde, OUTPUT);
	pinMode(ledVermelho, OUTPUT);

}