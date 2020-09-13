#include <thermistor.h>

//Declaração das variáveis
int celcius = 0;

int sensor = 0;

int valor = 0;

//Início do "Void Setup"
void setup()
{
	
	Serial.begin(9600);

}


//Início do "Void Loop"
void loop()
{
	
	sensor = analogRead(A0);

	valor = ((analogRead(A0) - 20)*3.04);

	celcius = map(valor, 0, 1023, -40, 125);

	Serial.print("Medida do sensor = ");

	Serial.println(sensor);

	Serial.print("Temperatura = ");

	Serial.println(celcius);

	delay(100);

}