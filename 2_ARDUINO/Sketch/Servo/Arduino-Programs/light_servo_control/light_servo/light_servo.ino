//Controls a Servo Motor using the info from a light Sensor

#include <Servo.h>

//Define Pins
int servoPin = 9;
int lightPin = 0; 

//Create Servo Object
Servo servo;

void setup(){
  //Attaches the Servo to our object
  servo.attach(servoPin);
}

void loop(){
  //Read the light Sensor and adjust values (0 - 1023)
  int value = analogRead(lightPin);
  int pos = map(value, 0, 1023, 0, 180);
  
  //Turn the servo
  servo.write(pos);
  
}
