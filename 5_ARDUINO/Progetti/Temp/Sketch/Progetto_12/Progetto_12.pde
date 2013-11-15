/*
Rilevamento temperatura con NTC da 5k
*/

#include <math.h>

#define ThermistorPIN 0  //Pin analogico 0

float val = 0;           //Variabile di comodo per il calcolo della temperatura in base al proprio NTC
float NTC = 5000;        //Valore dell'NTC utilizzato. 5000=5k

float Thermistor(int RawADC) 
{
  val=10000/NTC;
  val=4.5*val;
  val=NTC*val;
  long Resistance; 
  float Temp;  //Variabile di comodo per il calcolo della tempratura

  Resistance=((1024 * val / RawADC) - val); 
  Temp = log(Resistance); //Salva Log(resistance)
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Converte gradi Kelvin in Celsius   
  return Temp;           //Ritorna la temperatura calcolata
}

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float temp;
  temp=Thermistor(analogRead(ThermistorPIN));       //legge ADC e converte in °C
  Serial.print("Temperatura: ");
  Serial.print(temp,1);                             //Visualizzazione gradi
  Serial.print(176, BYTE);
  Serial.print("C"); 
  Serial.print(" / "); 
  temp = (temp * 9.0)/ 5.0 + 32.0;                //Converte in Fahrenheit
  Serial.print(temp,1);                           //Visualizza Fahrenheit
  Serial.print(176, BYTE);
  Serial.print("F");
  Serial.println("");                                   
  delay(5000);                                     
}




