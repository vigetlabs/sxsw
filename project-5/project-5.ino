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

  int mappedValue = 0;

  if (brightnessMin != brightnessMax) {
    int mappedValue = map(brightness, brightnessMin, brightnessMax, 0, 255);
  }

  analogWrite(ledPin, mappedValue);

  if (buttonState == HIGH) {
    Particle.publish("sxsw-team-42", String(mappedValue));
    delay(1000);
  }

  analogWrite(ledPin, teamBrightness);
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
