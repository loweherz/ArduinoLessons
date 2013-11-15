/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 9;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(A1, INPUT);    
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int value = analogRead(A1);
  Serial.println(value);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(value + 100);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(value + 100);               // wait for a second
}
