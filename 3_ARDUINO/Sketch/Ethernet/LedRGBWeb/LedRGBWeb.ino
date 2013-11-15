/*
Per capire meglio le linee riguardanti le richieste HTTP e per non fare confusione in seguito 
immagina la stringa che il client spedisce al server (Arduino in questo caso), è di questo tipo:

GET 1.1 /?r=xxx&g=yyy&b=zzz&S=submit
012345678901234567890123456789012345

Ho aggiunto sotto la numerazione dei caratteri per comprendere meglio la questione delle posizoni, 
quando utilizzi il metodo indexOf(“?”) sulla stringa otterrai come risultato 9, 
la posizione del carattere cercato nella stringa, 
allo stesso modo per “r” otterrai 10, per “g” 16, per “b” 22 ed “S” 28.
*/

#include <SPI.h>
#include <Ethernet.h>
#define maxLength 25
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

String inString = String(maxLength);
int val;
int r = 0;
int g = 0;
int b = 0;
char colorBuff[4];
EthernetServer server = EthernetServer(80);
IPAddress ip(192, 168, 0, 200); 

int pinR = 3;
int pinG = 5;
int pinB = 6;
 
void setup(){
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
 
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
 
  Serial.begin(9600);
}

void loop(){
  int bufLength;
  Client client = server.available();
  if (client) {
    boolean current_line_is_blank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (inString.length() < maxLength) {
          //inString.append(c);
          inString += c;
        }
        if (c == '\n' && current_line_is_blank) {
          if (inString.indexOf("?") > -1) {
            int Pos_r = inString.indexOf("r");
            int Pos_g = inString.indexOf("g", Pos_r);
            int Pos_b = inString.indexOf("b", Pos_g);
            int End = inString.indexOf("S", Pos_b);
            if(End < 0){
              End =  inString.length() + 1;
            }

			//LEGGO IL VALORE DI R
            bufLength = ((Pos_g) - (Pos_r+2));
            if(bufLength > 4){  //dont overflow the buffer
              bufLength = 4;
            }
            inString.substring((Pos_r+2), (Pos_g-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
            r = atoi(colorBuff);
			
			//LEGGO IL VALORE DI G
            bufLength = ((Pos_b) - (Pos_g+2));
            if(bufLength > 4){  //dont overflow the buffer
              bufLength = 4;
            }
            inString.substring((Pos_g+2), (Pos_b-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
            g = atoi(colorBuff);
			
			//LEGGO IL VALORE DI B
            bufLength = ((End) - (Pos_b+2));
            if(bufLength > 4){  //dont overflow the buffer
              bufLength = 4;
            }
            inString.substring((Pos_b+2), (End-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
            b = atoi(colorBuff);
 
            analogWrite(pinR,r);
            analogWrite(pinG,g);
            analogWrite(pinB,b);
 
          }
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html><head>");
          client.println("<meta http-equiv='Content-Type' content='text/html; charset=iso-8859-1'><title>:: Arduino Server ::</title>");
          client.println("<style>");
          client.println("body { text-align: center; font-family: Arial, Helvetica, sans-serif; font-size:50px; font-weight: normal; } ");
          client.println("h1, input { font-size: 100%; text-align: center; } ");
          client.println(".dim { border: 1px solid #f0731c; width: 100%; text-align: center; } ");
          client.println(".pulsante { width: 60px; height: 60px; border: 1px solid #000; margin: 5px; } ");
          client.println("</style>");
          client.println("</head><body>");
 
          client.println("<div class='dim'><h1>RGB Arduino </h1>");
          client.print("<form method=get>");
 
          client.println("<table border=0 align=center>");
          client.println("<tr>");
          client.println("<td align=center><div class=pulsante style=\"background-color: #FF0000;\"><br>R</div></td>");
          client.println("<td align=center><div class=pulsante style=\"background-color: #00ff00;\"><br>G</div></td>");
          client.println("<td align=center><div class=pulsante style=\"background-color: #0000ff;\"><br>B</div></td>");
          client.println("</tr>");
          client.println("<tr>");
          client.println("<td align=center><input type=text size=3 name=r id=r value=\""); client.print(r); client.println("\"></td>");
          client.println("<td align=center><input type=text size=3 name=g id=g value=\""); client.print(g); client.println("\"></td>");
          client.println("<td align=center><input type=text size=3 name=b id=b value=\""); client.print(b); client.println("\"></td>");
          client.println("</tr>");
 
          client.println("</table>");
 
          client.println("<br><input name=\"S\" type=\"submit\" value=\"INVIA\">");
          client.println("</form>");
          client.println("</div>");
          client.println("</body></html>");
          break;
        }
        if (c == '\n') {
          current_line_is_blank = true;
        }
        else if (c != '\r') {
          current_line_is_blank = false;
        }
      }
    }
    delay(1);
    inString = "";
    client.stop();
  }
}