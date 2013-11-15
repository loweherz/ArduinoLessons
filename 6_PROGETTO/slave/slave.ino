//----------------------------------
//RS 485
//SLAVES
//----------------------------------


byte  data[12];
byte  address;
byte  function;
byte  function_code;
unsigned int data_received;
byte  byte_receive;
byte  state=0;
byte  cont1=1;
byte  trace_OK=0;
unsigned int checksum;
unsigned int checksum_trace;

#define  pinCONTROL    02
#define  myaddress     02
  

void setup() {

   pinMode(13,OUTPUT);
   pinMode(pinCONTROL,OUTPUT);
   digitalWrite(2,LOW);
   Serial.begin(9600);
   Serial.println("--START--");

}

void loop()
{

   while (Serial.available() > 0){
    
     byte_receive=Serial.read();
     if (byte_receive==00){
       //Serial.println("ho ricevuto il byte Start");
       state=1;
       checksum_trace=0;
       checksum=0;
       trace_OK=0;
       address=0;
       data_received=0;
       cont1=1;
     }else if (state==1 && cont1<=12){
       data[cont1-1]=byte_receive;
       checksum=checksum+byte_receive;
       cont1=cont1+1;
     }else if (state==1 && cont1==13){
       checksum_trace=byte_receive<<8;
       cont1=cont1+1;
       //Serial.print("primo Byte Checksum");      
       //Serial.print(checksum_trace,HEX);
     }else if (state==1 && cont1==14){
       checksum_trace=checksum_trace+byte_receive;
       cont1=cont1+1;
       state=0;
       //Serial.println(byte_receive,HEX);
       //Serial.println("ricevuto trama");
       //Serial.print("Checksum Trace= ");
       //Serial.println(checksum_trace,HEX);
       //Serial.print("Checksum= ");
       //Serial.println(checksum,HEX);
       //Serial.println(checksum,DEC);
       //Serial.println("Trama= ");
       //Serial.print(data[0]);
       //Serial.print(data[1]);
       //Serial.print(data[2]);
       //Serial.print(data[3]);
       //Serial.print(data[4]);
       //Serial.print(data[5]);
       //Serial.print(data[6]);
       //Serial.print(data[7]);
       //Serial.print(data[8]);
       //Serial.print(data[9]);
       //Serial.print(data[10]);
       //Serial.println(data[11]);      

       if (checksum_trace==checksum){
         trace_OK=1;
        
         address=(hex2num(data[0])<<4)+(hex2num(data[1]));
         function=data[3];
         function_code=(hex2num(data[4])<<4)+(hex2num(data[5]));
         data_received=(hex2num(data[7])<<12)+(hex2num(data[8])<<8)+(hex2num(data[9])<<4)+(hex2num(data[10]));
        
         //Serial.println("TRAMA CORRETTA");
         //Serial.println(address,DEC);
         //Serial.println(data_received);
         if (address==myaddress){
           if ((function=='D') && (function_code==0) && data[2]==5){
             if (data_received==1){
               digitalWrite(13,HIGH);
               //Serial.println(data_received,DEC);
               sendACK(data[0],data[1],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10]);
             }else if (data_received==0){
               digitalWrite(13,LOW);
               sendACK(data[0],data[1],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10]);
             }
           }
         }
       }else{
         //Serial.println("TRAMA INCORRETTA");  
         sendNAK(data[0],data[1],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10]);
       }
     }

  }
  
}


//------------------------
//FUNZIONI
//------------------------

byte receiveMSG(){

  byte  byte_receive;
  byte  state=0;
  byte  cont1=1;
  byte  trace_OK=0;

  unsigned int checksum;
  unsigned int checksum_trace;
  

  
  
  while (Serial.available() > 0){
    
     byte_receive=Serial.read();
     if (byte_receive==00){
       state=1;
       checksum_trace=0;
       checksum=0;
       trace_OK=0;
       cont1=1;
     }else if (state==1 && cont1<=12){
       data[cont1-1]=byte_receive;
       checksum=checksum+byte_receive;
       cont1=cont1+1;
     }else if (state==1 && cont1==13){
       checksum_trace=byte_receive<<8;
       cont1=cont1+1;
     }else if (state==1 && cont1==14){
       checksum_trace=checksum_trace+byte_receive;
       cont1=cont1+1;
       state=0;
       if (checksum_trace==checksum){
           trace_OK=1;
       }else{
         trace_OK=0;
       }
       break;
     }
  }
  return trace_OK;

}



