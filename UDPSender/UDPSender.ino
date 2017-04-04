#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress  localip(192, 168, 1, 177);
IPAddress remoteip(192, 168, 1, 10);

unsigned int remotePort = 8888;
unsigned int localPort  = 8888;
char  Reply[] = "usefull payload\n";

EthernetUDP Udp;

void setup() {
  //void begin(const uint8_t* mac, IPAddress ip, IPAddress dns, IPAddress gateway, IPAddress subnet);
  Ethernet.begin(mac, localip);
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
    sprintf(Reply, "%010lu", millis());
    Udp.beginPacket(remoteip, remotePort);
    Udp.write(Reply);
    Udp.endPacket();
}

