#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>

#define CLK 3
#define DAT 4
#define MAX 24
#define ADD 1


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress  localip(192, 168, 88, 177);
IPAddress remoteip(192, 168, 88, 6);

unsigned int remotePort = 8888;
unsigned int localPort  = 8888;
char  Reply[] = "12345678901234567890";
unsigned long weight = 0;

EthernetUDP Udp;

void setup() {
  //void begin(const uint8_t* mac, IPAddress ip, IPAddress dns, IPAddress gateway, IPAddress subnet);
  Ethernet.begin(mac, localip);
  pinMode(CLK, OUTPUT);
  digitalWrite(CLK, LOW);
  pinMode(DAT, INPUT);
  Serial.begin(115200);
  Serial.print("Ready\n");
}

void loop() {
  if (digitalRead(DAT) == 0) {
    weight = 0;
    for (int i=0; i < MAX; i++){
      digitalWrite(CLK, HIGH);
      weight = weight << 1;
      digitalWrite(CLK, LOW);
      if (digitalRead(DAT) == 1) {
        weight = weight + 1;
        }
      }
    for (int i=0;i<ADD;i++) {
      digitalWrite(CLK, HIGH);
      digitalWrite(CLK, LOW);
      }

  
    sprintf(Reply, "%010lu%010lu", millis(), weight);
    Udp.beginPacket(remoteip, remotePort);
    Udp.write(Reply);
    Udp.endPacket();
  }
}

