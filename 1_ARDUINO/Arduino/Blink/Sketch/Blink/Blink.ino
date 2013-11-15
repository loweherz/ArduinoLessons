const int ledPin = 3;
int ledState = LOW;
long previousMillis = 0; // memorizza il tempo dell’ultimo aggiornamento
		     // long perchè il tempo è in millisecondi
long interval = 1000;    // interval at which to blink (milliseconds)

void setup() {
	pinMode(ledPin, OUTPUT); // metto il piedino in Output
}

void loop(){
	unsigned long currentMillis = millis();
	if(currentMillis - previousMillis > interval) {
		// save the last time you blinked the LED
		previousMillis = currentMillis;
		// se il LED è On mettilo OFF e viceversa:
		if (ledState == LOW)
			ledState = HIGH;
		else
			ledState = LOW;
		digitalWrite(ledPin, ledState);
	}
}

