#include <SoftwareSerial.h>
#include <Ultrasonic.h>

#define pinBT_RX 0
#define pinBT_TX 1

#define pinCanal1  2
#define pinCanal2  3
#define pinCanal3  4
#define pinCanal4  5
#define pinCanal5  6
#define pinCanal6  7
#define pinCanal7  8

char buf;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int ledVerde = 12;
int ledVermelho = 11;
int Buzzer = 13;
int trigPino = 10;
int echoPino = 9;
long distancia = 0;
long duracao = 0;


SoftwareSerial serialBT(pinBT_RX, pinBT_TX);

String comando = "";
int portas[] = {pinCanal1, pinCanal2, pinCanal3, pinCanal4, pinCanal5, pinCanal6, pinCanal7};

void setup() {         
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledVermelho, OUTPUT);
pinMode(trigPino, OUTPUT);
pinMode(echoPino, INPUT);

  Serial.begin(9600);
  serialBT.begin(9600); 

  for (int nL = 0; nL < 10; nL++) {
      pinMode(portas[nL], OUTPUT);
  }

 
  Serial.println("Sketch Iniciado!");
}

void loop() {

  while (serialBT.available()) {
     char byteRec = serialBT.read();

     if (int(byteRec) == 0) { 
        return;
     }

     comando += byteRec;

     if (byteRec == ';') {
        Serial.print("Comando Recebido: ");
        Serial.println(comando); 

        if (comando.substring(0,1) == "C") {
           String canal = comando.substring(1,2);
           bool nivel = ( comando.indexOf("true") != -1 );

           digitalWrite(portas[canal.toInt()], nivel);
        }

        if (comando.substring(0,1) == "E") {
           String estadoPortas = "";
           estadoPortas += String(digitalRead(pinCanal1));
           estadoPortas += String(digitalRead(pinCanal2));
           estadoPortas += String(digitalRead(pinCanal3));
           estadoPortas += String(digitalRead(pinCanal4));
           estadoPortas += String(digitalRead(pinCanal5));
           estadoPortas += String(digitalRead(pinCanal6));
           estadoPortas += String(digitalRead(pinCanal7));
           estadoPortas += ";";

           serialBT.println(estadoPortas);

           Serial.print("Comando Enviado: ");
           Serial.println(estadoPortas);
        }
   comando = "";
     }
  }
  while(Serial.available() > 0)
    {
        buf = Serial.read();
        
        if (buf == 'A')
        {
            digitalWrite(2, HIGH);
        }
         if (buf == 'a')
        {
            digitalWrite(2, LOW);
        }     
        buf = Serial.read();
        
        if (buf == 'B')
        {
            digitalWrite(3, HIGH);
        }
         if (buf == 'b')
        {
            digitalWrite(3, LOW);
        }  
        buf = Serial.read();
        
        if (buf == 'D')
        {
            digitalWrite(4, HIGH);
        }
         if (buf == 'd')
        {
            digitalWrite(4, LOW);
        }     
        buf = Serial.read();
        
        if (buf == 'E')
        {
            digitalWrite(5, HIGH);
        }
         if (buf == 'e')
        {
            digitalWrite(5, LOW);
        }  
        buf = Serial.read();
        
        if (buf == 'F')
        {
            digitalWrite(6, HIGH);
        }
         if (buf == 'f')
        {
            digitalWrite(6, LOW);
        }     
        buf = Serial.read();
        
        if (buf == 'G')
        {
            digitalWrite(7, HIGH);
        }
         if (buf == 'g')
        {
            digitalWrite(7, LOW);
        }    
        buf = Serial.read();
        
        if (buf == 'H')
        {
            digitalWrite(8, HIGH);
        }
         if (buf == 'h')
        {
            digitalWrite(8, LOW);
        } 
        if (buf == 'I')
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }
        if (buf == 'J')
        {
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
        }                  
    }
    digitalWrite(trigPino,LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPino, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPino,LOW);
  duracao = pulseIn(echoPino,HIGH);
  distancia = duracao / 58;
  Serial.print("distancia em cm: ");
  Serial.println(distancia);
if (distancia < 60){
    tone(13,400);
    digitalWrite(ledVermelho,HIGH);
    digitalWrite(ledVerde,LOW);
}else{
  noTone(13);
  digitalWrite(ledVermelho,LOW);
  digitalWrite(ledVerde,HIGH);
}
  delay(100);
}