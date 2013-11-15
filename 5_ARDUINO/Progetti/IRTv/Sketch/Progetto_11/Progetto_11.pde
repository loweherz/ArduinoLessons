/*
Ricevitore IR per telecomandi TV
*/

#include <IRremote.h>

const int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //Avvia ricezione
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if (results.decode_type == NEC) 
    {
      Serial.print("NEC: ");
    } 
    else if (results.decode_type == SONY) 
    {
      Serial.print("SONY: ");
    } 
    else if (results.decode_type == RC5) 
    {
      Serial.print("RC5: ");
    } 
    else if (results.decode_type == RC6) 
    {
      Serial.print("RC6: ");
    }
    else if (results.decode_type == UNKNOWN) 
    {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, HEX);
    irrecv.resume(); //Attesa ricezione prossimo valore
  }
}

