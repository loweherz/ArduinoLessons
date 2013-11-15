/*
Attivazione buzzer se c'è movimento
*/

 
int Val = 0;
const int BUZZER = 3; //Buzzer senza elettronica
const int MOV = 2;    //Sens. movimento
int randNumber = 0;


void setup()  
{ 
  pinMode(BUZZER, OUTPUT);  //Impostazione PIN come uscita
  pinMode(MOV, INPUT);      //Impostazione PIN come ingresso   
  digitalWrite(MOV,HIGH);
  Val=digitalRead(MOV);  //Imposto in Val lo stato del sensore presente all'vvio (condizione di non allarme)
} 
 

void loop()
{
  digitalRead(MOV);
  if (Val!=digitalRead(MOV))  //Se c'è movimento attivo il buzzer
  {
    Val=digitalRead(MOV);
    randNumber=random(10,255);
    analogWrite(BUZZER,randNumber);
  }
  else
  {
    Val=digitalRead(MOV);
    digitalWrite(BUZZER,0);
  }
  delay(500);
}


