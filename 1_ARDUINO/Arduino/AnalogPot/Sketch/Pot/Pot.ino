int pot = 3;

void setup() {
  //NON ho bisogno di dichiarare la modalità del pin analogico
  Serial.begin(9600);
}
 
void loop() {
  //leggo il valore e lo scrivo sulla seriale
  int sensorValue = analogRead(pot);
  Serial.println(sensorValue, DEC);
}
