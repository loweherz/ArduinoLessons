#include <servo.h>

Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;
Servo servoMotor4;
Servo servoMotor5;
Servo servoMotor6;
 
int grad = 0;
int gradMin=0;
int gradMax=180;
 
int servoPin1 = 3;
int servoPin2 = 5;
int servoPin3 = 6;
int servoPin4 = 8;
int servoPin5 = 9;
int servoPin6 = 10;
 
void setup() {
	servoMotor1.attach(servoPin1);
    servoMotor2.attach(servoPin2);
    servoMotor3.attach(servoPin3);
    servoMotor4.attach(servoPin4);
    servoMotor5.attach(servoPin5);
    servoMotor6.attach(servoPin6);
 
    Serial.begin(9600);
} 
 
void loop(){
    grad = Serial.read();
    Serial.println("Gradi: " + grad);
 
    if (grad < gradMin) { grad = gradMin; }
    if (grad > gradMax) { grad = gradMax; }
    int _grad = (gradMax - grad); //Sterzo le ruote di due angoli diversi
 
    servoMotor1.write( grad );
    servoMotor2.write( grad );
    servoMotor3.write( grad );
    servoMotor4.write( _grad );
    servoMotor5.write( _grad );
    servoMotor6.write( _grad );
    delay(15);
}