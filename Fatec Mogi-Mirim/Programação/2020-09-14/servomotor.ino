#include <Servo.h>

//Instrução
Servo servo;

int pos;

//Início do Void "Setup"

void setup()
{
    servo.attach(6);
    //Coloca o servo na posição inicial
    servo.write(0);
    delay(1000);

}

//Início do Void "Loop"

void loop()
{
    //Movimentos até 180°
    for(pos = 0; pos < 180; pos++){
        servo.write(pos);
        delay(15);

    }
    delay(1000);

    //Movimentação até 0°
    for(pos = 180; pos >= 0; poss--){
        servo.write(pos);
        delay(15);

    }

}