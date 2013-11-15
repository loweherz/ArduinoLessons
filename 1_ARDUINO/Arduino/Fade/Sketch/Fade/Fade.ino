/*
Esempio1: due led con Fade inverso 
 */
 
int brightness = 0;    // luminosità
int fadeAmount = 5;    // incremento
int led1 = 3;          // entrambi i pin sono PWM
int led2 = 5;

void setup()  {
  // declare i pin come output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
} 
 
void loop()  {
  // Imposto la luminosità dei due led
  analogWrite(led1, brightness);    
  analogWrite(led2, 255 - brightness);    
 
  // cambio la luminosità per il prossimo loop:
  brightness = brightness + fadeAmount;
 
  // se arrivo al limite inferiore o superiore inverto il conteggio:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  
  // attendo 30millisecondi in modo da vedere l'effetto
  delay(30);
}
