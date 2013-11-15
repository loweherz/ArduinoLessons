/* Simple Read
**
Read data from the serial port and change the color of a rectangle
* when a switch connected to a Wiring or Arduino board is pressed and
released.
* This example works with the Wiring / Arduino program that follows below.
*/

import processing.serial.*;
String portname = "COM8";
Serial port; // Create object from Serial class
int val=100; // Data received from the serial port, with an initial value

void setup(){
  size(400, 400);
  colorMode(HSB, 255);
  ellipseMode(CENTER); // draw from center out
  noStroke();
  frameRate(30);
  smooth();
  // Open the port the board is connected to
  port = new Serial(this, portname, 19200);
}

void draw(){
  if (port.available() > 0) { // If data is available,
    val = port.read(); // read it and store it in val
  } 
  background(99);
  // Draw the shape
  fill(val,255,255); // we're in HSB mode, so first value is color
  ellipse(width/2, height/2, 250,250);
}
