int buttonPin = D0;

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Particle.publish("buttonPressed");
    delay(2000);
  }
}
