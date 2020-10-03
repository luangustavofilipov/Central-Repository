//Declaração das variáves (se necessário)
int ledVermelho = 2;
int ledAmarelo = 3;
int ledVerde = 4;

//Início do Void "Setup"

void setup(){
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
    pinMode(ledVerde, OUTPUT);

}

//Início do Void "Loop"

void loop(){
    digitalWrite(ledVermelho, HIGH);
    delay(1000);
    digitalWrite(ledAmarelo, HIGH);
    delay(1000);
    digitalWrite(ledVerde, HIGH);
    delay(1000);


}