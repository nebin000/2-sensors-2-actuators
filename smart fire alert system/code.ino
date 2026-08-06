

const int tempPin = A0;
const int button = 2;
const int led = 8;
const int buzzer = 9;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  float temp = (analogRead(tempPin) * 5.0 / 1023 - 0.5) * 100;

  if (temp > 30 || digitalRead(button) == LOW) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}