int ROW_LOW = 22;
int ROW_HIGH = 29;
int COL_LOW = 4;
int COL_HIGH = 7;

void setup() {                
  for (int i=ROW_LOW; i<=ROW_HIGH; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

}

void litmeup(int pin) {
  digitalWrite(pin, LOW);
  delay(100);
  digitalWrite(pin, HIGH);
}

void flash_row() {
  for (int i=ROW_LOW; i<=ROW_HIGH; i++) {
    litmeup(i);
  } 
}

void all_down() {
  for (int i=COL_LOW; i<=COL_HIGH; i++) {
    digitalWrite(i, LOW);
  }

}
// the loop routine runs over and over again forever:
void loop() {
  for (int j=COL_LOW; j<=COL_HIGH; j++){
    all_down();
    digitalWrite(j, HIGH);
    flash_row();
  }
}
