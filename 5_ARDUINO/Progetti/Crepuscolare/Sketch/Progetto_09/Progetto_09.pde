/*
Crepuscolare. Attivazione Relè quando la luminosità scende al di sotto di un valore impostato.
*/

 
long Luce = 450;
long Val = 0;
const int FOTORES = 0;    //Pulsante ON/OFF
const int RELE =  2;  //Relè


void setup()  
{ 
  pinMode(RELE, OUTPUT);  //Impostazione PIN come uscita
  pinMode(FOTORES, INPUT);  //Impostazione PIN come ingresso   
  //Set porta seriale
  Serial.begin(9600);
  Serial.println("System Startup");
} 
 

void loop()
{
  Val=analogRead(FOTORES);
  //Visualizzazione su seriale del valore analogico della fotoresistenza
  Serial.print("Fotoresistenza: ");
  Serial.println(Val);
  if (Val<=Luce)  //Se il valore della fotoresistenza è inferiore di quello desiderato per la luce, si attiva il relè
  {
    digitalWrite(RELE,HIGH);
    Serial.println("Sera");
  }
  else
  {
    digitalWrite(RELE,LOW);
    Serial.println("Giorno");
  }
  delay(1000);
}


