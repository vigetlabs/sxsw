#define PIXEL_COUNT 1
#define PIXEL_PIN   D3
#define PIXEL_TYPE  WS2812B

String lightMode = "red";
Adafruit_NeoPixel led = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  Particle.function("adjustLight", adjustLight);
}

int adjustLight(String command) {
  lightMode = command;
  return 1;
}

void loop() {
  if (lightMode == "red") {
    led.setPixelColor(0, 255, 0, 0);
    led.show();
  } else if (lightMode == "green") {
    led.setPixelColor(0, 0, 255, 0);
    led.show();
  } else if (lightMode == "blue") {
    led.setPixelColor(0, 0, 0, 255);
    led.show();
  } else if (lightMode == "rainbow") {
    showTheRainbow();
  } else {
    led.setPixelColor(0, 0, 0, 0);
    led.show();
  }
}

void showTheRainbow() {
  // start with Red on, and make Green grow brighter
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, 255, i, 0);
    led.show();
  }
  // Green is now on, make Red shrink
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, 255 - i, 255, 0);
    led.show();
  }
  // Green is now on, make Blue grow
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, 0, 255, i);
    led.show();
  }
  // Blue is now on, make Green shrink
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, 0, 255 - i, 255);
    led.show();
  }
  // Blue is now on, make Red grow
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, i, 255, 0);
    led.show();
  }
  // Red is now on, make Blue shrink
  for (int i = 0; i < 255; i += 10) {
    led.setPixelColor(0, 255, 0, 255 - i);
    led.show();
  }
}
