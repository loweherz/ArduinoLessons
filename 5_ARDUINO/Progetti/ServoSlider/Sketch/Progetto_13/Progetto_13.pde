/*
Controllo di un servo motore
*/

#include <SoftwareServo.h> 

SoftwareServo myservo;  // crea l'oggetto servo

int potpin = 0;  //pin utilizzato per il potenziometro
int val;    //variabile contenente il valore analogico letto

void setup() 
{ 
  myservo.attach(3);  //Imposto sul pin due il colelgamento al servo
} 

void loop() 
{ 
  val = analogRead(potpin);            //Lettura del valore del potenziometro
  val = map(val, 0, 1023, 0, 179);     //Riadatto il valore del potenziometro in una scala compresa tra 0 e 180 (0° - 180°)
  myservo.write(val);                  //Sposto il servo dei gradi impostati
  delay(10);                           //Attesa prima di spostare di nuovo ils ervo

  SoftwareServo::refresh();
} 





