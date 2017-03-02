int buttonPin = D0;
int ledPin    = D3;
int sensorPin = A0;

int brightnessMax  = 0;
int brightnessMin  = 4096;
int teamBrightness = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Particle.subscribe("sxsw-team-42", setTeamBrightness);
}

void setTeamBrightness(const char *event, const char *data) {
  teamBrightness = atoi(data);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int brightness = analogRead(sensorPin);
  adjustMinMax(brightness);
  int mappedValue = mapValue(brightness);

  if (buttonState == HIGH) {
    Particle.publish("sxsw-team-42", String(mappedValue));
    delay(1000);
  }

  analogWrite(ledPin, teamBrightness);
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
