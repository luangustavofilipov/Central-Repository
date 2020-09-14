void setup (){

    Serial.begin(9600);
}

void loop (){

    //faz a leitura do pino A0 (0 - 1023)
    valor = analogRead(POT);
    Serial.println("Valor lido = ");
    

}