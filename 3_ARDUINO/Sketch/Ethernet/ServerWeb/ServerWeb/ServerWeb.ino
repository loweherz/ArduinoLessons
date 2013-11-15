#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,2, 130 };
File htmlFile;
EthernetServer server = EthernetServer(80);
 
void setup()
{
  Ethernet.begin(mac, ip);
  server.begin();
  if (!SD.begin(4)) { return; }
}
 
void loop()
{
  EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
 
          htmlFile = SD.open("index.htm");
          if (htmlFile) {
            while (htmlFile.available()) {
                client.print(htmlFile.read());
            }
            // close the file:
            htmlFile.close();
          }
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
  }
}
