#define botao 8
void setup()
{
    pinMode(botao, INPUT);
    Serial.begin(9600);

}

void loop()
{
    if(digitalRead(botao) == HIGH)
        Serial.println("Botao pressionado!");

}