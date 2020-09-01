#define  POT A0

//Definição da variável "Valor" como o que seŕa mostrado no "monitor serial"

int valor;

//Início do "Setup"

void setup()
{
	
	Serial.begin(9600);

}

//Início do "Loop"

void loop()
{
	
	valor = analogRead(A0);

	Serial.print("Valor lido: ");

	Serial.println(valor);

    valor = map(valor, 0, 1023, 0, 100);

    Serial.print("Valor mapeado: ");

    Serial.println(valor);

    Serial.println();

    delay(400);

}