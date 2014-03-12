
void setup() {
  randomSeed(analogRead(0));
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
}

void loop() {
  
  for (int i=16; i <= 19; i++){
    if ( random(0,100) >= 50) {
       digitalWrite(i, HIGH);      
    } else {
       digitalWrite(i, LOW);
    }
  }
  delay(random(5000, 10000));
}

