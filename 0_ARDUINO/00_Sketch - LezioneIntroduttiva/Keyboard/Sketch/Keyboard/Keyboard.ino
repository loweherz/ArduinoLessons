/*
  keyboard
 */

#include "pitches.h"

//TASTI
int key1 = 2;
int key2 = 3;
int key3 = 4;
int key4 = 5;

//LED
int led1 = 7;
int led2 = 8;
int led3 = 9;
int led4 = 10;

//USCITA - in questo caso un buzzer, potrebbe essere uno speaker 8ohm
int buzzer = 11;

void setup() {
  pinMode(key1,INPUT);
  pinMode(key2,INPUT);
  pinMode(key3,INPUT);
  pinMode(key4,INPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  pinMode(buzzer,OUTPUT);
}

void loop() {
  //Se vedo che un tasto è stato premuto vado ad eseguire la nota corrispondente
  if(digitalRead(key1)==LOW){
    tone(buzzer, NOTE_A4, 20);
    digitalWrite(led1,HIGH);
  }
  if(digitalRead(key2)==LOW){
    tone(buzzer, NOTE_F4, 20);
    digitalWrite(led2,HIGH);
  }
  if(digitalRead(key3)==LOW){
    tone(buzzer, NOTE_C5, 20);
    digitalWrite(led3,HIGH);
  }
  if(digitalRead(key4)==LOW){
    tone(buzzer, NOTE_D4, 20);
    digitalWrite(led4,HIGH);
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
