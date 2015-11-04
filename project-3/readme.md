## Project 3 - Communicating Devices

In this project, we'll use both ends of the Particle event system - publishing and subscribing - in order to build devices which talk to each other.

#### Requirements

This project includes using multiple devices, so you'll need to grab a partner or two. You'll also need to pull in the Neopixel library again like in Project 2.

You'll notice that the code subscribes and publishes to the `"duke-team-42"` event. Your group will need to change the number (or the entire string) to something unique so that you're only responding to each other's published events.

*Note 1: Your code will respond to your own published events if you've subscribed to the same event name that you're publishing to. If you'd like, publish and subscribe to different event names (as long as they inversely match up your partner's) so you only effect change on other devices.*

*Note 2: I'd suggest everyone in your group change the color in the line `Particle.publish("duke-team-42", "green");` so that it's easy to tell who's publishing events when.*

#### Key Concepts/Components

- **Particle.subscribe("name", function) :** Subscribe to Particle events. You must pass in the `"name"` of the event, and a `function` to run when the event is published.

#### Component Layout

![fritzing-diagram](https://s3.amazonaws.com/vigesharing-is-vigecaring/jsinichko/1804ytbai.jpg)
