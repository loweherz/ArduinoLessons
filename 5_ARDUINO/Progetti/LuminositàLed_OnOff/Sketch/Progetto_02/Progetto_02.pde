/*
2 pulsanti disponibili che permettono di agire su un led spegnendo e accendendo (P1) il led oppure regolarne la luminosità (P2)
*/

int Stato = 0;    //Stato Pulsante
int Val_PWM = 125; //Valore luminosità led per PWM (0-255)
int Accendi = 0;   //0: Accendi LED - 1: Spegni LED
int Inc_Dec = 1;   //0: Decremento luminosità - 1: Incremento luminosità
int TEMPO = 20;    //Tempo ritardo cambiamento luminosità (max 255)
const int P1 = 10;    //Pulsante ON/OFF
const int P2 = 11;    //Pulsante senso luminosità 
const int LED1 =  3;  //LED


void setup()  
{ 
  pinMode(LED1, OUTPUT);  //Impostazione PIN come uscita
  pinMode(P1, INPUT);  //Impostazione PIN come ingresso 
  pinMode(P2, INPUT);  //Impostazione PIN come ingresso 
  digitalWrite(P1, HIGH);  //Abilitazione pull-up
  digitalWrite(P2, HIGH);  //Abilitazione pull-up
} 

void loop()  
{ 
  //Lettura stato pulsante 1 (Accensione/Spegnimento)
  //Accensione/spegnimento LED in base allo stato pulsanti
  if (digitalRead(P1) == LOW) 
  {     
    if (Accendi == 0)  //Se led Spento lo accendo 
    {
      Accendi=1; 
      analogWrite(LED1, Val_PWM);  //Imposto luminosità LED    
    }
    else  //Se led spento lo accendo
    {
      Accendi=0;
      analogWrite(LED1, 0);
    }  
  } 
  while (digitalRead(P1) == LOW)
  {
    delay(10);  //Attesa 100ms
  }
  
  //Lettura stato pulsante 2 (Regolazione senso luminosità)
  while (digitalRead(P2) == LOW) 
  {     
    if (Val_PWM == 255) 
    {
      //Cambio senso, da Incremento a Decremento luminosità
      Inc_Dec=0;   
    }
    if (Val_PWM == 0) 
    {
      //Cambio senso, da Decremento a Incremento luminosità
      Inc_Dec=1;   
    }
    
    if (Inc_Dec == 1)  //Incremento luminosità
    {
      Val_PWM = Val_PWM + 1;      
    }
    else  //Decremento luminosità
    {
      Val_PWM = Val_PWM - 1;
    } 
    analogWrite(LED1, Val_PWM);  //Imposto luminosità LED
    delay(TEMPO);  //Attesa    
  }
}