void sendMSG(byte address1,byte address2,byte data_type,byte code1,byte code2,byte Sign,byte data1,byte data2,byte data3,byte data4){
  
  unsigned int checksum_ACK;
  checksum_ACK=address1+address2+5+data_type+code1+code2+Sign+data1+data2+data3+data4+3;
  
  UCSR0A=UCSR0A |(1 << TXC0);
  
  digitalWrite(pinCONTROL,HIGH);
  delay(1);

  Serial.print(0,BYTE);
  Serial.print(address1,BYTE);
  Serial.print(address2,BYTE);
  Serial.print(5,BYTE);
  Serial.print(data_type,BYTE);
  Serial.print(code1,BYTE);
  Serial.print(code2,BYTE);
  Serial.print(Sign,BYTE);
  Serial.print(data1,BYTE);
  Serial.print(data2,BYTE);
  Serial.print(data3,BYTE);
  Serial.print(data4,BYTE);  
  Serial.print(3,BYTE);
  Serial.print(((checksum_ACK>>8)&255),BYTE);
  Serial.print(((checksum_ACK)& 255),BYTE);
  while (!(UCSR0A & (1 << TXC0)));
  digitalWrite(pinCONTROL,LOW);

  
  
}



void sendACK(byte address1,byte address2,byte data_type,byte code1,byte code2,byte Sign,byte data1,byte data2,byte data3,byte data4){
  
  unsigned int checksum_ACK;
  checksum_ACK=address1+address2+6+data_type+code1+code2+Sign+data1+data2+data3+data4+3;
  
  UCSR0A=UCSR0A |(1 << TXC0);
  
  digitalWrite(pinCONTROL,HIGH);
  delay(1);

  Serial.print(0,BYTE);
  Serial.print(address1,BYTE);
  Serial.print(address2,BYTE);
  Serial.print(6,BYTE);
  Serial.print(data_type,BYTE);
  Serial.print(code1,BYTE);
  Serial.print(code2,BYTE);
  Serial.print(Sign,BYTE);
  Serial.print(data1,BYTE);
  Serial.print(data2,BYTE);
  Serial.print(data3,BYTE);
  Serial.print(data4,BYTE);  
  Serial.print(3,BYTE);
  Serial.print(((checksum_ACK>>8)&255),BYTE);
  Serial.print(((checksum_ACK)&255),BYTE);
  while (!(UCSR0A & (1 << TXC0)));
  digitalWrite(pinCONTROL,LOW);
  
  
}

void sendNAK(byte address1,byte address2,byte data_type,byte code1,byte code2,byte Sign,byte data1,byte data2,byte data3,byte data4){
  
  unsigned int checksum_ACK;
  checksum_ACK=address1+address2+6+data_type+code1+code2+Sign+data1+data2+data3+data4+3;
  
  UCSR0A=UCSR0A |(1 << TXC0);
  
  digitalWrite(pinCONTROL,HIGH);
  delay(1);

  Serial.print(0,BYTE);
  Serial.print(address1,BYTE);
  Serial.print(address2,BYTE);
  Serial.print(15,BYTE);
  Serial.print(data_type,BYTE);
  Serial.print(code1,BYTE);
  Serial.print(code2,BYTE);
  Serial.print(Sign,BYTE);
  Serial.print(data1,BYTE);
  Serial.print(data2,BYTE);
  Serial.print(data3,BYTE);
  Serial.print(data4,BYTE);  
  Serial.print(3,BYTE);
  Serial.print(((checksum_ACK>>8)&255),BYTE);
  Serial.print(((checksum_ACK)&255),BYTE);
  while (!(UCSR0A & (1 << TXC0)));
  digitalWrite(pinCONTROL,LOW);
  
  
}



byte hex2num(byte x){

  byte result;
  
  if (x>=48 && x<=57){
    result=x-48;  
  }else if (x>=65 && x<=70){
    switch(x){
      case 65:
        result=10;
        break;
      case 66:
        result=11;
        break;
      case 67:
        result=12;
        break;
      case 68:
        result=13;
        break;
      case 69:
        result=14;
        break;
      case 70:
        result=15;
        break;    
    }  
  }
  return result;  
}