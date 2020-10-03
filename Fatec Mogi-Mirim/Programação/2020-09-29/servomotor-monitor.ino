#include <Servo.h>

Servo servo;
int  PinservoMotor = 3;
char tecla;
int valorMotor = 0;

void setup()
{
    servo.attach(PinservoMotor);
    Serial.begin(9600);

}

void loop()
{
    tecla = Serial.print("Tecla = ");
    Serial.println(tecla);

if ((tela == 'D') || (tecla == 'd')){
    valorMotor = valorMotor - 15;

if (valorMotor >= 180){
    valorMotor = 180;

}

}
else if ((tecla == 'A') || (tecla == 'a')){
    valorMotor = valorMotor + 15;

if (valorMotor <= 0){
    valorMotor = 0;

}   
    
    servo.write(valorMotor);
    delay(20);

}

}   