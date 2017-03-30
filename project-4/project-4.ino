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
    if (brightnessMin != brightnessMax) {
      int mappedValue = map(brightness, brightnessMin, brightnessMax, 0, 255);
      analogWrite(ledPin, mappedValue);
    }
  }
}

// Keep track of lowest low reading and highest high reading
// Probably don't want to mess with this.
void adjustMinMax(int brightness) {
  if (brightness > brightnessMax) {
    brightnessMax = brightness;
  }

  if (brightness < brightnessMin) {
    brightnessMin = brightness;
  }
}
