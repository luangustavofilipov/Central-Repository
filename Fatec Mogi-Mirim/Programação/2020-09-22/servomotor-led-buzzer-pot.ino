#include <Servo.h>

//Instrução
Servo servo;

int pos;

int ledVermelho = 10;

int ledVerde = 11;

int buzz = 8;

int pot;

int valorMot = 0;

//Início do Void "Setup"

void setup()
{
    servo.attach(9);
    //Coloca o servo na posição inicial
    servo.write(0);
    Serial.begin(9600);
    delay(1000);

    //Define os leds
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);

}

//Início do Void "Loop"

void loop()
{

    valorPot = analogRead(A0);
    valorMotor = map(Pot,0,1023,0,180);
    servo.write(valorMot);
    Serial.println(valorMot);
    delay(100);
    //Movimentos até 180°
    for(pos = 0; pos < 180; pos++){
        servo.write(pos);
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledVermelho, LOW);
        delay(15);

    }
    delay(1000);

    //Movimentação até 0°
    for(pos = 180; pos >= 0; pos--){
        servo.write(pos);
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledVermelho, HIGH);
        delay(15);

    }

    if (pos <= 5){
        
    }
}