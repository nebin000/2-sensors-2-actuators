int ldr = A0;
int pir = 2;
int led = 13;
int motor = 9;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  int light = analogRead(ldr);
  int motion = digitalRead(pir);

  if (light < 500 && motion == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if (motion == HIGH) {
    analogWrite(motor, 200);
  } else {
    analogWrite(motor, 0);
  }
}