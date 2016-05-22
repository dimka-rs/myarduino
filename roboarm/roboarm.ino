//Robo ARM
int x0in = A0;
int x1in = A1;
int x2in = A2;
int x3in = A3;
int x0out = 10;
int x1out = 11;
int x2out = 12;
int x3out = 13;
int x0 = 500;
int x1 = 500;
int x2 = 500;
int x3 = 500;
int x0p = 130;
int x1p = 130;
int x2p = 130;
int x3p = 130;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Start\n");
  pinMode(x0in, INPUT);
  pinMode(x1in, INPUT);
  pinMode(x2in, INPUT);
  pinMode(x3in, INPUT);
  pinMode(x0out, OUTPUT);
  pinMode(x1out, OUTPUT);
  pinMode(x2out, OUTPUT);
  pinMode(x3out, OUTPUT);
  Serial.print("Setup done\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  x0 = analogRead(x0in);
  x1 = analogRead(x1in);
  x2 = analogRead(x2in);
  x3 = analogRead(x3in);
  if (x0 > 550 and x0p < 245) {x0p += 10;}
  if (x0 < 450 and x0p > 0) {x0p -= 10;}
  if (x1 > 550 and x1p < 245) {x1p += 10;}
  if (x1 < 450 and x1p > 0) {x1p -= 10;}
  if (x2 > 550 and x2p < 245) {x2p += 10;}
  if (x2 < 450 and x2p > 0) {x2p -= 10;}
  if (x3 > 550 and x3p < 245) {x3p += 10;}
  if (x3 < 450 and x3p > 0) {x3p -= 10;}
  analogWrite(x0out, x0p);
  analogWrite(x1out, x1p);
  analogWrite(x2out, x2p);
  analogWrite(x3out, x3p);
  Serial.print(x0p); Serial.print("\t");
  Serial.print(x1p); Serial.print("\t");
  Serial.print(x2p); Serial.print("\t");
  Serial.print(x3p); Serial.print("\n");
  delay(100);
}
