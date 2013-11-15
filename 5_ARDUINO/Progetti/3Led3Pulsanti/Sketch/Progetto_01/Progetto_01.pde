/*
3 pulsanti disponibili e singolo led associato ad ogni pulsante. Se il pulsante viene premuto il rispettivo led viene acceso
*/

int Stato1 = 0;    // how bright the LED is
int Stato2 = 0;    // how bright the LED is
int Stato3 = 0;    // how bright the LED is
const int P1 = 10;     // the number of the pushbutton pin
const int P2 = 11;     // the number of the pushbutton pin
const int P3 = 12;     // the number of the pushbutton pin
const int LED1 =  3;      // the number of the LED pin
const int LED2 =  5;      // the number of the LED pin
const int LED3 =  6;      // the number of the LED pin

void setup()  
{ 
  pinMode(LED1, OUTPUT);  //Impostazione PIN come uscita
  pinMode(LED2, OUTPUT);  //Impostazione PIN come uscita
  pinMode(LED3, OUTPUT);  //Impostazione PIN come uscita
  pinMode(P1, INPUT);  //Impostazione PIN come ingresso 
  pinMode(P2, INPUT);  //Impostazione PIN come ingresso
  pinMode(P3, INPUT);  //Impostazione PIN come ingresso
  digitalWrite(P1, HIGH);  //Abilitazione pull-up
  digitalWrite(P2, HIGH);  //Abilitazione pull-up
  digitalWrite(P3, HIGH);  //Abilitazione pull-up
} 

void loop()  
{ 
  //Lettura stato pulsanti
  Stato1 = digitalRead(P1);
  Stato2 = digitalRead(P2);
  Stato3 = digitalRead(P3);
  //Accensione/spegnimento LED in base allo stato pulsanti
  if (Stato1 == LOW) 
  {     
    //Accensione LED   
    digitalWrite(LED1, HIGH);  
  } 
  else 
  {
    //Spegnimento LED
    digitalWrite(LED1, LOW); 
  }  
  if (Stato2 == LOW) 
  {         
    digitalWrite(LED2, HIGH);  
  } 
  else 
  {
    digitalWrite(LED2, LOW); 
  }  
  if (Stato3 == LOW) 
  {       
    digitalWrite(LED3, HIGH);  
  } 
  else 
  {
    digitalWrite(LED3, LOW); 
  }    
  delay(100);  //Attesa 100ms
}
