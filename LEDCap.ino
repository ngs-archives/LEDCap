const int temt6000Pin = A5;
const int ledPins[] = {5, 6, 9, 10, 11, A2, A3, A4};
const int ledSize = sizeof(ledPins);
const int threshold = 40;
const int ledDelay = 100;
int ledCursor;

void setup() {
  ledCursor = 0;
  pinMode(temt6000Pin, INPUT);
  for(int i = 0; i < ledSize; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

boolean isDark() {
  int value = analogRead(temt6000Pin);
  return value < threshold;
}

void allOff() {
  for(int i = 0; i < ledSize; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  if(isDark()) {
    digitalWrite(ledPins[ledCursor], HIGH);
    delay(ledDelay);
  } else {
    allOff();
  }
  digitalWrite(ledPins[ledCursor], LOW);
  if(ledCursor++ == ledSize) {
    ledCursor = 0;
  }
}
