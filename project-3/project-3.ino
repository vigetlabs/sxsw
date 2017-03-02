int buttonPin = D0;
int ledPin    = D3;

int brightness = 50;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Particle.function("brightness", setBrightness);
}

int setBrightness(String command) {
  brightness = atoi(command);

  return brightness;
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    analogWrite(ledPin, brightness);
  }
}
