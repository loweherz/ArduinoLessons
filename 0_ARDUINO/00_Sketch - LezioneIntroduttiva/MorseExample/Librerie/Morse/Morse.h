#ifndef Morse_h
#define Morse_h
#include <WProgram.h>
 
class Morse
{
 public:
     Morse(int pin);
     void punto();
     void linea();
 private:
     int _pin;
};
#endif

