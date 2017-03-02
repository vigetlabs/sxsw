int buttonPin = D0;
int ledPin    = D3;
int sensorPin = A0;

int brightnessMax = 0;
int brightnessMin = 4096;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int brightness = analogRead(sensorPin);
  adjustMinMax(brightness);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    analogWrite(ledPin, mapValue(brightness));
  }
}

void adjustMinMax(int brightness) {
  if (brightness > brightnessMax) {
    brightnessMax = brightness;
  }

  if (brightness < brightnessMin) {
    brightnessMin = brightness;
  }
}

int mapValue(int brightness) {
  if (brightnessMax > brightnessMin) {
    // maps the brightness from the measured min-max to the 0-255 LED scale
    return ((brightness - brightnessMin) * 255) / (brightnessMax - brightnessMin);
  } else {
    return brightness;
  }
}
