int ldr = A0;
int pir = 2;
int led1 = 9;
int led2 = 10;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int light = analogRead(ldr);
  int motion = digitalRead(pir);

  if (light < 500) {
    digitalWrite(led1, HIGH);

    if (motion == HIGH) {
      digitalWrite(led2, HIGH);
    } 
    else {
      digitalWrite(led2, LOW);
    }
  } 
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}