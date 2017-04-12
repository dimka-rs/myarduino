#include <SPI.h>         // needed for Arduino versions later than 0018
#include <UIPEthernet.h>

#define CLK 3
#define DAT 4
#define DATABITS 24
#define CONFBITS 3 //1: A*128, 2: B*32, 3: A*64


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress  localip(192, 168, 88, 177);
IPAddress remoteip(192, 168, 88, 6);

unsigned int remotePort = 8888;
unsigned int localPort  = 8888;
char  Reply[] = "1234567890s1234567890";
signed long weight = 0;
char sign = '+';

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
    sign = '+';
    for (int i=0; i < DATABITS; i++){
      digitalWrite(CLK, HIGH);
      weight = weight << 1;
      digitalWrite(CLK, LOW);
      if (digitalRead(DAT) == 1) {
        if (i==0) {
          sign='-';
        } else {
          weight = weight + 1;
          }
        }
      }
    for (int i=0;i<CONFBITS;i++) {
      digitalWrite(CLK, HIGH);
      digitalWrite(CLK, LOW);
      }

  
    sprintf(Reply, "%010lu%c%010lu", millis(), sign, weight);
    Udp.beginPacket(remoteip, remotePort);
    Udp.write(Reply);
    Udp.endPacket();
  }
}

