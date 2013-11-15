import processing.serial.*;

Serial myPort;  // Create object from Serial class

int state = 31;

int fire = 1;
int right = 1;
int up = 1;
int left = 1;
int down = 1;

int x = 275;
int y = 275;
int c = 0;

void setup(){
  size(600, 600);
  myPort = new Serial(this, "COM3", 9600);
}

void draw() {
  if(myPort.available() > 0) {
    state = myPort.read();
    println(state);
    println(binary(state));
    
    fire = state & 1;
    right = (state & 2) >> 1;
    up = (state & 4) >> 2;
    left = (state & 8) >> 3;
    down = (state & 16) >> 4;
    
    print(fire);
    print(right);
    print(up);
    print(left);
    println(down);
  }
    
  //c is the fill of the rectangle. If the fire button is pressed, then fills it, otherwise no	
  c = (fire == 0) ? 250 : 0;
  
  
  //set the move
  if(right == 0 && left == 1) {
    x = x + 2;
  }
  if(up == 0 && down == 1) { 
    y = y - 2; 
  }
  if(left == 0 && right == 1) {
    x = x - 2;
  }
  if(down == 0 && up == 1) {
    y = y + 2;
  }
  
  background(255, 255, 150);
  fill(c);
  rect(x, y, 50, 50);
}