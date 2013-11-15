//MASTER INVIA UN NUMERO E SLAVE LO RISPEDISCE INDIETRO INCREMENTATO DI UNO
//MASTER
#include <Wire.h>
 
byte x = 0;
byte num = 0;
 
void setup(){
  //inizializzo la libreria Wire come Master
  Wire.begin();
 
  //init seiale
  Serial.begin(9600);
  //avviso che il programma è avviato
  Serial.println("START");
 
}
 
void loop()
{
  //invio sul bus I2C un byte al device
  //che ha come indirizzo il valore 0x04
  //start trasmissione
  Wire.beginTransmission(0x04);
  //invio un byte
  Wire.write(x);
  //fine trasmissione
  Wire.endTransmission();
 
  delayMicroseconds(500);
 
  //richiedo un byte allo slave che ha indirizzo 0x04
  Wire.requestFrom(0x04, 1);
 
  //attendo la disponibilità di dati sul bus i2c
  while(Wire.available())
  {
    //quando è presente un dato avvia
    //la lettura
    num = Wire.read();
  }
 
  //incrementa il valore del byte
  x++;
 
  //verifico che il byte letto dallo slave sia stato
  //incrementato
  if(num != x)
    Serial.println("ERRORE");
 
  delay(5);
 
}