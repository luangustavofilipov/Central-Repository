//Variaveis (se necessário)

int celcius = 0;

int sensor = 0;

int valor = 0;

//Inicio do Void "Setup"

void setup(){
    //Parte onde inicia-se o código executado somente uma vez
    Serial.begin(9600);
}

//Incio do Void "Loop"

void loop(){
    //Parte onde repete-se o código interminatemente
    sensor = analogRead(A0);

    valor = ((analogRead(A0) - 20)*3.04);

    celcius = map(valor, 0, 1023, -40, 125);

    Serial.print("Medida do sensor = ");

    Serial.println(sensor);

    Serial.print("Temperatura = ");

    Serial.println(celcius);

    delay(100);
}