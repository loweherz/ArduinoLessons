// Esercizio1: accensione temporizzata di due led
// in due direzioni con uso dell'if 

#define led_1 8    // il pin 8 è usato per il LED
#define led_2 9    // il pin 9 è usato per il LED
#define btn_pin1 2  // il pin 2 è usato per il PULSANTE 1
#define btn_pin2 3  // il pin 3 è usato per il PULSANTE 2

// Variabili
int in1 = 0;        // variabile per memorizzare lo stato del PULSANTE 1
int in2 = 0;        // variabile per memorizzare lo stato del PULSANTE 2

void setup() {
     pinMode(led_1, OUTPUT);
     pinMode(led_2, OUTPUT);
     pinMode(btn_pin1, INPUT);
     pinMode(btn_pin2, INPUT);
} 

void loop()
{
     in1 = digitalRead(btn_pin1);
     in2 = digitalRead(btn_pin2);

     if (in1 == HIGH && in2 == LOW)  // se PULSANTE 1 premuto e PULSANTE 2 no sequenza 1
       {
           digitalWrite(led_1, HIGH);
           delay (2000);
           digitalWrite(led_2, HIGH);
           delay (2000);
           digitalWrite(led_1, LOW);
           delay (2000);
           digitalWrite(led_2, LOW);
       }
     if (in1 == LOW && in2 == HIGH)  // se PULSANTE 2 premuto e PULSANTE 1 no sequenza 2
       {
           digitalWrite(led_2, HIGH);
           delay (2000);
           digitalWrite(led_1, HIGH);
           delay (2000);
           digitalWrite(led_2, LOW);
           delay (2000);
           digitalWrite(led_1, LOW);
       }
}
