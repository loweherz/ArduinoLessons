/*
2 pulsanti disponibili che permettono di regolare la velocità del motore. Da fermo il motore si avvierà partendo circa da Val_PWM pari a 125
Visualizzazione su seriale del valore impostato
*/

int Val_PWM = 0; //Valore per PWM (0-255)
const int P1 = 11;    //Pulsante decremento
const int P2 = 10;    //Pulsante incremento
const int MOTORE =  3;  //Motore


void setup()  
{ 
  Serial.begin(9600); 
  Serial.println("system startup"); 
  pinMode(P1, INPUT);  //Impostazione PIN come ingresso 
  pinMode(P2, INPUT);  //Impostazione PIN come ingresso 
  pinMode(MOTORE, OUTPUT);  //Impostazione PIN come uscita
  digitalWrite(P1, HIGH);  //Abilitazione pull-up
  digitalWrite(P2, HIGH);  //Abilitazione pull-up
} 

void loop()  
{ 
  //Lettura stato pulsante 1 (Decremento velocità)
  if (digitalRead(P1) == LOW) 
  {     
    if ((Val_PWM > 0) and (Val_PWM <= 255))
    {
      //Decremento velocità
      Val_PWM=Val_PWM-1; 
      Serial.print("Valore PWM: "); 
      Serial.println(Val_PWM, DEC);        
    }            
  } 

  //Lettura stato pulsante 2 (Incremento velocità)
  if (digitalRead(P2) == LOW) 
  {     
    if ((Val_PWM >= 0) and (Val_PWM < 255))
    {
      //Incremento velocità
      Val_PWM=Val_PWM+1;  
      Serial.print("Valore PWM: "); 
      Serial.println(Val_PWM, DEC);       
    } 
  }  
  analogWrite(MOTORE, Val_PWM);  //Imposto velocità 
  delay(50);  //Attesa
}
