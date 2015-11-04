## Project 1 - Making an Internet Button

In this project we'll use the Particle Photon and a button to trigger internet actions.

#### Key Concepts/Components
- **void setup():** all Arduino code must have a setup function defined. This gets run once when the system boots up.

- **void loop():** all Arduino code must also have a loop function defined. After setup is run, this runs as in an infinite loop.

- **pinMode:** tells the device that we'll be using a pin to either gather `INPUT` or provide `OUTPUT`.

- **digitalRead:** takes a digital (binary) reading from the specified pin. This will return `HIGH` or `LOW`.

- **Particle.publish:** Publishes an event to the internet within the Particle ecosystem. This is what we'll use with IFTTT to make the magic happen.

- **delay:** pause the program for the specified number of milliseconds, useful here so the button press is only registered once instead of as many times as the program loop cycles through while the button is pressed.


#### Component Layout

![fritzing-diagram](https://s3.amazonaws.com/vigesharing-is-vigecaring/jsinichko/0904g5bve.jpg)
