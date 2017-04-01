#define CLK 2
#define DAT 3
#define MAX 24
#define ADD 1

unsigned long weight = 0;

void setup() {
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
          Serial.print(1);
        } else {
          Serial.print(0);
        }
      }
    for (int i=0;i<ADD;i++) {
      digitalWrite(CLK, HIGH);
      digitalWrite(CLK, LOW);
      }
    Serial.print(" - ");
    if (weight > 16000000) {
      weight = 0;
    } else {
      weight = weight /22558;
    }
    Serial.println(weight);
    delay(100);
  }
}
