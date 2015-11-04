int buttonPin = D0;

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Particle.publish("buttonPressed");
    delay(5000);
  }
}
