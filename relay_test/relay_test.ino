
void setup() {
  randomSeed(analogRead(0));
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  for (int i=4; i <= 7; i++){
    digitalWrite(i, HIGH);
    delay(random(100, 1000));
    digitalWrite(i, LOW);
  }
}

