//Controls a Servo Motor using the info from an IR Distance Sensor

//Include Servo Library
#include <Servo.h>

//Define Pins
int servoPin = 9;
int distPin = 0;

//Create Servo Object
Servo myServo;

void setup()
{
 
  //Attaches the Servo to our object
  myServo.attach(servoPin);
}

void loop()
{
  //Read the Distance Sensor and adjust values
  int dist = analogRead(distPin);
  int pos = map(dist, 0, 1023, 0, 180);
  
  //Turn the servo
  myServo.write(pos);
  
}
