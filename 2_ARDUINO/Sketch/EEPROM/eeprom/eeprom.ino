#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup(){
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  clearMemory();
  readAllMemory();
}

void loop(){
	// need to divide by 4 because analog inputs range from
	// 0 to 1023 and each byte of the EEPROM can only hold a
	// value from 0 to 255.
	for(int i=address; i<=address+5; i++){
		int val = analogRead(i) / 4;
		writeOnMemory(i, val);		
	}
	
	address += 6;
	if(address > 500) address = 0;
	delay(5000);
	
	readFromToMemory(int i, int i+5);
}

void clearAllMemory(){
    for (int i = 0; i < 512; i++)
		EEPROM.write(i, 0);
}

void readAllMemory(){
	for (int i = 0; i < 512; i++){
		Serial.print(i);
		Serial.print(",\t");
		Serial.println(EEPROM.read(i));
	}
}

void readFromToMemory(int i, int j){
    for (int k = i; k < j; k++){
		Serial.print(k);
		Serial.print(",\t");
		Serial.println(EEPROM.read(k));
	}
}

void writeOnMemory(int addr, int value){
    EEPROM.write(addr, val);
}