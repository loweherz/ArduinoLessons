#include <SoftwareSerial.h>
//Xbee receiver
//This example code is in the Public Domain
SoftwareSerial xbee(9, 8);

int sentDat;

void setup() {
  Serial.begin(9600);
  xbee.begin(9600);  
  pinMode(2, OUTPUT); 
}

void loop() {
  if (xbee.available() > 0) {
	sentDat = xbee.read(); 

	if(sentDat == 1){
          //activate the pumpkin for one second and then stop
  	  digitalWrite(2, HIGH);
          delay(1000);
          digitalWrite(2, LOW);
	}
  }
}