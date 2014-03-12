
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void setled(char led, boolean state) {
  switch (led) {
    case 'a':
      digitalWrite(2, state);
      break;
    case 'b':
      digitalWrite(3, state);
      break;
    case 'c':
      digitalWrite(4, state);
      break;
    case 'd':
      digitalWrite(5, state);
      break;
    case 'e':
      digitalWrite(6, state);
      break;
    case 'f':
      digitalWrite(7, state);
      break;
    case 'g':
      digitalWrite(8, state);
      break;
    case 'p':
      digitalWrite(9, state);
      break;
    default:
      return;
  }
}

void digit(int digit) {
  switch (digit) {
    case 0:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', HIGH);
      setled('f', HIGH);
      setled('g', LOW);
      break;
    case 1:
      setled('a', LOW);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', LOW);
      setled('e', LOW);
      setled('f', LOW);
      setled('g', LOW);
      break;
    case 2:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', LOW);
      setled('d', HIGH);
      setled('e', HIGH);
      setled('f', LOW);
      setled('g', HIGH);
      break;
    case 3:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', LOW);
      setled('f', LOW);
      setled('g', HIGH);
      break;
    case 4:
      setled('a', LOW);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', LOW);
      setled('e', LOW);
      setled('f', HIGH);
      setled('g', HIGH);
      break;
    case 5:
      setled('a', HIGH);
      setled('b', LOW);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', LOW);
      setled('f', HIGH);
      setled('g', HIGH);
      break;
    case 6:
      setled('a', HIGH);
      setled('b', LOW);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', HIGH);
      setled('f', HIGH);
      setled('g', HIGH);
      break;
    case 7:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', LOW);
      setled('e', LOW);
      setled('f', LOW);
      setled('g', LOW);
      break;
    case 8:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', HIGH);
      setled('f', HIGH);
      setled('g', HIGH);
      break;
    case 9:
      setled('a', HIGH);
      setled('b', HIGH);
      setled('c', HIGH);
      setled('d', HIGH);
      setled('e', LOW);
      setled('f', HIGH);
      setled('g', HIGH);
      break;
 default:
      return;
}

}

void loop() {
  for (int i=0; i <= 9; i++){
    digit(i);
    delay(500);
  }
}

