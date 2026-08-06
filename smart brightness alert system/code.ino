const int ldrPin = A0;
const int button = 2;
const int led = 8;
const int buzzer = 9;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int light = analogRead(ldrPin);

  if (light < 300 || digitalRead(button) == LOW) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}