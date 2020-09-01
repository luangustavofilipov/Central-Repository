//Declaração das variáveis inteiras

int pinoTrig = 2;

int pinoEcho = 3;

//Declaração das variáveis de distância

long duracao = 0;

long distancia = 0;

//Declaração dos "Leds"

int ledVermelho = 6;

int ledAmarelo = 5;

int ledVerde = 4;

//Declaração da variável para controlar o "Buzzer"

int buzz = 8;

//Início do código "Setup"

void setup()
{
	
	//Comunicação com o monitor serial
	Serial.begin(9600);

	//Ativação dos pinos
	pinMode(pinoEcho, INPUT);
	pinMode(pinoTrig, OUTPUT);

}
	
	//Início do código "Loop"

void loop()
{
	

	digitalWrite(pinoEcho, LOW);
	delayMicroseconds(10);
	digitalWrite(pinoTrig, HIGH);
	delayMicroseconds(10);
    digitalWrite(pinoTrig, LOW);
    duracao = pulseIn(pinoEcho, HIGH);
    Serial.println(duracao);
    distancia = duracao / 58;
    Serial.print("Distância em centímetros: ");
    Serial.println(distancia);
    delay(100);

    if (distancia < 5) {

        digitalWrite(ledVermelho, HIGH);

        tone(buzz, 400, 1000);
    } 

    else {

        digitalWrite(ledVermelho, LOW);

        noTone(buzz);   

    }

    if(distancia >= 5 && distancia <= 10){
        
        digitalWrite(ledAmarelo, HIGH);

        tone(buzz, 500, 700);

    } else {
        
        digitalWrite(ledAmarelo, LOW);

        noTone(buzz);

    }

    if(distancia <= 10){
        
        digitalWrite(ledVerde, HIGH);

        tone(buzz, 600, 400);

    } else {

        digitalWrite(ledVerde, LOW);

        noTone(buzz);

    }


}