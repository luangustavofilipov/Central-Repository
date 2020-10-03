//Bibliotecas
#include <LiquidCrystal.h>

//Variaveis

LiquidCrystal lcd(11, 10, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD


//Setup
void setup()
{  

    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luan Gustavo");
    lcd.setCursor(0,1);
    lcd.print("Filipov");

}


//Loop
void loop()
{
    if (Serial.available())
{
//faz a leitura atraves do monitor serial//
char cr = Serial.read();
//determina um caracter para limpar a tela//
if (cr == '%')
{
lcd.clear();
}
//determina um caracter para pular para a linha de baixo//
else if (cr == '>')
{
lcd.setCursor(0,1);
}
else
{
 // se o caracter digitado nao limpa e nem pula linha vai para o display//
 // nao aceita acentuacao //
lcd.write(cr);
}
}
}