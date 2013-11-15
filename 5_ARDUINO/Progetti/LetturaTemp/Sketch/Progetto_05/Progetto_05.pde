/*
Visualizzazione temperatura rilevata dal DS18B20 su seriale
*/

#include <OneWire.h>
#include <DallasTemperature.h> 

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2 
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
int ASCII = 1;
 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
 

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("System Startup");
  // Start up the library
  sensors.begin();
}


void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Richiesta Temperatura...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("OK");
  //Serial.print("Temperatura: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(176, BYTE);
  Serial.println("C");
}
