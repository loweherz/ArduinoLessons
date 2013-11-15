/*
Visualizzazione a display dei secondi passati dall'accensione. Regolazione contrasto con slider
*/

#include <LiquidCrystal.h>
 
//Inizializza i PIN per il controllo del display
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() 
{
   //Impartisco il tipo di display, ovvero 16 caratteri e 2 righe
   lcd.begin(16, 2);
   //Scrittura messaggio di avvio
   lcd.print("Futura Elett.");
 }
 
void loop() 
{
   //Imposta colonna 0 e riga 1 (0:Prima riga - 1:Seconda riga)
   lcd.setCursor(0, 1);
   //Visualizzo il numero di secondi trascorsi
   lcd.print(millis()/1000);
   lcd.print(" sec.");
 }


