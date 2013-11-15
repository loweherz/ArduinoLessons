/*
Visualizzazione della temperatura su un display 16x2
*/

#include <OneWire.h>
#include <DallasTemperature.h> 
#include <LiquidCrystal.h>


// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 6 
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
//Inizializza i PIN per il controllo del display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ASCII = 1;
double Temperatura = 0;
 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
 

void setup(void)
{
  //Impartisco il tipo di display, ovvero 16 caratteri e 2 righe
  lcd.begin(16, 2);
  // start serial port
  Serial.begin(9600);
  Serial.println("System Startup");
  // Start up the library
  sensors.begin();
}


void loop(void)
{   
  Serial.print("Richiesta Temperatura..."); //Invio su seriale la scritta di richiesta
  sensors.requestTemperatures();//Richiesta temperatura sul bus OnWire
  Temperatura = sensors.getTempCByIndex(0);
  Serial.print(Temperatura); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(176, BYTE);
  Serial.println("C");
  
  //Imposta colonna 0 e riga 1 (0:Prima riga - 1:Seconda riga)
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(Temperatura);
  delay (1000);
}
