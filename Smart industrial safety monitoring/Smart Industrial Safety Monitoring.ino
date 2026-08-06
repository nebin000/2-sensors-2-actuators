// Smart Industrial Safety Monitoring System

const int gasPin = A0;
const int tempPin = A1;
const int ldrPin = A2;
const int pirPin = 2;

const int greenLED = 6;
const int redLED = 7;
const int buzzer = 8;
const int fan = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fan, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Read sensors
  int gasValue = analogRead(gasPin);
  int ldrValue = analogRead(ldrPin);
  int pirValue = digitalRead(pirPin);

  // Read temperature from TMP36
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // Print values
  Serial.print("Gas: ");
  Serial.print(gasValue);

  Serial.print("  Temp: ");
  Serial.print(temperature);

  Serial.print(" C  Light: ");
  Serial.print(ldrValue);

  Serial.print("  Motion: ");
  Serial.println(pirValue);

  // Reset outputs
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(fan, LOW);

  // Low light -> Green LED ON
  if (ldrValue < 500) {
    digitalWrite(greenLED, HIGH);
  }

  // High temperature -> Fan ON
  if (temperature > 35) {
    digitalWrite(fan, HIGH);
  }

  // Gas leak -> Alarm + Fan
  if (gasValue > 400) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(fan, HIGH);
  }

  // Motion detection
  if (pirValue == HIGH) {
    Serial.println("Worker Present");
  } else {
    Serial.println("No Worker");
  }

  delay(500);
}