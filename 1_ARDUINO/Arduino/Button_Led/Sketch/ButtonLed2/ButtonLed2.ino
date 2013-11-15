// Esempio 02: accendi il led appena è premuto il pulsante mantenendolo acceso quando si rilascia
// premendo una seconda volta il pulsante spegne il led

#define LED 3                // LED collegato al pin digitale 13
#define BUTTON 2              // pin di input dove è collegato il pulsante
int val = 0;                  // si userà val per conservare lo stato del pin di input
int stato = 0;                // ricorda lo stato in cui si trova il led, stato = 0 led spento, stato = 1 led acceso

void setup() {
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
}

void loop() {
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva

  // controlla che l'input sia HIGH (pulsante premuto)
  // e cambia lo stato del led
  if (val == HIGH) {
    stato = 1 - stato;
  } 

  if (stato == 1) {
    digitalWrite(LED, HIGH);   // accende il led
  }
  else {
    digitalWrite(LED, LOW);    //spegne il led
  }
}
