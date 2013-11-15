/*
Regolazione velocità motore e/o LED in base al valore rilevato da uno slider.
*/

int Val_PWM = 0; //Valore per PWM (0-255)
int Val_Slider = 0;  //Valore Slider
const int SLIDER = A0;    //Slider 5 kohm
const int MOTORE =  3;  //Motore


void setup()  
{ 
  Serial.begin(9600); 
  Serial.println("system startup"); 
  pinMode(SLIDER, INPUT);  //Impostazione PIN come ingresso 
  pinMode(MOTORE, OUTPUT);  //Impostazione PIN come uscita
} 

void loop()  
{ 
  Val_Slider = analogRead(SLIDER);  //Lettura valore Slider
  Serial.print("Valore Slider: "); 
  Serial.println(Val_Slider, DEC);
  Serial.print("Valore PWM: "); 
  Serial.println(Val_PWM, DEC);  
  Val_PWM = Val_Slider;
  Val_PWM = Val_PWM / 4;  //L'analogico lavora fino a 1024, ovvero 4 volte in più del PWM, quindi adatto i valori 
  analogWrite(MOTORE, Val_PWM);  //Imposto velocità 
  delay(100);  //Attesa
}
