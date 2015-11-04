## Project 1 - Making an Internet Button

In this project we'll use the Particle Photon and a button to trigger internet actions.

#### Key Concepts/Components
- **pinMode:** tells the device that we'll be using a pin to either gather `INPUT` or provide `OUTPUT`.
- **digitalRead:** takes a digital (binary) reading from the specified pin. This will return `HIGH` or `LOW`.
- **Particle.publish:** Publishes an event to the internet within the Particle ecosystem. This is what we'll use with IFTTT to make the magic happen.
