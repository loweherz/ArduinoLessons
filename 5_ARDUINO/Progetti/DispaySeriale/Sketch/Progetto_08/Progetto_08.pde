/*
Visualizzazione a display di ciò che viene inviata su USB, solo a seguito della pressione del tasto "Invio"
*/

#include <LiquidCrystal.h>
 
//Inizializza i PIN per il controllo del display
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Impostazione display
  lcd.begin(16, 2);
  //Inizializzazione seriale
  Serial.begin(9600);
}

void loop()
{
  //Se c'è un carattere su seriale lo visualizzo a display
  if (Serial.available()) 
  {
    //si attende poco che il messaggio arrivi su seriale
    delay(100);
    //pulizia display
    lcd.clear();
    //lettura di tutti i caratteri disponibili su serile a seguito della pressione del tasto di invio
    while (Serial.available() > 0) 
    {
      //visualizzazione a display
      lcd.write(Serial.read());
    }
  }
}


