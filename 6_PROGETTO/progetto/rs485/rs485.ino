#include <SoftwareSerial.h>

#define pinTxRx 4                    //PIN DI CONTROLLO

#define TX 1            //MACRO DI DEFINIZIONE RX E TX
#define RX 0

#define pinTx 3                      //PIN DI TRASMISSIONE
#define pinRx 2                      //PIN DI RICEZIONE

//DEFINISCO LA SERIALE PER INTERFACCIARMI CON IL BUS RS485
SoftwareSerial rs485(pinRx, pinTx);  

//BUFFER DI RICEZIONE
String bufferRx;

void setup(){
  Serial.begin(9600);
  rs485.begin(9600);
  
  //DEFINISICO IL PIN DI CONTROLLO COME OUTPUT E LO METTO IN RICEZIONE
  pinMode(pinTxRx,OUTPUT);
  digitalWrite(pinTxRx, RX);
}

void loop(){ //POLLING D'ASCOLTO

  //MASTER MANDA
  if(Serial.available()>0){
    char A = Serial.read();
    digitalWrite(pinTxRx, TX); //MI METTO IN TRASMISSIONE
    delay(10);                 //ASPETTO 10ms PRIMA DI INVIARE
    rs485.print(A);
    digitalWrite(pinTxRx, RX); //RITORNO IN RICEZIONE
  }
  
  //SLAVE RICEVE
  if(rs485.available()>0){    
    char B = rs485.read();
    Serial.println(B); //SE HO QUALCOSA NEL BUFFER LO SALVO
  }

  /*if(bufferRx.length()>0){    //LEGGO IL BUFFER
    Serial.println(bufferRx);
    bufferRx = "";            //SVUOTO IL BUFFER DI RICEZIONE
  }*/ 
}  
